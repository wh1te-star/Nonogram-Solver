#ifndef VERSANO_CORE_ROWPLACEMENT_H
#define VERSANO_CORE_ROWPLACEMENT_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Cell/Cell/Cell.h"

#include <vector>

namespace VersaNo::Core {

class RowPlacement {
  private:
    std::vector<Cell> placement;

  public:
    explicit RowPlacement(std::vector<Cell> placement);
    explicit RowPlacement(std::string colorString);
    explicit RowPlacement(HintNumber hintNumber);
    virtual ~RowPlacement() = default;

  public:
    const std::vector<Cell> &getPlacement() const;

  public:
    bool operator==(const RowPlacement &other) const;
    bool operator!=(const RowPlacement &other) const;
    Cell operator[](const ColumnIndex &index) const;
    RowPlacement operator+(const RowPlacement &other) const;
    RowPlacement &operator+=(const RowPlacement &other);

  private:
    bool hasNone() const;

  public:
    const size_t size() const;
    const std::vector<ColumnIndex> getHintIndex() const;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_ROWPLACEMENT_H
