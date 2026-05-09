#include "Core/Hint/HintList/HintList.h"

namespace VersaNo::Core {

HintList::HintList(std::vector<HintNumber> numbers) : numbers(numbers) {}

HintList::HintList(std::vector<int> numbers) {
    for (int number : numbers) {
        this->numbers.push_back(HintNumber(number));
    }
}

std::vector<HintNumber> HintList::getNumbers() const { return numbers; }

bool HintList::operator==(const HintList &other) const { return numbers == other.numbers; }

bool HintList::operator!=(const HintList &other) const { return !(*this == other); }

HintNumber HintList::operator[](int index) const { return numbers[index]; }

size_t HintList::size() const { return numbers.size(); }

} // namespace VersaNo::Core