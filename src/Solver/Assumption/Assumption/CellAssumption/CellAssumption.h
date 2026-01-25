#ifndef CELLASSUMPTION_H
#define CELLASSUMPTION_H

#include "Board/BacktrackBoard/BacktrackBoard.h"

class CellAssumption {
private:
    Coordinate coordinate;
    Cell cell;

public:
    explicit CellAssumption(const Coordinate& coordinate, const Cell& cell);
    virtual ~CellAssumption() = default;
    virtual void applyTo(BacktrackBoard& board) const = 0;
};

#endif