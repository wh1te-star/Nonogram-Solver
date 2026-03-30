#ifndef IBOARDUPDATEHANDLER_H
#define IBOARDUPDATEHANDLER_H

#include "Board/Board/Board.h"
#include "Index/Position/CellPosition/CellPosition.h"
#include "Index/Position/HintPosition/HintPosition.h"
#include "Index/Position/LinePosition/LinePosition.h"

class IBoardUpdateHandler {
  public:
    virtual ~IBoardUpdateHandler() = default;

    virtual void onUpdate() = 0;

    virtual void onCellUpdate(
      const CellPosition &cellPosition,
      const Cell &targetCell,
      const Cell &beforeCell,
      const Cell &afterCell) = 0;

    virtual void onLineUpdate(
      const LinePosition &linePosition,
      const Line &targetLine,
      const Line &beforeLine,
      const Line &afterLine) = 0;

    virtual void
    onBoardUpdate(const Board &targetBoard, const Board &beforeBoard, const Board &afterBoard) = 0;
};

#endif