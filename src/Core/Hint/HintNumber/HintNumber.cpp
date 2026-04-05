#include "Core/Hint/HintNumber/HintNumber.h"

namespace VersaNo::Core {

HintNumber::HintNumber(int number) : number(number) {}

const int &HintNumber::getNumber() const { return number; }

bool HintNumber::operator==(const HintNumber &other) const { return number == other.number; }

bool HintNumber::operator!=(const HintNumber &other) const { return !(*this == other); }

} // namespace VersaNo::Core