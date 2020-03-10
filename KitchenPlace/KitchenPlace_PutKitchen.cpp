/**
    File    : KitchenPlace_PutKitchen.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.29            Version: 20190331.3

    Show the result map within the best places to install the kitchen on room nearest to all employees

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
#include "KitchenPlace_PutKitchen.h"

void PutKitchen(vector<pair<LinCol, Matrix>>& Employees) {

     //Aggregate all maps
     for (uint16_t Employee = 1; Employee < Employees.size(); ++Employee)
         for (uint16_t Lin = 0; Lin < Employees[0].second.size(); ++Lin)
             for (uint16_t Col = 0; Col < Employees[0].second[0].size(); ++Col)
                 if (Employees[0].second[Lin][Col] != WALL)
                     Employees[0].second[Lin][Col] += Employees[Employee].second[Lin][Col];

     //Find the best places
     uint16_t Cheaper = WALL-1;
     //list<LinCol> TheBestLocations;
     for (LCType Lin = 0; Lin < Employees[0].second.size(); ++Lin)
         for (LCType Col = 0; Col < Employees[0].second[0].size(); ++Col) //{
             if (Employees[0].second[Lin][Col] < Cheaper) //{
                Cheaper = Employees[0].second[Lin][Col];
                //TheBestLocations.clear();
             //}
             //if (Employees[0].second[Lin][Col] == Cheaper)
                //TheBestLocations.emplace_back(Lin, Col);
         //}

     //Put the kitchen on the original map and show it
     for (LCType Lin = 0; Lin < Employees[0].second.size(); ++Lin) {
         cout << '\n';
         for (LCType Col = 0; Col < Employees[0].second[0].size(); ++Col)
             if (Employees[0].second[Lin][Col] == WALL)
                     cout << 'W';
             else if (Employees[0].second[Lin][Col] == Cheaper)
                     cout << 'k';
             else
                     cout << ' ';
     }
     cout << "\n*The best places to Kitchen in this room is marked as 'k' on map.\n\n";
}
