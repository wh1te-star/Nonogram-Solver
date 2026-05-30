#include "Solver/Assumption/Assumption/HintAssumption/HintAssumption.h"

#include "Core/Types/AppliedType/AppliedType.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

template <typename TOrientation>
HintAssumption<TOrientation>::HintAssumption(
  const HintPosition<TOrientation> &hintPosition, const HintNumber &hintNumber)
    : hintPosition(hintPosition), hintNumber(hintNumber) {}

template <typename TOrientation>
void HintAssumption<TOrientation>::applyTo(NonogramBoard &nonogramBoard) const {
    // Implement later
    /*
    if (hintPosition.getOrientation() == Orientation::Row) {
        RowIndex rowIndex = RowIndex(hintPosition.getCellIndex().getIndex());
        Row row = Row(std::vector<Cell>(, Cell(None)));
        nonogramBoard.applyRow(rowIndex, static_cast<const Row &>(row), true);
    } else {
        ColumnIndex columnIndex = ColumnIndex(hintPosition.getCellIndex().getIndex());
        nonogramBoard.applyColumn(columnIndex, static_cast<const Column &>(line), true);
    }
        */
}

// explicit template instantiation
template class HintAssumption<RowOrientation>;
template class HintAssumption<ColumnOrientation>;

} // namespace VersaNo::Solver