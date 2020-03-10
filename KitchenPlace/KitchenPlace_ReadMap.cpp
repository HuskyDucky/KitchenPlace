/**
    File    : KitchenPlace_ReadMap.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.31            Version: 20190331.2

    Read map from Kitchen.txt file

    BSD License

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
#include "KitchenPlace_ReadMap.h"
#include "KitchenPlace_ERROR.h"

vector<string> ReadMap() {
    vector<string> sMap;

        if (!fs::exists(FileName)) ERROR("File "+ FileName + " doesn't exist.");

        ifstream fFile(FileName);

        if (!fFile.good()) ERROR("I couldn't read "+ FileName + ".");

        string::size_type LineSize = string::npos;
        string Line;
        while (getline(fFile, Line)) {
              if (LineSize == string::npos)
                  LineSize = Line.size();
              else if (Line.size() != LineSize)
                      ERROR("The map in " + FileName + " is not good.");

              sMap.push_back(move(Line));
        }

    return sMap;
}
