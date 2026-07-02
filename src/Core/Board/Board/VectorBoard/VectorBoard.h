#ifndef VERSANO_CORE_BOARD_H
#define VERSANO_CORE_BOARD_H

#include "Core/Board/Board/IBoard.h"
#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Cell/CellColor/CellColor.h"
#include "Core/Cell/CellVector2D/CellVector2D.h"
#include "Core/Position/CellPosition/CellPosition.h"
#include "Core/Position/LinePosition/LinePosition.h"
#include "Core/Position/HintPosition/HintPosition.h"
#include <vector>

namespace VersaNo::Core {

class Board : public IBoard {
  private:
    RowLength rowLength;
    ColumnLength columnLength;
    CellVector2D board;

  public:
    Board(RowLength rowLength, ColumnLength columnLength);

    bool operator==(const Board &other) const;
    bool operator!=(const Board &other) const;

    template <typename TOrientation> typename LineTraits<TOrientation>::Length getLength() const;
    Cell getCell(CellPosition coordinate) const;

  public:
    template <typename TOrientation>
    typename LineTraits<TOrientation>::Line getLine(typename LineTraits<TOrientation>::Index index) const;

    void applyCell(CellPosition coordinate, const Cell &cell, bool overrideNone = false);

    template <typename TOrientation>
    void applyLine(typename LinePosition<TOrientation> linePosition, 
                   const typename LineTraits<TOrientation>::Line &line, 
                   bool overwriteNone);
    template <typename TOrientation>
    void applyPlacement(typename LinePosition<TOrientation> linePosition, 
                        const typename LineTraits<TOrientation>::Placement &placement);

    template <typename TOrientation>
    void applyHint(typename HintPosition<TOrientation> hintPosition, 
                   HintNumber hintNumber);

    void applyBoard(const Board &board, bool overwriteNone);

  public:
    bool isInRange(CellPosition coordinate) const;
    bool isSolved() const;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_BOARD_H