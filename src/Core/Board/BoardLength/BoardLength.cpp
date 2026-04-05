#include "Core/Board/BoardLength/BoardLength.h"

namespace VersaNo::Core {

BoardLength::BoardLength(int length) : length(length) {}

int BoardLength::getLength() const { return length; }

} // namespace VersaNo::Core