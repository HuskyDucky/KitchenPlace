/**
    File    : KitchenPlace.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.28            Version: 20190415.2

    Find the best places to install the kitchen on room nearest to all employees

    Copyright (c) 2019 HuskyDucky (Menashe Rosemberg) rosemberg@ymail.com

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
#include "KitchenPlace_ReadMap.h"
#include "KitchenPlace_MapEmployees.h"
#include "KitchenPlace_ManageDirections.h"
#include "KitchenPlace_FindShortWays.h"
#include "KitchenPlace_PutKitchen.h"
#include "KitchenPlace_ERROR.h"

static void CheckEmptySpaces(const Matrix& tMap) {
       Directions D(tMap);

       if (D.HasUnreachablePlace())
          ERROR("\n\nThis Map has unreachable place(s)\n");
}

int main() {
    vector<string> sMap = ReadMap();

    for (uint16_t Lin = 0; Lin < sMap.size(); ++Lin)        //Print Original Map
        cout << '\n' << sMap[Lin];
    cout << "\n*Original map.\n\n";

    auto Employees = CreateEnployeesList(sMap);

    if (Employees.empty())
       cerr << "\n\nNo Employees were found in this map\n\n";

    CheckEmptySpaces(Employees[0].second);

    for (auto& Emp : Employees) {
        ShortWayFinder SWF(Emp.first, Emp.second);
        SWF.SetDistancesOnMap();
    }

    PutKitchen(Employees);

    return 0;
}
