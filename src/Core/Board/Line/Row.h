#ifndef VERSANO_CORE_ROW_H
#define VERSANO_CORE_ROW_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Cell/Cell/Cell.h"

#include <vector>


namespace VersaNo::Core {


class Row {
  private:
    std::vector<Cell> line;

  public:
    explicit Row(std::vector<Cell> line);
    explicit Row(std::string colorString);
    virtual ~Row() = default;

  public:
    const std::vector<Cell> &getLine() const;

  public:
    bool operator==(const Row &other) const;
    bool operator!=(const Row &other) const;
    const Cell &operator[](ColumnIndex index) const;
    Cell &operator[](ColumnIndex index);

  public:
    const size_t size() const;
    bool canPlaceBlock(ColumnIndex startIndex, HintNumber hintNumber) const;
    void apply(const Row &determined);
};


} // namespace VersaNo::Core

#endif // VERSANO_CORE_ROW_H
