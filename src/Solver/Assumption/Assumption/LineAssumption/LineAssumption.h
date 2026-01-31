#ifndef LINEASSUMPTION_H
#define LINEASSUMPTION_H

#include "Board/BacktrackBoard/BacktrackBoard.h"
#include "Board/Orientation.h"
#include "Solver/Assumption/Assumption/IAssumption.h"
class RowIndex;
class ColumnIndex;

class LineAssumption : public IAssumption {
private:
    Orientation orientation;
    CellIndex index;
    Line line;

public:
    explicit LineAssumption(const RowIndex& index, const Line& line);
    explicit LineAssumption(const ColumnIndex& index, const Line& line);

    virtual ~LineAssumption() = default;
    void applyTo(BacktrackBoard &board) const override;
};

#endif