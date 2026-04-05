#ifndef VERSANO_CORE_CELL_H
#define VERSANO_CORE_CELL_H

#include "Core/Cell/CellColor/CellColor.h"

#include <iostream>

namespace VersaNo::Core {

class Cell {
  private:
    CellColor color;

  public:
    explicit Cell();
    explicit Cell(CellColor color);

  public:
    const CellColor &getColor() const;

  public:
    bool operator==(const Cell &other) const;
    bool operator!=(const Cell &other) const;

  public:
    bool canColor(const CellColor &newColor) const;
};

std::ostream &operator<<(std::ostream &os, const Cell &cell);

} // namespace VersaNo::Core

#endif // VERSANO_CORE_CELL_H