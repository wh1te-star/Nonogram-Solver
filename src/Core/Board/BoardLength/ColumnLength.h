#ifndef VERSAN_CORE_COLUMNLENGTH_H
#define VERSAN_CORE_COLUMNLENGTH_H

#include "Core/Board/BoardLength/BoardLength.h"

namespace VersaN::Core {
class ColumnIndex;
}

namespace VersaN::Core {

class ColumnLength : public BoardLength {
  public:
    explicit ColumnLength(int length);

  public:
    ColumnLength operator+(ColumnLength length) const;
    ColumnLength operator-(ColumnLength length) const;
    bool operator==(const ColumnLength &other) const;
    bool operator!=(const ColumnLength &other) const;
    bool operator<(const ColumnLength &other) const;
    bool operator<=(const ColumnLength &other) const;
    bool operator>(const ColumnLength &other) const;
    bool operator>=(const ColumnLength &other) const;
    bool operator<(const ColumnIndex &other) const;
    bool operator<=(const ColumnIndex &other) const;
    bool operator>(const ColumnIndex &other) const;
    bool operator>=(const ColumnIndex &other) const;
};

} // namespace VersaN::Core

#endif // VERSAN_CORE_COLUMNLENGTH_H
