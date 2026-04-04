#include "Rendering/Shared/RenderingBoardUpdateHandler/RenderingBoardUpdateHandler.h"

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

void RenderingBoardUpdateHandler::onLineUpdate(
  const LinePosition &linePosition,
  const Line &targetLine,
  const Line &beforeLine,
  const Line &afterLine) {
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