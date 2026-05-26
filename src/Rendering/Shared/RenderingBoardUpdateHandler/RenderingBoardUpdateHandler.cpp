#include "Rendering/Shared/RenderingBoardUpdateHandler/RenderingBoardUpdateHandler.h"

using namespace VersaNo::Core;
using namespace VersaNo::Solver;
namespace VersaNo::Rendering {

RenderingBoardUpdateHandler::RenderingBoardUpdateHandler(
  ISender<NonogramBoard> &nonogramBoardSender, NonogramBoard &nonogramBoard)
    : nonogramBoardSender(nonogramBoardSender), nonogramBoard(nonogramBoard) {}

void RenderingBoardUpdateHandler::onCellUpdate(
  const CellPosition &cellPosition,
  const Cell &targetCell,
  const Cell &beforeCell,
  const Cell &afterCell) {
    checkAndSendBoard();
}

template <typename TOrientation>
void RenderingBoardUpdateHandler::onLineUpdate(
  typename Core::LineTraits<TOrientation>::Index index,
  const typename Core::LineTraits<TOrientation>::Line &targetLine,
  const typename Core::LineTraits<TOrientation>::Line &beforeLine,
  const typename Core::LineTraits<TOrientation>::Line &afterLine) {
    checkAndSendBoard();
}

void RenderingBoardUpdateHandler::onBoardUpdate(
  const Board &targetBoard, const Board &beforeBoard, const Board &afterBoard) {
    checkAndSendBoard();
}

void RenderingBoardUpdateHandler::checkAndSendBoard() {
    if (nonogramBoardSender.isRequested()) {
        nonogramBoardSender.send(nonogramBoard);
    }
}

// Explicit template instantiations for RowOrientation and ColumnOrientation.
// This is for separating the declaration and definition,
// and is enabled by the fact that TOrientation can be RowOrientation or ColumnOrientation.
template void RenderingBoardUpdateHandler::onLineUpdate<RowOrientation>(
    RowIndex, 
    const LineTraits<RowOrientation>::Line&, 
    const LineTraits<RowOrientation>::Line&, 
    const LineTraits<RowOrientation>::Line&);

template void RenderingBoardUpdateHandler::onLineUpdate<ColumnOrientation>(
    ColumnIndex, 
    const LineTraits<ColumnOrientation>::Line&, 
    const LineTraits<ColumnOrientation>::Line&, 
    const LineTraits<ColumnOrientation>::Line&);

} // namespace VersaNo::Rendering