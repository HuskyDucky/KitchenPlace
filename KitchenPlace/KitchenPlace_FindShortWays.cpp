/**
    File    : KitchenPlace_FindShortWays.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.28            Version: 20190415.1

    Find the best places to install the kitchen on room nearest to all this->Employees

    Copyright (c) 2019 TheArquitect (Menashe Rosemberg) rosemberg@ymail.com

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/
#include "KitchenPlace_FindShortWays.h"

ShortWayFinder::ShortWayFinder(const LinCol& EmpLC,
                               Matrix& tMapLC) :
                                                Emp(EmpLC),
                                                tMap(tMapLC),
                                                D(tMapLC, EmpLC.first, EmpLC.second) {}

void ShortWayFinder::SetDistancesOnMap() {
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
