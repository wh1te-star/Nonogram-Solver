#ifndef VERSANO_CORE_HINTSETLIST_H
#define VERSANO_CORE_HINTSETLIST_H

#include "Core/Board/BoardLength/BoardLength.h"
#include "Core/Hint/HintList/HintList.h"

#include <vector>

namespace VersaNo::Core {

class HintGroup {
  private:
  protected:
    std::vector<HintList> hintGroup;

  public:
    explicit HintGroup(std::vector<HintList> HintGroup);
    virtual ~HintGroup() = default;

  public:
    std::vector<HintList> getHintGroup() const;

  public:
    bool operator==(const HintGroup &other) const;
    bool operator!=(const HintGroup &other) const;
    const HintList &operator[](const CellIndex &index) const;

  public:
    size_t size() const;
    int getMaxItemCount() const;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_HINTSETLIST_H
