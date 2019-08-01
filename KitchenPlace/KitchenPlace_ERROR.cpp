/**
    File    : KitchenPlace_ERROR.cpp
    Author  : Menashe Rosemberg
    Created : 2019.07.25            Version: 20190725.1

    Abort program

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/

#include "KitchenPlace_ERROR.h"

void ERROR(const std::string& Msg) {
     std::cerr << Msg << std::endl;
          abort();
}
