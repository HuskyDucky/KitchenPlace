/**
    File    : KitchenPlace_MapEmployees.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.30            Version: 20190405.1

    Normalize the map and find the employees

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
#include "KitchenPlace_MapEmployees.h"

vector<pair<LinCol, Matrix>> CreateEnployeesList(const vector<string>& sMap) {
    vector<LinCol> Emps;

    Matrix tMap(sMap.size(), vector<uint16_t>(sMap[0].size(), 0));   //Image the string map
    for (uint16_t Lin = 0; Lin < sMap.size(); ++Lin)
        for (uint16_t Col = 0; Col < sMap[Lin].size(); ++Col)
            switch (sMap[Lin][Col]) {
                   case 'E' : Emps.emplace_back(Lin, Col); break;   //Find employees
                   case 'W' : tMap[Lin][Col] = WALL;                //Copy the walls
            }

    vector<pair<LinCol, Matrix>> Employees;

    for (auto& Emp : Emps)
        Employees.emplace_back(make_pair(Emp, tMap));

    return Employees;
}


