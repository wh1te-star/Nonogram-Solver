#ifndef VERSANO_CORE_RENDERINGBOARDUPDATEHANDLER_H
#define VERSANO_CORE_RENDERINGBOARDUPDATEHANDLER_H

#include "Core/Board/Board/Board.h"
#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/Position/CellPosition/CellPosition.h"
#include "Core/Position/HintPosition/HintPosition.h"
#include "Core/Position/LinePosition/LinePosition.h"
#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/NamespaceInterface/SolverInterface/IBoardUpdateHandler.h"
#include "Rendering/Shared/ISender.h"

namespace VersaNo::Rendering {

class RenderingBoardUpdateHandler : public Core::IBoardUpdateHandler {
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

    void onRowUpdate(
      Core::RowIndex rowIndex,
      const typename Core::LineTraits<Core::RowOrientation>::Line &targetLine,
      const typename Core::LineTraits<Core::RowOrientation>::Line &beforeLine,
      const typename Core::LineTraits<Core::RowOrientation>::Line &afterLine) override;

    void onColumnUpdate(
      Core::ColumnIndex columnIndex,
      const typename Core::LineTraits<Core::ColumnOrientation>::Line &targetLine,
      const typename Core::LineTraits<Core::ColumnOrientation>::Line &beforeLine,
      const typename Core::LineTraits<Core::ColumnOrientation>::Line &afterLine) override;

    void onBoardUpdate(
      const Core::Board &targetBoard,
      const Core::Board &beforeBoard,
      const Core::Board &afterBoard) override;

  private:
    template <typename TOrientation>
    void onLineUpdateInternal(
      typename Core::LineTraits<TOrientation>::Index index,
      const typename Core::LineTraits<TOrientation>::Line &targetLine,
      const typename Core::LineTraits<TOrientation>::Line &beforeLine,
      const typename Core::LineTraits<TOrientation>::Line &afterLine);

    void checkAndSendBoard();
};

} // namespace VersaNo::Rendering

#endif // VERSANO_CORE_RENDERINGBOARDUPDATEHANDLER_H