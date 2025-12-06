#ifndef HIGHLIGHTINDEXES_H
#define HIGHLIGHTINDEXES_H

#include "Index/CellIndex/ColumnIndex.h"
#include "Index/CellIndex/RowIndex.h"
#include <unordered_set>

class HighlightIndexes {
private:
  std::unordered_set<RowIndex> rowIndexes;
  std::unordered_set<ColumnIndex> columnIndexes;

public:
  HighlightIndexes();

public:
  void addRowIndex(const RowIndex &rowIndex);
  void addColumnIndex(const ColumnIndex &columnIndex);

public:
  void deleteRowIndex(const RowIndex &rowIndex);
  void deleteColumnIndex(const ColumnIndex &columnIndex);

public:
  bool findRowIndex(const RowIndex &rowIndex) const;
  bool findColumnIndex(const ColumnIndex &columnIndex) const;

public:
  void clear();
  void clearRowIndexes();
  void clearColumnIndexes();
};

#endif
