#include "Solver/Assumption/Assumption/HintAssumption/HintAssumption.h"

#include "Core/Index/CellIndex/CellIndex.h"
#include "Core/Index/CellIndex/ColumnIndex.h"
#include "Core/Index/CellIndex/RowIndex.h"

using namespace VersaN::Core;
namespace VersaN::Solver {

HintAssumption::HintAssumption(const HintPosition &hintPosition, const HintNumber &hintNumber)
    : hintPosition(hintPosition), hintNumber(hintNumber) {}

void HintAssumption::applyTo(NonogramBoard &nonogramBoard) const {
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

} // namespace VersaN::Solver