#ifndef COLUMN_H
#define COLUMN_H


#include "Line.h"
#include "Coordinate.h"

class Column : public Line {
public:
    explicit Column(std::vector<Cell> line);
};


#endif
