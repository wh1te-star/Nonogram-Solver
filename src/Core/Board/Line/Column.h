#ifndef VERSANO_CORE_COLUMN_H
#define VERSANO_CORE_COLUMN_H


#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Cell/Cell/Cell.h"

#include <vector>


namespace VersaNo::Core {


class Column {
  private:
    std::vector<Cell> line;

  public:
    explicit Column(std::vector<Cell> line);
    explicit Column(std::string colorString);
    virtual ~Column() = default;

  public:
    const std::vector<Cell> &getLine() const;

  public:
    bool operator==(const Column &other) const;
    bool operator!=(const Column &other) const;
    const Cell &operator[](RowIndex index) const;
    Cell &operator[](RowIndex index);

  public:
    const size_t size() const;
    bool canPlaceBlock(RowIndex startIndex, HintNumber hintNumber) const;
    void apply(const Column &determined);
};


} // namespace VersaNo::Core

#endif // VERSANO_CORE_COLUMN_H
