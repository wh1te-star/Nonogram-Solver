#ifndef PLACEMENTPATTERNCOUNTALGORITHM_H
#define PLACEMENTPATTERNCOUNTALGORITHM_H


#include "PlacementCount.h"
#include "Line.h"
#include "HintSet.h"

class PlacementPatternCountAlgorithm {
public:
	static inline const PlacementCount MAX_COUNT = PlacementCount(999);

public:
	static PlacementCount run(
		const Line& line,
		const HintSet& HintSet
	);

private:
	static PlacementCount CountPlacement(
		const Line& line,
		const HintSet& HintSet
	);

	static bool isSeparated(
		const Line& line,
		const CellIndex& prevCellIndex
	);

	static bool isBlockFits(
		const Line& line,
		const CellIndex& blockStart,
		const HintNumber& hintNumber
	);
};


#endif
