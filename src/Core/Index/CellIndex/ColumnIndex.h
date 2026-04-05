#ifndef VERSAN_CORE_COLUMNINDEX_H
#define VERSAN_CORE_COLUMNINDEX_H

#include "Core/Index/CellIndex/CellIndex.h"

namespace VersaNo::Core {
class ColumnLength;
}

namespace VersaNo::Core {

class ColumnIndex : public CellIndex {
  public:
    explicit ColumnIndex(int index);

  public:
    ColumnIndex operator+(int shift) const;
    ColumnIndex operator-(int shift) const;
    ColumnIndex operator+(ColumnLength shift) const;
    ColumnIndex operator-(ColumnLength shift) const;
    ColumnIndex operator+(HintNumber shift) const;
    ColumnIndex operator-(HintNumber shift) const;
    bool operator==(const ColumnIndex &other) const;
    bool operator!=(const ColumnIndex &other) const;
    bool operator<(const ColumnIndex &other) const;
    bool operator<=(const ColumnIndex &other) const;
    bool operator>(const ColumnIndex &other) const;
    bool operator>=(const ColumnIndex &other) const;
    bool operator<(const ColumnLength &other) const;
    bool operator<=(const ColumnLength &other) const;
    bool operator>(const ColumnLength &other) const;
    bool operator>=(const ColumnLength &other) const;
    static std::vector<ColumnIndex> range(int first, int last);
};
} // namespace VersaNo::Core

namespace std {
template <> struct hash<VersaNo::Core::ColumnIndex> {
    size_t operator()(const VersaNo::Core::ColumnIndex &columnIndex) const {
        return std::hash<int>{}(columnIndex.getIndex());
    }
};
} // namespace std

#endif // VERSAN_CORE_COLUMNINDEX_H
