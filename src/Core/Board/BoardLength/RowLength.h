#ifndef VERSANO_CORE_ROWLENGTH_H
#define VERSANO_CORE_ROWLENGTH_H

#include "Core/Board/BoardLength/BoardLength.h"

namespace VersaNo::Core {
class RowIndex;
}

namespace VersaNo::Core {

class RowLength : public BoardLength {
  public:
    explicit RowLength(int length);

  public:
    RowLength operator+(RowLength length) const;
    RowLength operator-(RowLength length) const;
    bool operator==(const RowLength &other) const;
    bool operator!=(const RowLength &other) const;
    bool operator<(const RowLength &other) const;
    bool operator<=(const RowLength &other) const;
    bool operator>(const RowLength &other) const;
    bool operator>=(const RowLength &other) const;
    bool operator<(const RowIndex &other) const;
    bool operator<=(const RowIndex &other) const;
    bool operator>(const RowIndex &other) const;
    bool operator>=(const RowIndex &other) const;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_ROWLENGTH_H