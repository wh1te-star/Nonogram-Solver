#ifndef VERSAN_CORE_HINTSETLIST_H
#define VERSAN_CORE_HINTSETLIST_H

#include "Core/Board/BoardLength/BoardLength.h"
#include "Core/Hint/HintSet/HintSet.h"

#include <vector>

namespace VersaN::Core {

class HintSetList {
  private:
  protected:
    std::vector<HintSet> hintSetList;

  public:
    explicit HintSetList(std::vector<HintSet> HintSetList);
    virtual ~HintSetList() = default;

  public:
    std::vector<HintSet> getHintSetList() const;

  public:
    bool operator==(const HintSetList &other) const;
    bool operator!=(const HintSetList &other) const;
    const HintSet &operator[](const CellIndex &index) const;

  public:
    size_t size() const;
    int getMaxItemCount() const;
};

} // namespace VersaN::Core

#endif // VERSAN_CORE_HINTSETLIST_H
