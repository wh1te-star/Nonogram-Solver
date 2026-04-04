#ifndef HINTASSUMPTION_H
#define HINTASSUMPTION_H

#include "Board/NonogramBoard/NonogramBoard.h"
#include "Board/Orientation.h"
#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Index/Position/HintPosition/HintPosition.h"
#include "Hint/HintNumber/HintNumber.h"

class HintAssumption : public IAssumption {
  private:
    HintPosition hintPosition;
    HintNumber hintNumber;

  public:
    explicit HintAssumption(const HintPosition &hintPosition, const HintNumber &hintNumber);
    virtual ~HintAssumption() = default;

    void applyTo(NonogramBoard &board) const override;
};

#endif
