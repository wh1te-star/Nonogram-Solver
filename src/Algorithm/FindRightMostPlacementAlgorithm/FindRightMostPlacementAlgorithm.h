#ifndef FINDRIGHTMOSTPLACEMENTALGORITHM_H
#define FINDRIGHTMOSTPLACEMENTALGORITHM_H


#include <vector>
#include "Cell.h"
#include "Column.h"
#include "HintSet.h"
#include "ColumnPlacement.h"

class FindRightMostPlacementAlgorithm {
public:
	static Placement run(
		const Line& line,
		const HintSet& HintSet
	);

    static Placement getRightMostPlacement(
        const Line& line,
		const HintSet& HintSet
    );

    static Placement getRightMostPlacementRecursive(
		const Line& line,
		const HintSet& HintSet,
		Placement& currentPlacement,
		int currentHintIndex
	);
};


#endif
