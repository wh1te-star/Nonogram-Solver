#include "Solver/PlacementPatternCounter/DPPlacementPatternCounter/DPPlacementPatternCounter.h"

DPPlacementPatternCounter::DPPlacementPatternCounter() {}

DPPlacementPatternCounter::DPPlacementPatternCounter(int MAX_COUNT) : MAX_COUNT(MAX_COUNT) {}

PlacementPatternCounterResult DPPlacementPatternCounter::count(
  const HintSet &hintSet,
  Line &line,
  PlacementCount &placementCount,
  IBoardUpdateHandler &boardUpdateHandler) {
    auto result = DPPlacementPatternCount(hintSet, line, placementCount, boardUpdateHandler);
    return result;
}

PlacementPatternCounterResult DPPlacementPatternCounter::DPPlacementPatternCount(
  const HintSet &hintSet,
  const Line &line,
  PlacementCount &placementCount,
  IBoardUpdateHandler &boardUpdateHandler) {
    int hintsCount = hintSet.size();
    int totalLength = line.size();
    std::vector<std::vector<PlacementCount>> partialCount(
      hintsCount + 1, std::vector<PlacementCount>(totalLength + 1, PlacementCount(0)));

    partialCount[0][0] = PlacementCount(1);

    for (int cellIndexInt = 1; cellIndexInt <= totalLength; cellIndexInt++) {
        CellIndex cellIndex = CellIndex(cellIndexInt - 1);
        Cell cell = line[cellIndex];

        if (cell.canColor(White)) {
            partialCount[0][cellIndexInt] = PlacementCount(1);
        } else {
            break;
        }
    }

    for (int hintNumberIndexInt = 1; hintNumberIndexInt <= hintsCount; hintNumberIndexInt++) {
        HintNumber hintNumber = hintSet[hintNumberIndexInt - 1];

        for (int cellIndexInt = 1; cellIndexInt <= totalLength; cellIndexInt++) {
            CellIndex cellIndex = CellIndex(cellIndexInt);

            if (line[cellIndex - 1].canColor(White)) {
                partialCount[hintNumberIndexInt][cellIndexInt] =
                  partialCount[hintNumberIndexInt][cellIndexInt - 1];
            }

            if (cellIndex >= BoardLength(hintNumber.getNumber())) {
                CellIndex prevCellIndex = cellIndex - hintNumber - 1;

                CellIndex blockStart = cellIndex - hintNumber;

                bool canPlaceBlock = true;
                canPlaceBlock &= isBlockFits(line, blockStart, hintNumber);
                canPlaceBlock &= isSeparated(line, prevCellIndex);

                if (canPlaceBlock) {
                    if (prevCellIndex < 0) {
                        partialCount[hintNumberIndexInt][cellIndexInt] +=
                          partialCount[hintNumberIndexInt - 1][0];
                    } else {
                        partialCount[hintNumberIndexInt][cellIndexInt] +=
                          partialCount[hintNumberIndexInt - 1][prevCellIndex.getIndex()];
                    }
                }
            }

            if (partialCount[hintNumberIndexInt][cellIndexInt] > PlacementCount(MAX_COUNT)) {
                placementCount = PlacementCount(MAX_COUNT);
                return PlacementPatternCounterResult::tooManyPatterns;
            }
        }
    }

    placementCount = partialCount[hintsCount][totalLength];
    return PlacementPatternCounterResult::success;
}

bool DPPlacementPatternCounter::isSeparated(const Line &line, const CellIndex &prevCellIndex) {
    if (prevCellIndex < 0) {
        return true;
    }
    Cell prevCell = line[prevCellIndex];
    return prevCell.canColor(White);
}

bool DPPlacementPatternCounter::isBlockFits(
  const Line &line, const CellIndex &blockStart, const HintNumber &hintNumber) {
    for (int offset = 0; offset < hintNumber.getNumber(); offset++) {
        CellIndex cellIndex = blockStart + offset;
        Cell cell = line[cellIndex];
        if (!cell.canColor(Black)) {
            return false;
        }
    }
    return true;
}
