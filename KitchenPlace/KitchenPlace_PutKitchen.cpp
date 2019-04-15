/**
    File    : KitchenPlace_PutKitchen.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.29            Version: 20190331.3

    Show the result map within the best places to install the kitchen on room nearest to all employees

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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
