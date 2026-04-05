#ifndef VERSANO_CORE_ROWINDEX_H
#define VERSANO_CORE_ROWINDEX_H

#include "Core/Index/CellIndex/CellIndex.h"

namespace VersaNo::Core {
class RowLength;
}

namespace VersaNo::Core {

class RowIndex : public CellIndex {
  public:
    explicit RowIndex(int index);

  public:
    RowIndex operator+(int shift) const;
    RowIndex operator-(int shift) const;
    RowIndex operator+(RowLength shift) const;
    RowIndex operator-(RowLength shift) const;
    RowIndex operator+(HintNumber shift) const;
    RowIndex operator-(HintNumber shift) const;
    bool operator==(const RowIndex &other) const;
    bool operator!=(const RowIndex &other) const;
    bool operator<(const RowIndex &other) const;
    bool operator<=(const RowIndex &other) const;
    bool operator>(const RowIndex &other) const;
    bool operator>=(const RowIndex &other) const;
    bool operator<(const RowLength &other) const;
    bool operator<=(const RowLength &other) const;
    bool operator>(const RowLength &other) const;
    bool operator>=(const RowLength &other) const;
    static std::vector<RowIndex> range(int first, int last);
};

} // namespace VersaNo::Core

namespace std {
template <> struct hash<VersaNo::Core::RowIndex> {
    size_t operator()(const VersaNo::Core::RowIndex &rowIndex) const {
        return std::hash<int>{}(rowIndex.getIndex());
    }
};
} // namespace std

#endif // VERSANO_CORE_ROWINDEX_H
