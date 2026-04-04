#ifndef LINEASSUMPTION_H
#define LINEASSUMPTION_H

#include "Core/Board/Orientation.h"
#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"
class NonogramBoard;

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