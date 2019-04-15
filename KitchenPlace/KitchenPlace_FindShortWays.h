/**
    File    : KitchenPlace_FindShortWays.h
    Author  : Menashe Rosemberg
    Created : 2019.03.29            Version: 20190415.1

    Find the best places to install the kitchen on room nearest to all employees

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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
