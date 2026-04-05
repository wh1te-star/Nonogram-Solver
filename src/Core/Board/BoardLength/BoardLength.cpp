#include "Core/Board/BoardLength/BoardLength.h"

namespace VersaN::Core {

BoardLength::BoardLength(int length) : length(length) {}

int BoardLength::getLength() const { return length; }

} // namespace VersaN::Core