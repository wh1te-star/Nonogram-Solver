#ifndef VERSANO_CORE_HINTSETLIST_H
#define VERSANO_CORE_HINTSETLIST_H

#include "Core/Board/BoardLength/BoardLength.h"
#include "Core/Hint/HintSet/HintSet.h"

#include <vector>

namespace VersaNo::Core {

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

} // namespace VersaNo::Core

#endif // VERSANO_CORE_HINTSETLIST_H
