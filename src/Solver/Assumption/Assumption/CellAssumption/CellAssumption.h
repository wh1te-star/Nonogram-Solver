#ifndef CELLASSUMPTION_H
#define CELLASSUMPTION_H

#include "Board/NonogramBoard/NonogramBoard.h"
#include "Solver/Assumption/Assumption/IAssumption.h"

class CellAssumption : public IAssumption {
private:
    CellPosition coordinate;
    Cell cell;

public:
    explicit CellAssumption(const CellPosition& coordinate, const Cell& cell);
    virtual ~CellAssumption() = default;
    void applyTo(NonogramBoard& board) const override;
};

#endif