/**
    File    : KitchenPlace_PutKithen.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.29            Version: 20190331.1

    Show the result map within the best places to install the kitchen on room nearest to all employees

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software developed to SQLLink internal use only.
**/
#ifndef KITCHENSHOW_H
#define KITCHENSHOW_H

//#include <list>
#include <vector>
#include <iostream>

#include "KitchenPlace.h"

using namespace std;

void PutKitchen(vector<pair<LinCol, Matrix>>& Employees);

#endif // KITCHENSHOW_H
