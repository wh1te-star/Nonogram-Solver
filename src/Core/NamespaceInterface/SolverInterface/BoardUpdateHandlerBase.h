#ifndef VERSANO_SOLVER_BOARDUPDATEHANDLER_H
#define VERSANO_SOLVER_BOARDUPDATEHANDLER_H

#include "Core/NamespaceInterface/SolverInterface/IBoardUpdateHandler.h"

namespace VersaNo::Solver {

template <typename Derived>
class BoardUpdateHandler : public IBoardUpdateHandler {
public:
    virtual ~BoardUpdateHandler() = default;

    void onRowUpdate(
        Core::RowIndex rowIndex,
        const typename Core::LineTraits<Core::RowOrientation>::Line &targetLine,
        const typename Core::LineTraits<Core::RowOrientation>::Line &beforeLine,
        const typename Core::LineTraits<Core::RowOrientation>::Line &afterLine) override {
        
        static_cast<Derived*>(this)->template onLineUpdate<Core::RowOrientation>(
            rowIndex, targetLine, beforeLine, afterLine);
    }

    void onColumnUpdate(
        Core::ColumnIndex columnIndex,
        const typename Core::LineTraits<Core::ColumnOrientation>::Line &targetLine,
        const typename Core::LineTraits<Core::ColumnOrientation>::Line &beforeLine,
        const typename Core::LineTraits<Core::ColumnOrientation>::Line &afterLine) override {
        
        static_cast<Derived*>(this)->template onLineUpdate<Core::ColumnOrientation>(
            columnIndex, targetLine, beforeLine, afterLine);
    }
};

} // namespace VersaNo::Solver

#endif // VERSANO_SOLVER_BOARDUPDATEHANDLER_H