/**
    File    : KitchenPlace_ManageDirections.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.30            Version: 20190407.3

    Find the best places to install the kitchen on room nearest to all employees

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "KitchenPlace_ManageDirections.h"

Directions::Directions(const Matrix& tMap,
                       LCType lin,
                       LCType col) :
                                    dMapLinSize(tMap.size()),
                                    dMapColSize(tMap[0].size()),
                                    dMap(this->dMapLinSize, vector<uint8_t>(this->dMapColSize, 0)) {

    if (lin != LCLimit && col != LCLimit)
        this->Visited.emplace(lin, col);

    for (lin = 0; lin < this->dMapLinSize; ++lin)
        for (col = 0; col < this->dMapColSize; ++col)
            if (tMap[lin][col] == WALL)                                   //Build the walls
                this->dMap[lin][col] = wall;
            else if (this->Visited.empty())
                     this->Visited.emplace(lin, col);

    if (this->Visited.empty()) {
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
       this->Lin = this->Visited.top().first;
       this->Col = this->Visited.top().second;
}

LinCol Directions::NextStep() {
       if (this->Visited.empty()) return LinCol(LCLimit, LCLimit);

       while (this->dMap[this->Lin][this->Col] == Turn::NW) {
             this->Visited.pop();
             if (this->Visited.empty())
                return LinCol(LCLimit, LCLimit);

             this->UpdateLinCol();
       }

       if (~this->dMap[this->Lin][this->Col] &  Turn::RT) {
            this->dMap[this->Lin][this->Col] |= Turn::RT;
            this->dMap[this->Lin][++this->Col] |= Turn::LF;

       } else if (~this->dMap[this->Lin][this->Col] &  Turn::DW) {
                   this->dMap[this->Lin][this->Col] |= Turn::DW;
                   this->dMap[++this->Lin][this->Col] |= Turn::UP;

       } else if (~this->dMap[this->Lin][this->Col] &  Turn::UP) {
                   this->dMap[this->Lin][this->Col] |= Turn::UP;
                   this->dMap[--this->Lin][this->Col] |= Turn::DW;

       } else if (~this->dMap[this->Lin][this->Col] &  Turn::LF) {
                   this->dMap[this->Lin][this->Col] |= Turn::LF;
                   this->dMap[this->Lin][--this->Col] |= Turn::RT;
       }

       if (this->Lin != this->Visited.top().first || this->Col != this->Visited.top().second) {
           this->Visited.emplace(this->Lin, this->Col);
           this->SetPossibleDirections4CurrPosition();
       }

       return this->Visited.top();
}

bool Directions::HasUnreachablePlace() {
     while (this->NextStep().first != LCLimit);

     for (LCType lin = 0; lin < this->dMapLinSize; ++lin)
         for (LCType col = 0; col < this->dMapColSize; ++col)
             if (dMap[lin][col] == 0)
                return true;

     return false;
}
