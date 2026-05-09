#ifndef VERSANO_CORE_ROWHINTSETLIST_H
#define VERSANO_CORE_ROWHINTSETLIST_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Hint/HintList/HintList.h"

namespace VersaNo::Core {


class RowHintGroup {
  private:
    std::vector<HintList> hintGroup;

  public:
    explicit RowHintGroup(std::vector<HintList> hintGroup);

  public:
    std::vector<HintList> getHintGroup() const;

  public:
    bool operator==(const RowHintGroup &other) const;
    bool operator!=(const RowHintGroup &other) const;
    HintList operator[](RowIndex rowIndex) const;

  public:
    size_t size() const;
    ColumnLength getMaxHintListLength() const;
};


} // namespace VersaNo::Core


#endif // VERSANO_CORE_ROWHINTSETLIST_H
