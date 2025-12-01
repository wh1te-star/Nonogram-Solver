#ifndef ROWLENGTH_H
#define ROWLENGTH_H


#include "BoardLength.h"
class RowIndex;

class RowLength : public BoardLength {
public:
    explicit RowLength(int length);

public:
    RowLength operator+(RowLength length) const;
    RowLength operator-(RowLength length) const;
    bool operator==(const RowLength& other) const;
    bool operator!=(const RowLength& other) const;
    bool operator<(const RowLength& other) const;
    bool operator<=(const RowLength& other) const;
    bool operator>(const RowLength& other) const;
    bool operator>=(const RowLength& other) const;
    bool operator<(const RowIndex& other) const;
    bool operator<=(const RowIndex& other) const;
    bool operator>(const RowIndex& other) const;
    bool operator>=(const RowIndex& other) const;
};


#endif
