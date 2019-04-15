/**
    File    : KitchenPlace_FindShortWays.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.28            Version: 20190415.1

    Find the best places to install the kitchen on room nearest to all this->Employees

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software developed to SQLLink internal use only.
**/
#include "KitchenPlace_FindShortWays.h"

ShortWayFinder::ShortWayFinder(const LinCol& EmpLC,
                               Matrix& tMapLC) :
                                                Emp(EmpLC),
                                                tMap(tMapLC),
                                                D(tMapLC, EmpLC.first, EmpLC.second) {}

void ShortWayFinder::SetDistancesOnDMap() {
     LinCol lincol = this->D.CurrPosition();

     while (lincol.first != LCLimit) {
           bool toReview = false;

           for (uint8_t Direction = 1; Direction <= Turn::LF; Direction <<= 1) {
               LinCol N_S = this->SetNextStep(Direction,  lincol);

             if (N_S != this->Emp && this->tMap[N_S.first][N_S.second] != WALL) {
                if (this->tMap[N_S.first][N_S.second] == 0)
                    this->tMap[N_S.first][N_S.second] = this->tMap[lincol.first][lincol.second] + 1;
                else if (this->tMap[N_S.first][N_S.second] + 1 < this->tMap[lincol.first][lincol.second]) {
                         this->tMap[lincol.first][lincol.second] = this->tMap[N_S.first][N_S.second] + 1;
                         toReview = true;
                }
             }
           }

         if (toReview && this->DoesItReallyNeedReview(lincol))
            this->Revision.emplace_back(lincol);

         lincol = this->D.NextStep();
    }

    Revision.remove_if([&](const LinCol& lincol){ return !this->DoesItReallyNeedReview(lincol); });
    this->ReviewExceptionPoints();
}

LinCol ShortWayFinder::SetNextStep(const uint8_t Direction, LinCol NextStep) const {
    switch (Direction) {
           case Turn::RT: NextStep.second++; break;
           case Turn::LF: NextStep.second--; break;
           case Turn::DW: NextStep.first++; break;
           default      : NextStep.first--;
    }

    return NextStep;
}

void ShortWayFinder::ReviewExceptionPoints() {
     while (!this->Revision.empty()) {
           for (uint8_t Direction = Turn::RT; Direction != Turn::NW; ++Direction) {
               LinCol N_S = this->SetNextStep(Direction, this->Revision.front());
               if (this->tMap[N_S.first][N_S.second] != WALL &&
                   this->tMap[N_S.first][N_S.second] > this->tMap[this->Revision.front().first][this->Revision.front().second] + 1) {
                   this->tMap[N_S.first][N_S.second] = this->tMap[this->Revision.front().first][this->Revision.front().second] + 1;
                   this->Revision.emplace_back(N_S);
               }
           }

           this->Revision.pop_front();
     }
}

bool ShortWayFinder::DoesItReallyNeedReview(const LinCol& CurrPoint) const {
     for (uint8_t Direction = 1; Direction <= Turn::LF; Direction <<= 1) {
         LinCol N_S = this->SetNextStep(Direction, CurrPoint);

         if (this->tMap[N_S.first][N_S.second] != WALL &&
             this->tMap[N_S.first][N_S.second] > this->tMap[CurrPoint.first][CurrPoint.second] + 1 &&
             this->IsItNOTNear2AnPointAlreadyAdded2Review(CurrPoint))
             return true;
     }

     return false;
}

bool ShortWayFinder::IsItNOTNear2AnPointAlreadyAdded2Review(const LinCol& lincol) const {
     for (auto& IIt : Revision)
          for (uint8_t Direction = 1; Direction <= Turn::LF; Direction <<= 1)
               if (IIt == this->SetNextStep(Direction, lincol))
                  return false;

      return true;
}

/*    Revision.remove_if([&](const LinCol& lincol){ return !DoesItReallyNeedReview(lincol, Revision, this->tMap); });

    for (uint32_t tlin = 0; tlin < this->tMap.size(); ++tlin) {
        cout << '\n';
        for (uint32_t tcol = 0; tcol < this->tMap[tlin].size(); ++tcol)
            switch (this->tMap[tlin][tcol]) {
                   case    0: cout << "   "; break;
                   case WALL: cout << "WWW"; break;
                   default  : cout << setw(3) << this->tMap[tlin][tcol];
        }
    }
    cin.get();

    for (uint32_t tlin = 0; tlin < this->tMap.size(); ++tlin) {
        cout << '\n';
        for (uint32_t tcol = 0; tcol < this->tMap[tlin].size(); ++tcol) {
            bool DRAW = true;
            for (auto& Rev : Revision)
                if (tlin == Rev.first && tcol == Rev.second) {
                    DRAW = false;
                    cout << "_X_";
                    break;
                }

            if (DRAW)
                switch (this->tMap[tlin][tcol]) {
                        case    0: cout << "   "; break;
                        case WALL: cout << "WWW"; break;
                        default  : cout << setw(3) << this->tMap[tlin][tcol];
                }
        }
    }
    cin.get();
*/

/*
    ReviewExceptionPoints(Revision, this->tMap);

    for (uint32_t tlin = 0; tlin < this->tMap.size(); ++tlin) {
        cout << '\n';
        for (uint32_t tcol = 0; tcol < this->tMap[tlin].size(); ++tcol)
            switch (this->tMap[tlin][tcol]) {
                   case    0: cout << "   "; break;
                   case WALL: cout << "WWW"; break;
                   default  : cout << setw(3) << this->tMap[tlin][tcol];
        }
    }
    cin.get();
*/

