/**
    File    : KitchenPlace_ManageDirections.h
    Author  : Menashe Rosemberg
    Created : 2019.03.29            Version: 20190414.3

    Find the best places to install the kitchen on room nearest to all employees

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
#ifndef KITCHENPLACE_MANDIR_H
#define KITCHENPLACE_MANDIR_H

#include "KitchenPlace.h"

#include <iostream>
#include <optional>
#include <stack>

namespace Turn {
          constexpr uint8_t RT = 0b00000001;
          constexpr uint8_t DW = 0b00000010;
          constexpr uint8_t UP = 0b00000100;
          constexpr uint8_t LF = 0b00001000;

          constexpr uint8_t NW = 0b00001111;
}

using MiniMatrix = vector<vector<uint8_t>>;
constexpr uint8_t wall = numeric_limits<uint8_t>::max();

struct Directions {
       Directions(const Matrix& tMap,
                  LCType lin = LCLimit,
                  LCType col = LCLimit);

    LinCol NextStep();
    LinCol CurrPosition() const;

    bool HasUnreachablePlace();     //may return a false positive if this->NextStep() didn't finished to run over all reachable places
    //void Reset();                   //The object need to be reset after HasUnreachablePlace() had run

    private:
        const LCType dMapLinSize;
        const LCType dMapColSize;
        MiniMatrix dMap;
        LCType Lin;
        LCType Col;

        stack<LinCol> Visited;

        bool HasNoWay_Up() const;
        bool HasNoWay_Lf() const;
        bool HasNoWay_Dw() const;
        bool HasNoWay_Rt() const;

        inline void UpdateLinCol();
        void SetPossibleDirections4CurrPosition();
};

#endif // KITCHENPLACE_MANDIR_H
