#ifndef ROW_H
#define ROW_H


#include "Board/Line/Line.h"

class Row : public Line {
public:
    explicit Row(std::vector<Cell> line);
};


#endif
