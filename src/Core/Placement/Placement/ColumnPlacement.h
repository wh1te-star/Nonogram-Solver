#ifndef VERSANO_CORE_COLUMNPLACEMENT_H
#define VERSANO_CORE_COLUMNPLACEMENT_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Cell/Cell/Cell.h"

#include <vector>

namespace VersaNo::Core {

class ColumnPlacement {
  private:
    std::vector<Cell> placement;

  public:
    explicit ColumnPlacement(std::vector<Cell> placement);
    explicit ColumnPlacement(std::string colorString);
    explicit ColumnPlacement(HintNumber hintNumber);
    virtual ~ColumnPlacement() = default;

  public:
    const std::vector<Cell> &getPlacement() const;

  public:
    bool operator==(const ColumnPlacement &other) const;
    bool operator!=(const ColumnPlacement &other) const;
    Cell operator[](const RowIndex &index) const;
    ColumnPlacement operator+(const ColumnPlacement &other) const;
    ColumnPlacement &operator+=(const ColumnPlacement &other);

  private:
    bool hasNone() const;

  public:
    const size_t size() const;
    const std::vector<RowIndex> getHintIndex() const;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_COLUMNPLACEMENT_H
