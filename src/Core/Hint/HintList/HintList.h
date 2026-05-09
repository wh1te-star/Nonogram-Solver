#ifndef VERSANO_CORE_HINTSET_H
#define VERSANO_CORE_HINTSET_H

#include "Core/Types/AppliedType/AppliedType.h"

#include <vector>

namespace VersaNo::Core {


class HintList {
  private:
    std::vector<HintNumber> numbers;

  public:
    HintList(std::vector<HintNumber> numbers);
    HintList(std::vector<int> numbers);

  public:
    std::vector<HintNumber> getNumbers() const;

  public:
    bool operator==(const HintList &other) const;
    bool operator!=(const HintList &other) const;
    HintNumber operator[](int index) const;

  public:
    size_t size() const;
};


} // namespace VersaNo::Core


#endif // VERSANO_CORE_HINTSET_H
