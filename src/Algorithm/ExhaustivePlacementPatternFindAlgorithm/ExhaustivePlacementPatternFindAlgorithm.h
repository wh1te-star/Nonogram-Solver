#ifndef EXHAUSTIVEPLACEMENTPATTERNFINDALGORITHM_H
#define EXHAUSTIVEPLACEMENTPATTERNFINDALGORITHM_H


#include <vector>
#include "Cell.h"
#include "Line.h"
#include "Placement.h"
#include "HintSet.h"

class ExhaustivePlacementPatternFindAlgorithm {
public:
	static std::vector<Placement> run(
		const Line& line,
		const HintSet& HintSet
	);

	static std::vector<Placement> findPlacementsExhaustive(
		const Line& line,
		const HintSet& HintSet
	);

	static void findPlacementsExhaustiveRecursive(
		const Line& line,
		const HintSet& HintSet,
		std::vector<Placement>& solutions,
		Placement& currentPlacement,
		int currentHintIndex
	);
};


#endif
