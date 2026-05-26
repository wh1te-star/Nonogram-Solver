#ifndef VERSANO_CORE_RENDERINGBOARDUPDATEHANDLER_H
#define VERSANO_CORE_RENDERINGBOARDUPDATEHANDLER_H

#include "Core/Board/Board/Board.h"
#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/Position/CellPosition/CellPosition.h"
#include "Core/Position/HintPosition/HintPosition.h"
#include "Core/Position/LinePosition/LinePosition.h"
#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/NamespaceInterface/SolverInterface/BoardUpdateHandlerBase.h"
#include "Rendering/Shared/ISender.h"

namespace VersaNo::Rendering {

class RenderingBoardUpdateHandler : public Solver::BoardUpdateHandler<RenderingBoardUpdateHandler> {
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


    template <typename TOrientation>
    void onLineUpdate(
      typename Core::LineTraits<TOrientation>::Index index,
      const typename Core::LineTraits<TOrientation>::Line &targetLine,
      const typename Core::LineTraits<TOrientation>::Line &beforeLine,
      const typename Core::LineTraits<TOrientation>::Line &afterLine);


    void onBoardUpdate(
      const Core::Board &targetBoard,
      const Core::Board &beforeBoard,
      const Core::Board &afterBoard) override;


  private:
    void checkAndSendBoard();
};

} // namespace VersaNo::Rendering

#endif // VERSANO_CORE_RENDERINGBOARDUPDATEHANDLER_H