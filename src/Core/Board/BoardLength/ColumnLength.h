#ifndef VERSANO_CORE_COLUMNLENGTH_H
#define VERSANO_CORE_COLUMNLENGTH_H

#include "Core/Board/BoardLength/BoardLength.h"

namespace VersaNo::Core {
class ColumnIndex;
}

namespace VersaNo::Core {

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

} // namespace VersaNo::Core

#endif // VERSANO_CORE_COLUMNLENGTH_H
