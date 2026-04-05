#ifndef VERSAN_CORE_TABLERENDERER_H
#define VERSAN_CORE_TABLERENDERER_H

#include "Core/Board/Board/Board.h"
#include "Core/Board/BoardLength/ColumnLength.h"
#include "Core/Board/BoardLength/RowLength.h"
#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/Hint/HintSetList/ColumnHintSetList.h"
#include "Core/Hint/HintSetList/RowHintSetList.h"
#include "Core/Index/CellIndex/ColumnIndex.h"
#include "Core/Index/CellIndex/RowIndex.h"
#include "Core/Placement/PlacementCountList/ColumnPlacementCountList.h"
#include "Core/Placement/PlacementCountList/RowPlacementCountList.h"
#include "Rendering/HighlightIndexes/HighlightIndexes.h"
#include "imgui.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <string>

namespace VersaNo::Rendering {

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
    void render(
      const Core::NonogramBoard &nonogramBoard
      // const SharedBacktrackStack &sharedBacktrackStack,
      // const SharedHighlightIndexes &sharedHighlightIndexes
    ) const;

  private:
    CellType determineCellType(
      Core::RowIndex rowIndex,
      Core::ColumnIndex columnIndex,
      Core::RowLength columnHintLength,
      Core::ColumnLength rowHintLength,
      Core::RowLength boardRowLength,
      Core::ColumnLength boardColumnLength,
      Core::RowLength columnBacktrackStackLength,
      Core::ColumnLength rowBacktrackStackLength) const;

    void setupCellStyle(
      Core::RowIndex rowIndex,
      Core::ColumnIndex columnIndex,
      Core::RowLength columnHintLength,
      Core::ColumnLength rowHintLength,
      Core::Board board,
      CellType cellType,
      Rendering::HighlightIndexes highlightIndexes) const;

    std::string setLabel(
      Core::RowIndex rowIndex,
      Core::ColumnIndex columnIndex,
      CellType cellType,
      Core::RowLength columnHintLength,
      Core::ColumnLength rowHintLength,
      Core::RowHintSetList rowHintSetList,
      Core::ColumnHintSetList columnHintSetList,
      Core::RowPlacementCountList rowPlacementCountList,
      Core::ColumnPlacementCountList columnPlacementCountList,
      float cell_size /*, BacktrackStack backtrackStack*/) const;

    void drawGridLine(
      Core::RowIndex rowIndex,
      Core::ColumnIndex columnIndex,
      Core::RowLength columnHintLength,
      Core::ColumnLength rowHintLength,
      Core::RowLength columnPlacementCountLength,
      Core::ColumnLength rowPlacementCountLength) const;

    ImU32 getCellColorU32(
      Core::RowIndex rowIndex,
      Core::ColumnIndex columnIndex,
      Core::RowLength columnHintLength,
      Core::ColumnLength rowHintLength,
      Core::Board board,
      CellType cellType,
      // Core::HighlightIndexes highlightIndexes,
      bool isHovered) const;

    void drawGridLineDirect(
      ImDrawList *draw_list,
      ImVec2 p_min,
      ImVec2 p_max,
      Core::RowIndex rowIndex,
      Core::ColumnIndex columnIndex,
      Core::RowLength columnHintLength,
      Core::ColumnLength rowHintLength,
      Core::RowLength boardRowLength,
      Core::ColumnLength boardColumnLength) const;
};

} // namespace VersaNo::Rendering

#endif // VERSAN_CORE_TABLERENDERER_H
