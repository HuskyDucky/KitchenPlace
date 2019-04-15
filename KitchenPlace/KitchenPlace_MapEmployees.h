/**
    File    : KitchenPlace_MapEmployees.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.30            Version: 20190330.2

    Normalize the map and find the employees

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef MAPEMP_H
#define MAPEMP_H

#include <string>

#include "KitchenPlace.h"

vector<pair<LinCol, Matrix>> CreateEnployeesList(const vector<string>& sMap);

#endif // MAPEMP_H
