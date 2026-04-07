/*
#include "Algorithm/PlacementPatternCountAlgorithm/PlacementPatternCountAlgorithm.h"

#include "Board/Line/Line.h"
#include "Cell/Cell/Cell.h"
#include "Hint/HintList/HintList.h"
#include <gtest/gtest.h>
#include <vector>

TEST(Algorithm_PlacementPatternCount, VerySimpleCase) {
  Line line = Line("     ");
  HintList hintList = HintList({1, 2});

  PlacementCount result = PlacementPatternCountAlgorithm::run(line, hintList);
  EXPECT_EQ(result.getCount(), 3);
}

TEST(Algorithm_PlacementPatternCount, DeterministicCase) {
  Line line = Line("    ");
  HintList hintList = HintList({1, 2});

  PlacementCount result = PlacementPatternCountAlgorithm::run(line, hintList);
  EXPECT_EQ(result.getCount(), 1);
}

TEST(Algorithm_PlacementPatternCount, ImpossibleCase) {
  Line line = Line("   WW");
  HintList hintList = HintList({1, 2});

  PlacementCount result = PlacementPatternCountAlgorithm::run(line, hintList);
  EXPECT_EQ(result.getCount(), 0);
}

*/