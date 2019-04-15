/**
    File    : KitchenPlace_ReadMAp.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.31            Version: 20190331.1

    Read map from Kitchen.txt file

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software developed to SQLLink internal use only.
**/
#ifndef READMAP_H
#define READMAP_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

const string FileName = "Kitchen.txt";

vector<string> ReadMap();

#endif // READMAP_H
