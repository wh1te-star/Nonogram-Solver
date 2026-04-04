#ifndef HINTPOSITION_H
#define HINTPOSITION_H

#include "Board/BoardLength/ColumnLength.h"
#include "Board/BoardLength/RowLength.h"
#include "Board/Orientation.h"
#include "Index/CellIndex/ColumnIndex.h"
#include "Index/CellIndex/RowIndex.h"
#include "Index/Position/IPosition.h"

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
