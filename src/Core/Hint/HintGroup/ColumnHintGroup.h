#ifndef VERSANO_CORE_COLUMNHINTSETLIST_H
#define VERSANO_CORE_COLUMNHINTSETLIST_H


#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Hint/HintList/HintList.h"

namespace VersaNo::Core {


class ColumnHintGroup {
  private:
    std::vector<HintList> hintGroup;

  public:
    explicit ColumnHintGroup(std::vector<HintList> hintGroup);

  public:
    std::vector<HintList> getHintGroup() const;

  public:
    bool operator==(const ColumnHintGroup &other) const;
    bool operator!=(const ColumnHintGroup &other) const;
    HintList operator[](ColumnIndex columnIndex) const;

  public:
    size_t size() const;
    RowLength getMaxHintListLength() const;
};


} // namespace VersaNo::Core


#endif // VERSANO_CORE_COLUMNHINTSETLIST_H
