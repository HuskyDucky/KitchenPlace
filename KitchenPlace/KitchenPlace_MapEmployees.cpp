/**
    File    : KitchenPlace_MapEmployees.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.30            Version: 20190405.1

    Normalize the map and find the employees

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software developed to SQLLink internal use only.
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


