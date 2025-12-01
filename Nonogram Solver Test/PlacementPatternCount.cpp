#include "pch.h"

#include <vector>
#include "PlacementPatternCountAlgorithm.h"
#include "Line.h"
#include "HintSet.h"
#include "Cell.h"


TEST(Algorithm_PlacementPatternCount, VerySimpleCase) {
    Line line = Line("     ");
    HintSet hintSet = HintSet({ 1, 2 });

    PlacementCount result = PlacementPatternCountAlgorithm::run(line, hintSet);
    EXPECT_EQ(result.getCount(), 3);
}

TEST(Algorithm_PlacementPatternCount, DeterministicCase) {
    Line line = Line("    ");
    HintSet hintSet = HintSet({ 1, 2 });

    PlacementCount result = PlacementPatternCountAlgorithm::run(line, hintSet);
    EXPECT_EQ(result.getCount(), 1);
}

TEST(Algorithm_PlacementPatternCount, ImpossibleCase) {
    Line line = Line("   WW");
    HintSet hintSet = HintSet({ 1, 2 });

    PlacementCount result = PlacementPatternCountAlgorithm::run(line, hintSet);
    EXPECT_EQ(result.getCount(), 0);
}
