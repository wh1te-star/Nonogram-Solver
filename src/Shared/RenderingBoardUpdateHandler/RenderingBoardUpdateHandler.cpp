#include "Shared/RenderingBoardUpdateHandler/RenderingBoardUpdateHandler.h"

RenderingBoardUpdateHandler::RenderingBoardUpdateHandler(
  ISender<NonogramBoard> &nonogramBoardSender, NonogramBoard &nonogramBoard)
    : nonogramBoardSender(nonogramBoardSender), nonogramBoard(nonogramBoard) {}

void RenderingBoardUpdateHandler::onUpdate() {
    if (nonogramBoardSender.isRequested()) {
        nonogramBoardSender.send(nonogramBoard);
    }
}

void RenderingBoardUpdateHandler::onCellUpdate(
  const CellPosition &cellPosition,
  const Cell &targetCell,
  const Cell &beforeCell,
  const Cell &afterCell) {
    onUpdate();
  }

void RenderingBoardUpdateHandler::onLineUpdate(
  const LinePosition &linePosition,
  const Line &targetLine,
  const Line &beforeLine,
  const Line &afterLine) {
    onUpdate();
  }

void RenderingBoardUpdateHandler::onBoardUpdate(
  const Board &targetBoard, const Board &beforeBoard, const Board &afterBoard) {
    onUpdate();
  }