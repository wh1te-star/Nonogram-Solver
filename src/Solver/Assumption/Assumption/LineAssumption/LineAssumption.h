#ifndef LINEASSUMPTION_H
#define LINEASSUMPTION_H

#include "Board/BacktrackBoard/BacktrackBoard.h"

class LineAssumption {
private:
  CellIndex index;
  Line line;

public:
  explicit LineAssumption(const CellIndex &index, const Line &line);
  virtual ~LineAssumption() = default;
  virtual void applyTo(BacktrackBoard &board) const = 0;
};

#endif
