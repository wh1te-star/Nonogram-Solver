#ifndef TABLERENDERER_H
#define TABLERENDERER_H

#include "Algorithm/Backtrack/BacktrackStack/BacktrackStack.h"
#include "Board/Board/Board.h"
#include "Board/BacktrackBoard/BacktrackBoard.h"
#include "Board/BoardLength/ColumnLength.h"
#include "Board/BoardLength/RowLength.h"
#include "Hint/HintSetList/ColumnHintSetList.h"
#include "Hint/HintSetList/RowHintSetList.h"
#include "Index/CellIndex/ColumnIndex.h"
#include "Index/CellIndex/RowIndex.h"
#include "Placement/PlacementCountList/ColumnPlacementCountList.h"
#include "Placement/PlacementCountList/RowPlacementCountList.h"
#include "Rendering/HighlightIndexes/HighlightIndexes.h"
#include "imgui.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <string>

class TableRenderer {
private:
  enum CellType {
    BOARD_CELL,
    ROW_HINT,
    ROW_PLACEMENT_COUNT,
    ROW_BACKTRACK_STACK,
    COLUMN_HINT,
    COLUMN_PLACEMENT_COUNT,
    COLUMN_BACKTRACK_STACK,
    OUT_OF_BOARD
  };

public:
  TableRenderer();
  void render(const BacktrackBoard &backtrackBoard
              //const SharedBacktrackStack &sharedBacktrackStack,
              //const SharedHighlightIndexes &sharedHighlightIndexes
              ) const;

private:
  CellType determineCellType(RowIndex rowIndex, ColumnIndex columnIndex,
                             RowLength columnHintLength,
                             ColumnLength rowHintLength,
                             RowLength boardRowLength,
                             ColumnLength boardColumnLength,
                             RowLength columnBacktrackStackLength,
                             ColumnLength rowBacktrackStackLength) const;

  void setupCellStyle(RowIndex rowIndex, ColumnIndex columnIndex,
                      RowLength columnHintLength, ColumnLength rowHintLength,
                      Board board, CellType cellType,
                      HighlightIndexes highlightIndexes) const;

  std::string setLabel(RowIndex rowIndex, ColumnIndex columnIndex,
                       CellType cellType, RowLength columnHintLength,
                       ColumnLength rowHintLength,
                       RowHintSetList rowHintSetList,
                       ColumnHintSetList columnHintSetList,
                       RowPlacementCountList rowPlacementCountList,
                       ColumnPlacementCountList columnPlacementCountList,
                       float cell_size/*, BacktrackStack backtrackStack*/) const;


  void drawGridLine(RowIndex rowIndex, ColumnIndex columnIndex,
                    RowLength columnHintLength, ColumnLength rowHintLength,
                    RowLength columnPlacementCountLength,
                    ColumnLength rowPlacementCountLength) const;
  ImU32 getCellColorU32(RowIndex rowIndex, ColumnIndex columnIndex,
                        RowLength columnHintLength, ColumnLength rowHintLength,
                        Board board, CellType cellType,
                        //HighlightIndexes highlightIndexes,
                        bool isHovered) const;
  void drawGridLineDirect(ImDrawList *draw_list, ImVec2 p_min, ImVec2 p_max,
                          RowIndex rowIndex, ColumnIndex columnIndex,
                          RowLength columnHintLength,
                          ColumnLength rowHintLength, RowLength boardRowLength,
                          ColumnLength boardColumnLength) const;
};

#endif
