#ifndef COLUMNPLACEMENT_H
#define COLUMNPLACEMENT_H


#include "Placement.h"
#include "Coordinate.h"

class ColumnPlacement : public Placement {
public:
    explicit ColumnPlacement(std::vector<Cell> placement);
};


#endif
