/**
    File    : KitchenPlace.h
    Author  : Menashe Rosemberg
    Created : 2019.03.29            Version: 20190415.1

    Find the best places to install the kitchen on room nearest to all employees

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software developed to SQLLink internal use only.
**/
#ifndef KITCHENPLACE_H
#define KITCHENPLACE_H

#include <cinttypes>
#include <limits>
#include <vector>

using namespace std;

using Matrix = vector<vector<uint16_t>>;
constexpr uint16_t WALL  = numeric_limits<uint16_t>::max();
constexpr uint16_t EMPTY = numeric_limits<uint16_t>::max();

using LinCol = pair<uint32_t, uint32_t>;
constexpr uint32_t LCLimit = numeric_limits<uint32_t>::max();

#endif // KITCHENPLACE_H
