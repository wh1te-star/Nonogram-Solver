#include "Core/Wrapper/IntWrapper/IntWrapper.h"

namespace VersaNo::Core {

explicit IntWrapper::IntWrapper(int v) : value(v) {}

int IntWrapper::get() const { return value; }

bool IntWrapper::operator==(const IntWrapper &other) const { return value == other.value; }
bool IntWrapper::operator!=(const IntWrapper &other) const { return value != other.value; }
bool IntWrapper::operator<(const IntWrapper &other) const { return value < other.value; }
bool IntWrapper::operator>(const IntWrapper &other) const { return value > other.value; }
bool IntWrapper::operator<=(const IntWrapper &other) const { return value <= other.value; }
bool IntWrapper::operator>=(const IntWrapper &other) const { return value >= other.value; }

} // namespace VersaNo::Core
