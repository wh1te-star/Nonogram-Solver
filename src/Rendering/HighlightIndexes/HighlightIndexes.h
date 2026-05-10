#ifndef VERSANO_CORE_HIGHLIGHTINDEXES_H
#define VERSANO_CORE_HIGHLIGHTINDEXES_H

#include "Core/Types/AppliedType/AppliedType.h"

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

#endif // VERSANO_CORE_HIGHLIGHTINDEXES_H
