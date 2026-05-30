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
    nonogramBoard.applyLine(linePosition, line, true);
}

} // namespace VersaNo::Solver