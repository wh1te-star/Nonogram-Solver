#ifndef HINTASSUMPTION_H
#define HINTASSUMPTION_H

#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/Board/Orientation.h"
#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Core/Index/Position/HintPosition/HintPosition.h"
#include "Core/Hint/HintNumber/HintNumber.h"

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
