/**
    File    : KitchenPlace.h
    Author  : Menashe Rosemberg
    Created : 2019.03.29            Version: 20190415.1

    Find the best places to install the kitchen on room nearest to all employees

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef KITCHENPLACE_H
#define KITCHENPLACE_H

#include <limits>
#include <vector>
#include <cinttypes>

using namespace std;

using Matrix = vector<vector<uint16_t>>;
constexpr uint16_t WALL  = numeric_limits<uint16_t>::max();
constexpr uint16_t EMPTY = numeric_limits<uint16_t>::max();

using LCType = uint32_t;
using LinCol = pair<LCType, LCType>;
constexpr LCType LCLimit = numeric_limits<LCType>::max();

#endif // KITCHENPLACE_H
