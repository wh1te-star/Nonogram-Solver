#ifndef VERSANO_CORE_IBOARDUPDATEHANDLER_H
#define VERSANO_CORE_IBOARDUPDATEHANDLER_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Board/Board/Board.h"
#include "Core/Position/CellPosition/CellPosition.h"
#include "Core/Position/HintPosition/HintPosition.h"
#include "Core/Position/LinePosition/LinePosition.h"

namespace VersaNo::Solver {

class IBoardUpdateHandler {
  public:
    virtual ~IBoardUpdateHandler() = default;

    virtual void onCellUpdate(
      const Core::CellPosition &cellPosition,
      const Core::Cell &targetCell,
      const Core::Cell &beforeCell,
      const Core::Cell &afterCell) = 0;

    virtual void onLineUpdate(
      const Core::LinePosition &linePosition,
      const Core::Line &targetLine,
      const Core::Line &beforeLine,
      const Core::Line &afterLine) = 0;

    virtual void onBoardUpdate(
      const Core::Board &targetBoard,
      const Core::Board &beforeBoard,
      const Core::Board &afterBoard) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_IBOARDUPDATEHANDLER_H