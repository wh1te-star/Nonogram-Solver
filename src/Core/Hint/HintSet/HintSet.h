#ifndef VERSAN_CORE_HINTSET_H
#define VERSAN_CORE_HINTSET_H

#include "Core/Hint/HintNumber/HintNumber.h"
#include "Core/Index/CellIndex/CellIndex.h"

#include <vector>

namespace VersaN::Core {

class HintSet {
  private:
    std::vector<HintNumber> numbers;

  public:
    HintSet(std::vector<HintNumber> numbers);
    HintSet(std::vector<int> numbers);

  public:
    std::vector<HintNumber> getNumbers() const;

  public:
    bool operator==(const HintSet &other) const;
    bool operator!=(const HintSet &other) const;
    HintNumber operator[](int index) const;

  public:
    size_t size() const;
};

} // namespace VersaN::Core

#endif // VERSAN_CORE_HINTSET_H
