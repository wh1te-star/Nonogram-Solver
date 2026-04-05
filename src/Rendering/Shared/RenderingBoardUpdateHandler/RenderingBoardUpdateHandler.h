#ifndef VERSANO_CORE_RENDERINGBOARDUPDATEHANDLER_H
#define VERSANO_CORE_RENDERINGBOARDUPDATEHANDLER_H

#include "Core/Board/Board/Board.h"
#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/Index/Position/CellPosition/CellPosition.h"
#include "Core/Index/Position/HintPosition/HintPosition.h"
#include "Core/Index/Position/LinePosition/LinePosition.h"
#include "Rendering/Shared/ISender.h"
#include "Solver/IBoardUpdateHandler.h"

namespace VersaNo::Rendering {

class RenderingBoardUpdateHandler : public Solver::IBoardUpdateHandler {
  private:
    ISender<Core::NonogramBoard> &nonogramBoardSender;
    Core::NonogramBoard &nonogramBoard;

  public:
    RenderingBoardUpdateHandler(
      ISender<Core::NonogramBoard> &nonogramBoardSender, Core::NonogramBoard &nonogramBoard);

    void onCellUpdate(
      const Core::CellPosition &cellPosition,
      const Core::Cell &targetCell,
      const Core::Cell &beforeCell,
      const Core::Cell &afterCell) override;

    void onLineUpdate(
      const Core::LinePosition &linePosition,
      const Core::Line &targetLine,
      const Core::Line &beforeLine,
      const Core::Line &afterLine) override;

    void onBoardUpdate(
      const Core::Board &targetBoard,
      const Core::Board &beforeBoard,
      const Core::Board &afterBoard) override;

  private:
    void checkAndSendBoard();
};

} // namespace VersaNo::Rendering

#endif // VERSANO_CORE_RENDERINGBOARDUPDATEHANDLER_H