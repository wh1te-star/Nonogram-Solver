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
  typename Core::LineTraits<TOrientation>::Line &line,
  PlacementCount &placementCount,
  IBoardUpdateHandler &boardUpdateHandler) {
    auto result = DPPlacementPatternCount(hintList, line, placementCount, boardUpdateHandler);
    return result;
}

template <typename TOrientation>
PlacementPatternCounterResult DPPlacementPatternCounter<TOrientation>::DPPlacementPatternCount(
  const HintList &hintList,
  typename Core::LineTraits<TOrientation>::Line &line,
  PlacementCount &placementCount,
  IBoardUpdateHandler &boardUpdateHandler) {
    using Traits = typename Core::LineTraits<TOrientation>;
    using Index = typename Traits::Index;
    using PeerIndex = typename Traits::PeerIndex;
    using Length = typename Traits::Length;
    using PeerLength = typename Traits::PeerLength;
    using Line = typename Traits::Line;

    size_t hintsCount = hintList.size();
    size_t totalLength = line.size();
    std::vector<std::vector<PlacementCount>> partialCount(
      hintsCount + 1, std::vector<PlacementCount>(totalLength + 1, PlacementCount(0)));

    partialCount[0][0] = PlacementCount(1);

    for (PeerIndex index : PeerIndex::closedRangeUp(1, (int)totalLength)) {
        Cell cell = line[index];

        if (cell.canColor(White)) {
            partialCount[0][index.value] = PlacementCount(1);
        } else {
            break;
        }
    }

    for (HintIndex hintIndex : HintIndex::closedRangeUp(1, (int)hintsCount)) {
        HintNumber hintNumber = hintList[hintIndex - 1];

        for (PeerIndex index : PeerIndex::closedRangeUp(1, (int)totalLength)) {
            if (line[index - 1].canColor(White)) {
                partialCount[hintIndex.value][index.value] =
                  partialCount[hintIndex.value][index.value - 1];
            }

            if (index >= PeerLength(hintNumber.value)) {
                PeerIndex prevCellIndex = index - hintNumber.value - 1;

                PeerIndex blockStart = index - hintNumber.value;

                bool canPlaceBlock = true;
                canPlaceBlock &= isBlockFits(line, blockStart, hintNumber);
                canPlaceBlock &= isSeparated(line, prevCellIndex);

                if (canPlaceBlock) {
                    if (prevCellIndex < PeerLength(0)) {
                        partialCount[hintIndex.value][index.value] +=
                          partialCount[hintIndex.value - 1][0];
                    } else {
                        partialCount[hintIndex.value][index.value] +=
                          partialCount[hintIndex.value - 1][prevCellIndex.value];
                    }
                }
            }

            if (partialCount[hintIndex.value][index.value] > PlacementCount(MAX_COUNT)) {
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
    using Traits = typename Core::LineTraits<TOrientation>;
    using Index = typename Traits::Index;
    using PeerIndex = typename Traits::PeerIndex;

    if (prevCellIndex < PeerIndex(0)) {
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
    using Traits = typename Core::LineTraits<TOrientation>;
    using Index = typename Traits::Index;
    using PeerIndex = typename Traits::PeerIndex;
    using Length = typename Traits::Length;
    using PeerLength = typename Traits::PeerLength;

    for (PeerIndex index :
         PeerIndex::closedRangeUp(blockStart.value, blockStart.value + hintNumber.value - 1)) {
        Cell cell = line[index];
        if (!cell.canColor(Black)) {
            return false;
        }
    }
    return true;
}

template class DPPlacementPatternCounter<Core::RowOrientation>;
template class DPPlacementPatternCounter<Core::ColumnOrientation>;

} // namespace VersaNo::Solver