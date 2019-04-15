/**
    File    : KitchenPlace_ReadMap.cpp
    Author  : Menashe Rosemberg
    Created : 2019.0331            Version: 20190331.1

    Read map from Kitchen.txt file

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "KitchenPlace_ReadMap.h"

vector<string> ReadMap() {
    vector<string> sMap;

        if (!fs::exists(FileName)) throw runtime_error("File "+ FileName + " doesn't exist.");

        ifstream fFile(FileName);

        if (!fFile.good()) throw runtime_error("I couldn't read "+ FileName + ".");

        string::size_type LineSize = string::npos;
        string Line;
        while (getline(fFile, Line)) {
              if (LineSize == string::npos)
                  LineSize = Line.size();
              else if (Line.size() != LineSize)
                      throw runtime_error("The map in " + FileName + " is not good.");

              sMap.push_back(move(Line));
        }

    return sMap;
}
