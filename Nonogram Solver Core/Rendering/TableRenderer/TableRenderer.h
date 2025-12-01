#ifndef TABLERENDERER_H
#define TABLERENDERER_H


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include <string>
#include "Board.h"
#include "RowIndex.h"
#include "ColumnIndex.h"
#include "RowLength.h"
#include "ColumnLength.h"
#include "RowHintSetList.h"
#include "ColumnHintSetList.h"
#include "RowPlacementCountList.h"
#include "ColumnPlacementCountList.h"
#include "HighlightIndexes.h"
#include "BacktrackStack.h"
class SharedBacktrackBoard;
class SharedBacktrackStack;
class SharedHighlightIndexes;

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
		const SharedBacktrackBoard& sharedBacktrackBoard,
		const SharedBacktrackStack& sharedBacktrackStack,
		const SharedHighlightIndexes& sharedHighlightIndexes
	) const;

private:
	CellType determineCellType(
		RowIndex rowIndex,
		ColumnIndex columnIndex,
		RowLength columnHintLength,
		ColumnLength rowHintLength,
		RowLength boardRowLength,
		ColumnLength boardColumnLength,
		RowLength columnBacktrackStackLength,
		ColumnLength rowBacktrackStackLength
	) const;

	void setupCellStyle(
		RowIndex rowIndex,
		ColumnIndex columnIndex,
		RowLength columnHintLength,
		ColumnLength rowHintLength,
		Board board,
		CellType cellType,
		HighlightIndexes highlightIndexes
	) const;

	std::string setLabel(
		RowIndex rowIndex,
		ColumnIndex columnIndex,
		CellType cellType,
		RowLength columnHintLength,
		ColumnLength rowHintLength,
		RowHintSetList rowHintSetList,
		ColumnHintSetList columnHintSetList,
		RowPlacementCountList rowPlacementCountList,
		ColumnPlacementCountList columnPlacementCountList,
		float cell_size,
		BacktrackStack backtrackStack
	) const;

	void drawGridLine(
		RowIndex rowIndex,
		ColumnIndex columnIndex,
		RowLength columnHintLength,
		ColumnLength rowHintLength,
		RowLength columnPlacementCountLength,
		ColumnLength rowPlacementCountLength
	) const;
};


#endif
