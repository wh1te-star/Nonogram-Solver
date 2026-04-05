#ifndef VERSANO_CORE_PLACEMENT_H
#define VERSANO_CORE_PLACEMENT_H

#include "Core/Cell/Cell/Cell.h"
#include "Core/Index/Position/CellPosition/CellPosition.h"

#include <vector>

namespace VersaNo::Core {
class RowPlacement;
}
namespace VersaNo::Core {
class ColumnPlacement;
}

namespace VersaNo::Core {

class Placement {
  private:
  protected:
    std::vector<Cell> placement;

  public:
    explicit Placement(std::vector<Cell> placement);
    explicit Placement(std::string colorString);
    explicit Placement(HintNumber hintNumber);
    virtual ~Placement() = default;

  public:
    const std::vector<Cell> &getPlacement() const;

  public:
    bool operator==(const Placement &other) const;
    bool operator!=(const Placement &other) const;
    Cell operator[](const CellIndex &index) const;
    Placement operator+(const Placement &other) const;
    Placement &operator+=(const Placement &other);

  private:
    bool hasNone() const;

  public:
    const size_t size() const;
    const std::vector<CellIndex> getHintIndex() const;
    RowPlacement toRowPlacement() const;
    ColumnPlacement toColumnPlacement() const;
};
std::ostream &operator<<(std::ostream &os, const Placement &placement);

} // namespace VersaNo::Core

#endif // VERSANO_CORE_PLACEMENT_H
