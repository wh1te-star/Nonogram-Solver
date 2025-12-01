#ifndef FINDLEFTMOSTPLACEMENTALGORITHM_H
#define FINDLEFTMOSTPLACEMENTALGORITHM_H


#include <vector>
#include "Cell.h"
#include "Column.h"
#include "HintSet.h"
#include "ColumnPlacement.h"

class FindLeftMostPlacementAlgorithm {
public:
	static Placement run(
		const Line& line,
		const HintSet& HintSet
	);

    static Placement getLeftMostPlacement(
        const Line& line,
		const HintSet& HintSet
    );

    static Placement getLeftMostPlacementRecursive(
		const Line& line,
		const HintSet& HintSet,
		Placement& currentPlacement,
		int currentHintIndex
	);
};


#endif
