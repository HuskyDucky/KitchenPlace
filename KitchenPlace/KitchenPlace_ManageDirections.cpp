/**
    File    : KitchenPlace_ManageDirections.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.30            Version: 20190407.2

    Find the best places to install the kitchen on room nearest to all employees

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software developed to SQLLink internal use only.
**/
#include "KitchenPlace_ManageDirections.h"

Directions::Directions(const Matrix& tMap,
                       uint32_t lin,
                       uint32_t col) :
                                       dMapLinSize(tMap.size()),
                                       dMapColSize(tMap[0].size()),
                                       dMap(this->dMapLinSize, vector<uint8_t>(this->dMapColSize, 0)) {

    if (lin != LCLimit && col != LCLimit)
        this->Visited.emplace(lin, col);

    for (lin = 0; lin < this->dMapLinSize; ++lin)
        for (col = 0; col < this->dMapColSize; ++col)
            if (tMap[lin][col] == WALL)                                   //Build the walls
                dMap[lin][col] = wall;
            else if (this->Visited.empty())
                     this->Visited.emplace(lin, col);

    if (Visited.empty()) {
        cerr << "\n\nNo start place was found\n" << endl;
        abort();
    }

    this->UpdateLinCol();
    this->SetPossibleDirections4CurrPosition();
}

LinCol Directions::CurrPosition() const {
       return LinCol(this->Lin, this->Col) ;
}

void Directions::SetPossibleDirections4CurrPosition() {
     if (this->HasNoWay_Up())
        this->dMap[this->Lin][this->Col] |= Turn::UP;

     if (this->HasNoWay_Lf())
        this->dMap[this->Lin][this->Col] |= Turn::LF;

     if (this->HasNoWay_Dw())
        this->dMap[this->Lin][this->Col] |= Turn::DW;

     if (this->HasNoWay_Rt())
        this->dMap[this->Lin][this->Col] |= Turn::RT;
}

bool Directions::HasNoWay_Up() const { return this->Lin == 0 || this->dMap[this->Lin - 1][this->Col] == wall; }
bool Directions::HasNoWay_Lf() const { return this->Col == 0 || this->dMap[this->Lin][this->Col - 1] == wall; }
bool Directions::HasNoWay_Dw() const { return this->Lin + 1 == this->dMapLinSize || this->dMap[this->Lin + 1][this->Col] == wall; }
bool Directions::HasNoWay_Rt() const { return this->Col + 1 == this->dMapColSize || this->dMap[this->Lin][this->Col + 1] == wall; }

inline void Directions::UpdateLinCol() {
       this->Lin = Visited.top().first;
       this->Col = Visited.top().second;
}

LinCol Directions::NextStep() {
     if (Visited.empty()) return LinCol(LCLimit, LCLimit);

     while (dMap[this->Lin][this->Col] == Turn::NW) {
           this->Visited.pop();
           if (this->Visited.empty())
              return LinCol(LCLimit, LCLimit);

           this->UpdateLinCol();
     }

     if (~dMap[this->Lin][this->Col] &  Turn::RT) {
          dMap[this->Lin][this->Col] |= Turn::RT;
          dMap[this->Lin][++this->Col] |= Turn::LF;

     } else if (~dMap[this->Lin][this->Col] &  Turn::DW) {
                 dMap[this->Lin][this->Col] |= Turn::DW;
                 dMap[++this->Lin][this->Col] |= Turn::UP;

     } else if (~dMap[this->Lin][this->Col] &  Turn::UP) {
                 dMap[this->Lin][this->Col] |= Turn::UP;
                 dMap[--this->Lin][this->Col] |= Turn::DW;

     } else if (~dMap[this->Lin][this->Col] &  Turn::LF) {
                 dMap[this->Lin][this->Col] |= Turn::LF;
                 dMap[this->Lin][--this->Col] |= Turn::RT;
     }

     if (this->Lin != Visited.top().first || this->Col != Visited.top().second) {
         this->Visited.emplace(this->Lin, this->Col);
         this->SetPossibleDirections4CurrPosition();
     }

     return this->Visited.top();
}

bool Directions::HasUnreachablePlace() {

     while (this->NextStep().first != LCLimit);

     for (uint32_t lin = 0; lin < this->dMapLinSize; ++lin)
         for (uint32_t col = 0; col < this->dMapColSize; ++col)
             if (dMap[lin][col] == 0)
                return true;

     return false;
}
