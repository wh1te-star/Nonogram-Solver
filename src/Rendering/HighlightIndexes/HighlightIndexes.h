#ifndef VERSAN_CORE_HIGHLIGHTINDEXES_H
#define VERSAN_CORE_HIGHLIGHTINDEXES_H

#include "Core/Index/CellIndex/ColumnIndex.h"
#include "Core/Index/CellIndex/RowIndex.h"

#include <unordered_set>

namespace VersaNo::Rendering {

class HighlightIndexes {
  private:
    std::unordered_set<Core::RowIndex> rowIndexes;
    std::unordered_set<Core::ColumnIndex> columnIndexes;

  public:
    HighlightIndexes();

  public:
    void addRowIndex(const Core::RowIndex &rowIndex);
    void addColumnIndex(const Core::ColumnIndex &columnIndex);

  public:
    void deleteRowIndex(const Core::RowIndex &rowIndex);
    void deleteColumnIndex(const Core::ColumnIndex &columnIndex);

  public:
    bool findRowIndex(const Core::RowIndex &rowIndex) const;
    bool findColumnIndex(const Core::ColumnIndex &columnIndex) const;

  public:
    void clear();
    void clearRowIndexes();
    void clearColumnIndexes();
};

} // namespace VersaNo::Rendering

#endif // VERSAN_CORE_HIGHLIGHTINDEXES_H
