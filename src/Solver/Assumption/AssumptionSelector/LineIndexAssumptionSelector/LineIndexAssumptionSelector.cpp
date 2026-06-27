#include "Solver/Assumption/AssumptionSelector/LineIndexAssumptionSelector/LineIndexAssumptionSelector.h"

#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"
#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include "Solver/ResultEnum/ExhaustivePlacementPatternFinderResult.h"

#include <cassert>
#include <type_traits>

using namespace VersaNo::Core;
namespace VersaNo::Solver {

template <typename TOrientation>
LineIndexAssumptionSelector<TOrientation>::LineIndexAssumptionSelector() {}

template <typename TOrientation>
std::unique_ptr<IAssumptionPosition> LineIndexAssumptionSelector<TOrientation>::select(
  const NonogramBoard &board, const AssumptionSelectionContext &context) {
    using Traits = Core::LineTraits<TOrientation>;
    using PeerOrientation = typename Traits::PeerOrientation;
    using Index = typename Traits::Index;
    using Length = typename Traits::Length;

    int currentIndex = context.depth;

    int lineCount = board.getLength<TOrientation>().value;
    if (currentIndex >= lineCount) {
        assert(false);
    }

    Index lineIndex(currentIndex);
    LinePosition<TOrientation> linePosition(lineIndex);
    return std::make_unique<LineAssumptionPosition<TOrientation>>(linePosition);
}

template class LineIndexAssumptionSelector<Core::RowOrientation>;
template class LineIndexAssumptionSelector<Core::ColumnOrientation>;

} // namespace VersaNo::Solver