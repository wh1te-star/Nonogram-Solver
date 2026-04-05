#ifndef VERSAN_CORE_ROWLENGTH_H
#define VERSAN_CORE_ROWLENGTH_H

#include "Core/Board/BoardLength/BoardLength.h"

namespace VersaN::Core {
class RowIndex;
}

namespace VersaN::Core {

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

} // namespace VersaN::Core

#endif // VERSAN_CORE_ROWLENGTH_H