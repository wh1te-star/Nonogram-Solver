#include "Rendering/Shared/RenderingBoardUpdateHandler/RenderingBoardUpdateHandler.h"

using namespace VersaNo::Core;
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

void RenderingBoardUpdateHandler::onRowUpdate(
  RowIndex rowIndex,
  const typename LineTraits<RowOrientation>::Line &targetLine,
  const typename LineTraits<RowOrientation>::Line &beforeLine,
  const typename LineTraits<RowOrientation>::Line &afterLine) {
    onLineUpdateInternal<RowOrientation>(rowIndex, targetLine, beforeLine, afterLine);
}

void RenderingBoardUpdateHandler::onColumnUpdate(
  ColumnIndex columnIndex,
  const typename LineTraits<ColumnOrientation>::Line &targetLine,
  const typename LineTraits<ColumnOrientation>::Line &beforeLine,
  const typename LineTraits<ColumnOrientation>::Line &afterLine) {
    onLineUpdateInternal<ColumnOrientation>(columnIndex, targetLine, beforeLine, afterLine);
}

void RenderingBoardUpdateHandler::onBoardUpdate(
  const IBoard &targetBoard, const IBoard &beforeBoard, const IBoard &afterBoard) {
    checkAndSendBoard();
}

template <typename TOrientation>
void RenderingBoardUpdateHandler::onLineUpdateInternal(
  typename LineTraits<TOrientation>::Index index,
  const typename LineTraits<TOrientation>::Line &targetLine,
  const typename LineTraits<TOrientation>::Line &beforeLine,
  const typename LineTraits<TOrientation>::Line &afterLine) {
    checkAndSendBoard();
}

void RenderingBoardUpdateHandler::checkAndSendBoard() {
    if (nonogramBoardSender.isRequested()) {
        nonogramBoardSender.send(nonogramBoard);
    }
}

// Explicit instantiations
template void RenderingBoardUpdateHandler::onLineUpdateInternal<RowOrientation>(
  RowIndex,
  const LineTraits<RowOrientation>::Line &,
  const LineTraits<RowOrientation>::Line &,
  const LineTraits<RowOrientation>::Line &);

template void RenderingBoardUpdateHandler::onLineUpdateInternal<ColumnOrientation>(
  ColumnIndex,
  const LineTraits<ColumnOrientation>::Line &,
  const LineTraits<ColumnOrientation>::Line &,
  const LineTraits<ColumnOrientation>::Line &);

} // namespace VersaNo::Rendering