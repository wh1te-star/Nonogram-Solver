#ifndef VERSANO_SOLVER_IBOARDUPDATEHANDLER_H
#define VERSANO_SOLVER_IBOARDUPDATEHANDLER_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Board/Board/IBoard.h"
#include "Core/Position/CellPosition/CellPosition.h"

namespace VersaNo::Core {

class IBoardUpdateHandler {
public:
    virtual ~IBoardUpdateHandler() = default;

    virtual void onCellUpdate(
        const Core::CellPosition &cellPosition,
        const Core::Cell &targetCell,
        const Core::Cell &beforeCell,
        const Core::Cell &afterCell) = 0;

    virtual void onRowUpdate(
        Core::RowIndex rowIndex,
        const typename Core::LineTraits<Core::RowOrientation>::Line &targetLine,
        const typename Core::LineTraits<Core::RowOrientation>::Line &beforeLine,
        const typename Core::LineTraits<Core::RowOrientation>::Line &afterLine) = 0;

    virtual void onColumnUpdate(
        Core::ColumnIndex columnIndex,
        const typename Core::LineTraits<Core::ColumnOrientation>::Line &targetLine,
        const typename Core::LineTraits<Core::ColumnOrientation>::Line &beforeLine,
        const typename Core::LineTraits<Core::ColumnOrientation>::Line &afterLine) = 0;

    virtual void onBoardUpdate(
        const Core::IBoard &targetBoard,
        const Core::IBoard &beforeBoard,
        const Core::IBoard &afterBoard) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_SOLVER_IBOARDUPDATEHANDLER_H