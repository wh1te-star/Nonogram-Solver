#include "Solver/Assumption/AssumptionSelector/LineIndexAssumptionSelector/LineIndexAssumptionSelector.h"

#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"
#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include "Solver/ResultEnum/ExhaustivePlacementPatternFinderResult.h"

#include <type_traits>
#include <cassert>

using namespace VersaNo::Core;
namespace VersaNo::Solver {

template <typename TOrientation>
LineIndexAssumptionSelector<TOrientation>::LineIndexAssumptionSelector() {}

template <typename TOrientation>
std::unique_ptr<IAssumptionPosition> LineIndexAssumptionSelector<TOrientation>::select(
  const NonogramBoard &board, const AssumptionSelectionContext &context) {
    
    int currentIndex = context.depth;

    using Traits = Core::LineTraits<TOrientation>;
    using IndexType = typename Traits::Index;

    int lineCount = Traits::Length(board).getLength(); // Assuming length can be fetched via traits
    if (currentIndex >= lineCount) {
        assert(false);
    }

    if (std::is_same<TOrientation, Core::RowOrientation>::value) {
        const Core::RowIndex rowIndex(currentIndex);
        LinePosition linePosition(Core::EOrientation::Row, rowIndex);
        return std::make_unique<LineAssumptionPosition>(linePosition);
    } else {
        const Core::ColumnIndex columnIndex(currentIndex);
        LinePosition linePosition(Core::EOrientation::Column, columnIndex);
        return std::make_unique<LineAssumptionPosition>(linePosition);
    }
}

template class LineIndexAssumptionSelector<Core::RowOrientation>;
template class LineIndexAssumptionSelector<Core::ColumnOrientation>;

} // namespace VersaNo::Solver