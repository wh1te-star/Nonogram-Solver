#ifndef HINTASSUMPTION_H
#define HINTASSUMPTION_H

#include "Board/NonogramBoard/NonogramBoard.h"
#include "Board/Orientation.h"
#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Index/Position/HintPosition/HintPosition.h"

class HintAssumption : public IAssumption {
  private:
    HintPosition hintPosition;
    Line line;

  public:
    explicit HintAssumption(const HintPosition &hintPosition, const Line &line);

    virtual ~HintAssumption() = default;
    void applyTo(NonogramBoard &board) const override;
};

#endif
