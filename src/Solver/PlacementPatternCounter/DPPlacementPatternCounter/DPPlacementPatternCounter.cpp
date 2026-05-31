#include "Solver/PlacementPatternCounter/DPPlacementPatternCounter/DPPlacementPatternCounter.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

template <typename TOrientation>
DPPlacementPatternCounter<TOrientation>::DPPlacementPatternCounter() {}

template <typename TOrientation>
DPPlacementPatternCounter<TOrientation>::DPPlacementPatternCounter(int MAX_COUNT)
    : MAX_COUNT(MAX_COUNT) {}

template <typename TOrientation>
PlacementPatternCounterResult DPPlacementPatternCounter<TOrientation>::count(
  const HintList &hintList,
  Line<TOrientation> &line,
  PlacementCount &placementCount,
  IBoardUpdateHandler &boardUpdateHandler) {
    auto result = DPPlacementPatternCount(hintList, line, placementCount, boardUpdateHandler);
    return result;
}

template <typename TOrientation>
PlacementPatternCounterResult DPPlacementPatternCounter<TOrientation>::DPPlacementPatternCount(
  const HintList &hintList,
  const Line<TOrientation> &line,
  PlacementCount &placementCount,
  IBoardUpdateHandler &boardUpdateHandler) {
    int hintsCount = hintList.size();
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
        HintNumber hintNumber = hintList[hintNumberIndexInt - 1];

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

template <typename TOrientation>
bool DPPlacementPatternCounter<TOrientation>::isSeparated(
  const Core::Line<typename Core::LineTraits<TOrientation>::PeerIndex> &line,
  const typename Core::LineTraits<TOrientation>::PeerIndex &prevCellIndex) {
    if (prevCellIndex < 0) {
        return true;
    }
    Cell prevCell = line[prevCellIndex];
    return prevCell.canColor(White);
}

template <typename TOrientation>
bool DPPlacementPatternCounter<TOrientation>::isBlockFits(
      const Core::Line<typename Core::LineTraits<TOrientation>::PeerIndex> &line,
      const typename Core::LineTraits<TOrientation>::PeerIndex &blockStart,
      const Core::HintNumber &hintNumber) {
    for (int offset = 0; offset < hintNumber.getNumber(); offset++) {
        CellIndex cellIndex = blockStart + offset;
        Cell cell = line[cellIndex];
        if (!cell.canColor(Black)) {
            return false;
        }
    }
    return true;
}

} // namespace VersaNo::Solver