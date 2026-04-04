#ifndef HINTPOSITION_H
#define HINTPOSITION_H

#include "Core/Board/BoardLength/ColumnLength.h"
#include "Core/Board/BoardLength/RowLength.h"
#include "Core/Board/Orientation.h"
#include "Core/Index/CellIndex/ColumnIndex.h"
#include "Core/Index/CellIndex/RowIndex.h"
#include "Core/Index/Position/IPosition.h"

class HintPosition : public IPosition {
  private:
    Orientation orientation;
    CellIndex cellIndex;
    int hintIndex;

  public:
    explicit HintPosition(Orientation orientation, CellIndex cellIndex, int hintIndex);

  public:
    const Orientation &getOrientation() const;
    const CellIndex &getCellIndex() const;
    int getHintIndex() const;

  public:
    bool operator==(const HintPosition &other) const;
    bool operator!=(const HintPosition &other) const;
};

#endif
