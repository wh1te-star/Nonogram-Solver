#ifndef VERSANO_CORE_LINE_H
#define VERSANO_CORE_LINE_H

#include "Core/Cell/Cell/Cell.h"
#include "Core/Cell/CellLocation/CellLocation.h"
#include "Core/Index/Position/CellPosition/CellPosition.h"

#include <vector>

namespace VersaNo::Core {
class Row;
}
namespace VersaNo::Core {
class Column;
}

namespace VersaNo::Core {

class Line {
  private:
  protected:
    std::vector<Cell> line;

  public:
    explicit Line(std::vector<Cell> line);
    explicit Line(std::string colorString);
    virtual ~Line() = default;

  public:
    const std::vector<Cell> &getLine() const;

  public:
    bool operator==(const Line &other) const;
    bool operator!=(const Line &other) const;
    const Cell &operator[](const CellIndex &index) const;
    Cell &operator[](const CellIndex &index);

  public:
    const size_t size() const;
    const std::vector<CellLocation> getCellLocationList(const CellPosition &cellPosition) const;
    bool canPlaceBlock(const CellIndex &startIndex, const HintNumber &hintNumber) const;
    void apply(const Line &determined);
    Row toRow() const;
    Column toColumn() const;
};
std::ostream &operator<<(std::ostream &os, const Line &line);

} // namespace VersaNo::Core

#endif // VERSANO_CORE_LINE_H
