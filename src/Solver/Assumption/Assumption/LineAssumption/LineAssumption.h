#ifndef LINEASSUMPTION_H
#define LINEASSUMPTION_H

#include "Board/NonogramBoard/NonogramBoard.h"
#include "Board/Orientation.h"
#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"
class RowIndex;
class ColumnIndex;

class LineAssumption : public IAssumption {
  private:
    LinePosition linePosition;
    Line line;

  public:
    explicit LineAssumption(const LinePosition &linePosition, const Line &line);

    virtual ~LineAssumption() = default;
    void applyTo(NonogramBoard &board) const override;
};

#endif