#ifndef RENDERINGBOARDUPDATEHANDLER_H
#define RENDERINGBOARDUPDATEHANDLER_H

#include "Board/Board/Board.h"
#include "Board/NonogramBoard/NonogramBoard.h"
#include "Index/Position/CellPosition/CellPosition.h"
#include "Index/Position/HintPosition/HintPosition.h"
#include "Index/Position/LinePosition/LinePosition.h"
#include "Shared/ISender.h"
#include "Solver/IBoardUpdateHandler.h"

class RenderingBoardUpdateHandler : public IBoardUpdateHandler {
  private:
    ISender<NonogramBoard> &nonogramBoardSender;
    NonogramBoard &nonogramBoard;

  public:
    RenderingBoardUpdateHandler(ISender<NonogramBoard> &nonogramBoardSender, NonogramBoard &nonogramBoard);

    void onUpdate() override;

    void onCellUpdate(
      const CellPosition &cellPosition,
      const Cell &targetCell,
      const Cell &beforeCell,
      const Cell &afterCell) override;

    void onLineUpdate(
      const LinePosition &linePosition,
      const Line &targetLine,
      const Line &beforeLine,
      const Line &afterLine) override;

    void onBoardUpdate(
      const Board &targetBoard, const Board &beforeBoard, const Board &afterBoard) override;
};

#endif