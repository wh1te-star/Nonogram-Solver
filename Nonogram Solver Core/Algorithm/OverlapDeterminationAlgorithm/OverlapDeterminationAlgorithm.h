#ifndef OVERLAPPATTERNCOUNTALGORITHM_H
#define OVERLAPPATTERNCOUNTALGORITHM_H


#include <vector>
#include "Cell.h"
#include "Column.h"
#include "HintSet.h"
#include "ColumnPlacement.h"

class OverlapDeterminationAlgorithm {
public:
    static Line run(
        const Line& line,
		const HintSet& HintSet
    );

    static Line determineByOverlap(
        const Line& line,
		const HintSet& HintSet
    );
};


#endif
