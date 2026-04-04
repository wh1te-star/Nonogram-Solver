#ifndef ROWPLACEMENT_H
#define ROWPLACEMENT_H

#include "Core/Placement/Placement/Placement.h"

class RowPlacement : public Placement {
public:
  explicit RowPlacement(std::vector<Cell> placement);
};

#endif
