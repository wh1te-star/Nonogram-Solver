#ifndef IBOARDUPDATEHANDLER_H
#define IBOARDUPDATEHANDLER_H

#include "Board/Board/Board.h"

class IBoardUpdateHandler {
  public:
    virtual ~IBoardUpdateHandler() = default;
    virtual void onCellUpdate(const Board& board) = 0;
    virtual void onLineUpdate(const Board& board) = 0;
    virtual void onBoardUpdate(const Board& board) = 0;
};

#endif