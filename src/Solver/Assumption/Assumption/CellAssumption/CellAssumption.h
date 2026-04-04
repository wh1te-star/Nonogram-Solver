#ifndef CELLASSUMPTION_H
#define CELLASSUMPTION_H

#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Solver/Assumption/Assumption/IAssumption.h"

class CellAssumption : public IAssumption {
private:
    CellPosition cellPosition;
    Cell cell;

public:
    explicit CellAssumption(const CellPosition& cellPosition, const Cell& cell);
    virtual ~CellAssumption() = default;

    void applyTo(NonogramBoard& board) const override;
};

#endif