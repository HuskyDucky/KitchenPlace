/**
    File    : KitchenPlace_FindShortWays.h
    Author  : Menashe Rosemberg
    Created : 2019.03.29            Version: 20190415.1

    Find the best places to install the kitchen on room nearest to all employees

    Copyright (c) 2019 HuskyDucky (Menashe Rosemberg) rosemberg@ymail.com

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
#ifndef KITCHENPLACE_SHORTWAYS_H
#define KITCHENPLACE_SHORTWAYS_H

#include <list>

#include "KitchenPlace.h"
#include "KitchenPlace_ManageDirections.h"

using RevisionType = list<LinCol>;

struct ShortWayFinder {
       ShortWayFinder(const LinCol& EmpLC, Matrix& tMapLC);

    void SetDistancesOnMap();

    private:
        const LinCol& Emp;
        Matrix& tMap;

        Directions D;

        RevisionType Revision;

        void ReviewExceptionPoints();
        bool DoesItReallyNeedReview(const LinCol& CurrPoint) const;
        bool IsItNOTNear2AnPointAlreadyAdded2Review(const LinCol& lincol) const;
        LinCol SetNextStep(const uint8_t Direction, LinCol NextStep) const;
};


#endif // KITCHENPLACE_SHORTWAYS_H
