#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"

#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/Types/AppliedType/AppliedType.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

template <typename TOrientation>
LineAssumption<TOrientation>::LineAssumption(
  const LinePosition<TOrientation> &linePosition,
  const typename LineTraits<TOrientation>::Line &line)
    : linePosition(linePosition), line(line) {}

template <typename TOrientation>
void LineAssumption<TOrientation>::applyTo(NonogramBoard &nonogramBoard) const {
    nonogramBoard.applyLine<TOrientation>(linePosition, line, true);
}

// explicit template instantiation
template class LineAssumption<Core::RowOrientation>;
template class LineAssumption<Core::ColumnOrientation>;

} // namespace VersaNo::Solver