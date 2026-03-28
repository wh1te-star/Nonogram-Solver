#ifndef LINEPOSITION_H
#define LINEPOSITION_H

#include "Board/BoardLength/ColumnLength.h"
#include "Board/BoardLength/RowLength.h"
#include "Index/Position/IPosition.h"
#include "Index/CellIndex/ColumnIndex.h"
#include "Index/CellIndex/RowIndex.h"
#include "Board/Orientation.h"

class LinePosition : public IPosition {
  private:
    Orientation orientation;
    CellIndex cellIndex;

  public:
    explicit LinePosition(Orientation orientation, CellIndex index);

  public:
    const Orientation &getOrientation() const;
    const CellIndex &getCellIndex() const;

  public:
    bool operator==(const LinePosition &other) const;
    bool operator!=(const LinePosition &other) const;
};

#endif
