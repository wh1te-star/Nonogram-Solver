#include "Rendering/TableRenderer/TableRenderer.h"

#include "Algorithm/Backtrack/BacktrackStack/BacktrackStack.h"
#include "Board/BacktrackBoard/BacktrackBoard.h"
#include "Board/BoardLength/ColumnLength.h"
#include "Board/BoardLength/RowLength.h"
#include "Index/CellIndex/ColumnIndex.h"
#include "Index/CellIndex/RowIndex.h"
#include "Rendering/FontData/FontData.h"
#include "Shared/SharedBacktrackStack/SharedBacktrackStack.h"
#include "Shared/SharedHighlightIndexes/SharedHighlightIndexes.h"
#include "imgui.h"
#include "imgui_internal.h"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <string>

TableRenderer::TableRenderer() {}

void TableRenderer::render(
    const BacktrackBoard &backtrackBoard
    // const SharedBacktrackStack &sharedBacktrackStack,
    // const SharedHighlightIndexes &sharedHighlightIndexes
) const {
  auto start_total = std::chrono::high_resolution_clock::now();
  auto start_data_copy = std::chrono::high_resolution_clock::now();

  ImGui::Begin("Nonogram Board", NULL, ImGuiWindowFlags_None);

  // --- Data Retrieval (Same as before) ---
  // const HighlightIndexes highlightIndexes =
  // sharedHighlightIndexes.getHighlightIndexes(); const BacktrackStack
  // backtrackStack = sharedBacktrackStack.getBacktrackStack();
  const Board board = backtrackBoard.getBoard();
  const RowHintSetList rowHintSetList = backtrackBoard.getRowHintSetList();
  const ColumnHintSetList columnHintSetList =
      backtrackBoard.getColumnHintSetList();
  const RowPlacementCountList rowPlacementCountList =
      backtrackBoard.getRowPlacementCountList();
  const ColumnPlacementCountList columnPlacementCountList =
      backtrackBoard.getColumnPlacementCountList();

  auto end_data_copy = std::chrono::high_resolution_clock::now();

  // --- Length Calculations (Same as before) ---
  const RowLength boardRowLength = board.getRowLength();
  const ColumnLength boardColumnLength = board.getColumnLength();
  const RowLength columnHintLength = columnHintSetList.getMaxHintSetLength();
  const ColumnLength rowHintLength = rowHintSetList.getMaxHintSetLength();
  const RowLength columnPlacementCountLength = RowLength(1);
  const ColumnLength rowPlacementCountLength = ColumnLength(1);
  const RowLength columnBacktrackStackLength = RowLength(1);
  const ColumnLength rowBacktrackStackLength = ColumnLength(1);

  const RowLength totalRowLength = columnHintLength + boardRowLength +
                                   columnPlacementCountLength +
                                   columnBacktrackStackLength;
  const ColumnLength totalColumnLength = rowHintLength + boardColumnLength +
                                         rowPlacementCountLength +
                                         rowBacktrackStackLength;

  // --- Layout Calculation ---
  ImVec2 container_size = ImGui::GetContentRegionAvail();

  // Determine cell size
  float min_container_dim =
      ImMin(container_size.x / totalColumnLength.getLength(),
            container_size.y / totalRowLength.getLength());
  float cell_size = round(min_container_dim);
  if (cell_size < 1.0f)
    cell_size = 1.0f;

  float table_width = cell_size * totalColumnLength.getLength();
  float table_height = cell_size * totalRowLength.getLength();

  // --- Centering Logic (Fixed) ---
  // Instead of moving cursor screen pos manually and risking bounds error,
  // we calculate the offset relative to the current cursor window position.
  float offset_x = (container_size.x - table_width) * 0.5f;
  float offset_y = (container_size.y - table_height) * 0.5f;

  // Move the cursor to the start position of the table within the window
  ImGui::SetCursorPos(
      ImVec2(ImGui::GetCursorPosX() + (offset_x > 0 ? offset_x : 0),
             ImGui::GetCursorPosY() + (offset_y > 0 ? offset_y : 0)));

  // [CRITICAL FIX]
  // Reserve space for the table using a Dummy item.
  // This tells ImGui "there is an item here of this size", preventing the
  // assertion error. It also automatically advances the cursor to the end of
  // the table.
  ImGui::Dummy(ImVec2(table_width, table_height));

  // Get the screen coordinates of the Dummy we just drew.
  // We will draw our custom grid on top of this reserved space.
  ImVec2 table_start_screen_pos = ImGui::GetItemRectMin();

  // Prepare for Drawing
  ImDrawList *draw_list = ImGui::GetWindowDrawList();
  ImFont *font = FontData::getFontByCellSize(cell_size);

  // Mouse Interaction Variables
  ImVec2 mousePos = ImGui::GetMousePos();
  bool isWindowHovered = ImGui::IsWindowHovered();

  auto start_draw_loop = std::chrono::high_resolution_clock::now();

  // --- Main Rendering Loop ---
  for (int r = 0; r < totalRowLength.getLength(); ++r) {
    for (int c = 0; c < totalColumnLength.getLength(); ++c) {

      RowIndex rowIndex = RowIndex(r);
      ColumnIndex columnIndex = ColumnIndex(c);

      // Calculate absolute screen coordinates based on the Dummy's position
      ImVec2 p_min = ImVec2(table_start_screen_pos.x + c * cell_size,
                            table_start_screen_pos.y + r * cell_size);
      ImVec2 p_max = ImVec2(p_min.x + cell_size, p_min.y + cell_size);

      // Check for Hover
      bool isHovered = false;
      if (isWindowHovered) {
        if (mousePos.x >= p_min.x && mousePos.x < p_max.x &&
            mousePos.y >= p_min.y && mousePos.y < p_max.y) {
          isHovered = true;
        }
      }

      // 1. Determine Cell Type
      CellType cellType = determineCellType(
          rowIndex, columnIndex, columnHintLength, rowHintLength,
          boardRowLength, boardColumnLength, columnBacktrackStackLength,
          rowBacktrackStackLength);

      // 2. Get Color & Draw Background
      // ImU32 color = getCellColorU32(rowIndex, columnIndex, columnHintLength,
      // rowHintLength, board, cellType, highlightIndexes, isHovered);
      ImU32 color = getCellColorU32(rowIndex, columnIndex, columnHintLength,
                                    rowHintLength, board, cellType, isHovered);

      draw_list->AddRectFilled(p_min, p_max, color);

      // 3. Draw Label (Text)
      // std::string label = setLabel( rowIndex, columnIndex, cellType,
      // columnHintLength, rowHintLength, rowHintSetList, columnHintSetList,
      // rowPlacementCountList, columnPlacementCountList, cell_size,
      // backtrackStack);
      std::string label = setLabel(
          rowIndex, columnIndex, cellType, columnHintLength, rowHintLength,
          rowHintSetList, columnHintSetList, rowPlacementCountList,
          columnPlacementCountList, cell_size);//, backtrackStack);

      if (!label.empty()) {
        ImVec2 textSize =
            font->CalcTextSizeA(font->LegacySize, FLT_MAX, 0.0f, label.c_str());
        ImVec2 textPos = ImVec2(p_min.x + (cell_size - textSize.x) * 0.5f,
                                p_min.y + (cell_size - textSize.y) * 0.5f);

        draw_list->AddText(font, font->LegacySize, textPos,
                           IM_COL32(50, 50, 50, 255), label.c_str());
      }

      // 4. Draw Grid Lines
      drawGridLineDirect(draw_list, p_min, p_max, rowIndex, columnIndex,
                         columnHintLength, rowHintLength, boardRowLength,
                         boardColumnLength);
    }
  }

  auto end_draw_loop = std::chrono::high_resolution_clock::now();
  // No need to manually SetCursorPosY anymore, because ImGui::Dummy() already
  // handled layout!

  ImGui::End();

  auto end_total = std::chrono::high_resolution_clock::now();
  // Calculate duration in microseconds (us)
  long long duration_data_copy =
      std::chrono::duration_cast<std::chrono::microseconds>(end_data_copy -
                                                            start_data_copy)
          .count();
  long long duration_draw_loop =
      std::chrono::duration_cast<std::chrono::microseconds>(end_draw_loop -
                                                            start_draw_loop)
          .count();
  long long duration_total =
      std::chrono::duration_cast<std::chrono::microseconds>(end_total -
                                                            start_total)
          .count();

  // Display the results in the ImGui window itself
  ImGui::Text("--- Renderer Performance ---");
  ImGui::Text("Total Frame Time: %lld us", duration_total);
  ImGui::Text("1. Data Copy Time (Lock Wait + Copy): %lld us",
              duration_data_copy);
  ImGui::Text("2. Main Draw Loop Time (CPU Cycles): %lld us",
              duration_draw_loop);
  ImGui::Text("3. Other (ImGui Overhead, Layout, etc.): %lld us",
              duration_total - duration_data_copy - duration_draw_loop);
}

TableRenderer::CellType TableRenderer::determineCellType(
    RowIndex rowIndex, ColumnIndex columnIndex, RowLength columnHintLength,
    ColumnLength rowHintLength, RowLength boardRowLength,
    ColumnLength boardColumnLength, RowLength columnBacktrackStackLength,
    ColumnLength rowBacktrackStackLength) const {

  if (rowHintLength <= columnIndex &&
      columnIndex < rowHintLength + boardColumnLength) {
    if (rowIndex < columnHintLength) {
      return COLUMN_HINT;
    } else if (rowIndex < columnHintLength + boardRowLength) {
      return BOARD_CELL;
    } else if (rowIndex <
               columnHintLength + boardRowLength + columnBacktrackStackLength) {
      return COLUMN_PLACEMENT_COUNT;
    } else {
      return COLUMN_BACKTRACK_STACK;
    }
  }
  if (columnHintLength <= rowIndex &&
      rowIndex < columnHintLength + boardRowLength) {
    if (columnIndex < rowHintLength) {
      return ROW_HINT;
    } else if (columnIndex < rowHintLength + boardColumnLength) {
      return BOARD_CELL;
    } else if (columnIndex <
               rowHintLength + boardColumnLength + rowBacktrackStackLength) {
      return ROW_PLACEMENT_COUNT;
    } else {
      return ROW_BACKTRACK_STACK;
    }
  }
  return OUT_OF_BOARD;
}

// Helper to resolve colors to ImU32 directly (replaces setupCellStyle + ImGui
// Style Stack)
ImU32 TableRenderer::getCellColorU32(RowIndex rowIndex, ColumnIndex columnIndex,
                                     RowLength columnHintLength,
                                     ColumnLength rowHintLength, Board board,
                                     CellType cellType,
                                     //HighlightIndexes highlightIndexes,
                                     bool isHovered) const {

  // Define base colors (ABGR format for IM_COL32 usually, but the macro handles
  // RGBA->Uint)
  const ImU32 col_outOfBoard = IM_COL32(128, 128, 128, 255);
  const ImU32 col_rowHint = IM_COL32(204, 204, 230, 255);     // 0.8, 0.8, 0.9
  const ImU32 col_colHint = IM_COL32(204, 230, 204, 255);     // 0.8, 0.9, 0.8
  const ImU32 col_rowHintHigh = IM_COL32(128, 128, 230, 255); // 0.5, 0.5, 0.9
  const ImU32 col_colHintHigh = IM_COL32(128, 230, 128, 255); // 0.5, 0.9, 0.5
  const ImU32 col_black = IM_COL32(51, 51, 51, 255);          // 0.2, 0.2, 0.2
  const ImU32 col_white = IM_COL32(255, 255, 255, 255);
  const ImU32 col_empty = IM_COL32(230, 230, 230, 255); // 0.9, 0.9, 0.9

  // Hover overlay (simple additive or replacement logic)
  // For simplicity, we'll return a slightly lighter/darker variant if hovered,
  // or you can draw a semi-transparent rect over it later.
  // Here I will just map the base color.

  ImU32 baseColor = col_outOfBoard;

  if (cellType == OUT_OF_BOARD) {
    baseColor = col_outOfBoard;
  } else if (cellType == ROW_PLACEMENT_COUNT || cellType == ROW_HINT ||
             cellType == ROW_BACKTRACK_STACK) {
    //if (highlightIndexes.findRowIndex(rowIndex - columnHintLength)) {
    if (false) {
      baseColor = col_rowHintHigh;
    } else {
      baseColor = col_rowHint;
    }
  } else if (cellType == COLUMN_PLACEMENT_COUNT || cellType == COLUMN_HINT ||
             cellType == COLUMN_BACKTRACK_STACK) {
    //if (highlightIndexes.findColumnIndex(columnIndex - rowHintLength)) {
    if (false) {
      baseColor = col_colHintHigh;
    } else {
      baseColor = col_colHint;
    }
  } else {
    Coordinate coordinate =
        Coordinate(rowIndex - columnHintLength, columnIndex - rowHintLength);
    CellColor cellColor = board.getCell(coordinate).getColor();
    if (cellColor == Black) {
      baseColor = col_black;
    } else if (cellColor == White) {
      baseColor = col_white;
    } else {
      baseColor = col_empty;
    }
  }

  if (isHovered) {
    // Simple hover effect: blend with a grey overlay or just brighten
    // Here, a manual blend roughly equivalent to your previous "ButtonHovered"
    // style (0.4, 0.4, 0.4) is quite dark, assuming you meant that as the hover
    // tint. Let's just slightly darken the color to indicate hover. Bitwise
    // manipulation or ImGui::ColorConvert functions can be used, but let's keep
    // it fast. A simple hack is to subtract a small value from RGB channels.
    int r = (baseColor >> 0) & 0xFF;
    int g = (baseColor >> 8) & 0xFF;
    int b = (baseColor >> 16) & 0xFF;
    int a = (baseColor >> 24) & 0xFF;

    r = std::max(0, r - 30);
    g = std::max(0, g - 30);
    b = std::max(0, b - 30);

    return IM_COL32(r, g, b, a);
  }

  return baseColor;
}

std::string TableRenderer::setLabel(
    RowIndex rowIndex, ColumnIndex columnIndex, CellType cellType,
    RowLength columnHintLength, ColumnLength rowHintLength,
    RowHintSetList rowHintSetList, ColumnHintSetList columnHintSetList,
    RowPlacementCountList rowPlacementCountList,
    ColumnPlacementCountList columnPlacementCountList, float cell_size
    //BacktrackStack backtrackBoard
    ) const {

  // Logic remains mostly the same, just returning string.
  // Font pushing is handled in the main loop now.

  if (cellType == ROW_PLACEMENT_COUNT || cellType == ROW_HINT ||
      cellType == ROW_BACKTRACK_STACK || cellType == COLUMN_PLACEMENT_COUNT ||
      cellType == COLUMN_HINT || cellType == COLUMN_BACKTRACK_STACK) {

    if (cellType == ROW_HINT) {
      RowIndex HintSetIndex = rowIndex - columnHintLength;
      HintSet HintSet = rowHintSetList[HintSetIndex];
      ColumnIndex HintNumberIndex = ColumnIndex(
          columnIndex.getIndex() + HintSet.size() - rowHintLength.getLength());

      if (HintNumberIndex >= ColumnIndex(0)) {
        // assert(HintNumberIndex < ColumnLength((int)HintSet.size()));
        // kept your logic, assuming bounds are safe or assert exists
        return std::to_string(HintSet[HintNumberIndex.getIndex()].getNumber());
      }
    }

    if (cellType == COLUMN_HINT) {
      ColumnIndex HintSetIndex = columnIndex - rowHintLength;
      HintSet HintSet = columnHintSetList[HintSetIndex];
      RowIndex HintNumberIndex = RowIndex(rowIndex.getIndex() + HintSet.size() -
                                          columnHintLength.getLength());
      if (HintNumberIndex >= RowIndex(0)) {
        return std::to_string(HintSet[HintNumberIndex.getIndex()].getNumber());
      }
    }

    if (cellType == ROW_PLACEMENT_COUNT) {
      RowIndex placementCountIndex = rowIndex - columnHintLength;
      PlacementCount placementCount =
          rowPlacementCountList[placementCountIndex];
      return std::to_string(placementCount.getCount());
    }

    if (cellType == COLUMN_PLACEMENT_COUNT) {
      ColumnIndex placementCountIndex = columnIndex - rowHintLength;
      PlacementCount placementCount =
          columnPlacementCountList[placementCountIndex];
      return std::to_string(placementCount.getCount());
    }

    /*
    if (cellType == ROW_BACKTRACK_STACK) {
      RowIndex backtrackStackIndex = rowIndex - columnHintLength;
      int backtrackDepth =
          backtrackBoard.getDepthAtRowIndex(backtrackStackIndex);
      return std::to_string(backtrackDepth);
    }

    if (cellType == COLUMN_BACKTRACK_STACK) {
      ColumnIndex backtrackStackIndex = columnIndex - rowHintLength;
      int backtrackDepth =
          backtrackBoard.getDepthAtColumnIndex(backtrackStackIndex);
      return std::to_string(backtrackDepth);
    }
      */
  }

  return "";
}

void TableRenderer::drawGridLineDirect(ImDrawList *draw_list, ImVec2 p_min,
                                       ImVec2 p_max, RowIndex rowIndex,
                                       ColumnIndex columnIndex,
                                       RowLength columnHintLength,
                                       ColumnLength rowHintLength,
                                       RowLength boardRowLength,
                                       ColumnLength boardColumnLength) const {

  // Calculate thickness logic based on your original rules
  float columnThickness = 1.0f;
  if (columnIndex.getIndex() >= rowHintLength.getLength() &&
      (columnIndex.getIndex() - rowHintLength.getLength()) % 5 == 4) {
    columnThickness = 3.0f;
  }
  if (columnIndex.getIndex() == rowHintLength.getLength() - 1) {
    columnThickness = 6.0f;
  }
  if (columnIndex.getIndex() ==
      rowHintLength.getLength() + boardColumnLength.getLength() - 1) {
    columnThickness = 6.0f;
  }

  // Draw Vertical Line (Right side of cell)
  draw_list->AddLine(ImVec2(p_max.x, p_min.y), ImVec2(p_max.x, p_max.y),
                     IM_COL32(0, 0, 0, 255), columnThickness);

  // Calculate thickness for rows
  float rowThickness = 1.0f;
  if (rowIndex.getIndex() >= columnHintLength.getLength() &&
      (rowIndex.getIndex() - columnHintLength.getLength()) % 5 == 4) {
    rowThickness = 3.0f;
  }
  if (rowIndex.getIndex() == columnHintLength.getLength() - 1) {
    rowThickness = 6.0f;
  }
  if (rowIndex.getIndex() ==
      columnHintLength.getLength() + boardRowLength.getLength() - 1) {
    rowThickness = 6.0f;
  }

  // Draw Horizontal Line (Bottom of cell)
  draw_list->AddLine(ImVec2(p_min.x, p_max.y), ImVec2(p_max.x, p_max.y),
                     IM_COL32(0, 0, 0, 255), rowThickness);
}