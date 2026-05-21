#ifndef VERSANO_CORE_BOARD_H
#define VERSANO_CORE_BOARD_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Cell/CellColor/CellColor.h"
#include "Core/Cell/CellVector2D/CellVector2D.h"
#include "Core/Position/CellPosition/CellPosition.h"
#include <vector>

namespace VersaNo::Core {

class Board {
  private:
    RowLength rowLength;
    ColumnLength columnLength;
    CellVector2D board;

  public:
    Board(RowLength rowLength, ColumnLength columnLength);

    bool operator==(const Board &other) const;
    bool operator!=(const Board &other) const;

    RowLength getRowLength() const;
    ColumnLength getColumnLength() const;
    Cell getCell(CellPosition coordinate) const;

  public:
    template <typename TOrientation>
    typename LineTraits<TOrientation>::Line getLine(typename LineTraits<TOrientation>::Index index) const;

    void applyCell(CellPosition coordinate, const Cell &cell, bool overrideNone = false);

    template <typename TOrientation>
    void applyLine(typename LineTraits<TOrientation>::Index index, 
                   const typename LineTraits<TOrientation>::Line &line, 
                   bool overwriteNone);
    template <typename TOrientation>
    void applyPlacement(typename LineTraits<TOrientation>::Index index, 
                        const typename LineTraits<TOrientation>::Placement &placement);

    void applyBoard(const Board &board, bool overwriteNone);

  public:
    bool isInRange(CellPosition coordinate) const;
    bool isSolved() const;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_BOARD_H