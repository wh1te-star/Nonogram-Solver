#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Board/NonogramBoard/NonogramBoard.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

template <typename TOrientation>
LineAssumption<TOrientation>::LineAssumption(const LinePosition<TOrientation> &linePosition, const Line<TOrientation> &line)
    : linePosition(linePosition), line(line) {}

template <typename TOrientation>
void LineAssumption<TOrientation>::applyTo(NonogramBoard &nonogramBoard) const {
    nonogramBoard.applyLine<TOrientation>(linePosition, line, true);
}

// explicit template instantiation
template class LineAssumption<Core::RowOrientation>;
template class LineAssumption<Core::ColumnOrientation>;

} // namespace VersaNo::Solver