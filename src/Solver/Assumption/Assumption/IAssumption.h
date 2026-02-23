#ifndef IASSUMPTION_H
#define IASSUMPTION_H

#include "Board/NonogramBoard/NonogramBoard.h"

class IAssumption {
public:
    virtual ~IAssumption() = default;
    virtual void applyTo(NonogramBoard& board) const = 0;
};

#endif