#ifndef IASSUMPTION_H
#define IASSUMPTION_H

#include "Board/BacktrackBoard/BacktrackBoard.h"

class IAssumption {
public:
    virtual ~IAssumption() = default;
    virtual void applyTo(BacktrackBoard& board) const = 0;
};

#endif