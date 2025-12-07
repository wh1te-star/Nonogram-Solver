#ifndef SHAREDBACKTRACKSTACK_H
#define SHAREDBACKTRACKSTACK_H

#include "Algorithm/Backtrack/BacktrackStack/BacktrackStack.h"
#include <mutex>

class SharedBacktrackStack {
private:
  mutable std::mutex mtx;
  BacktrackStack backtrackStack;

public:
  SharedBacktrackStack(BacktrackStack backtrackStack);

public:
  BacktrackStack getBacktrackStack() const;
  void setBacktrackStack(const BacktrackStack &backtrackStack);
  int getDepthAtRowIndex(RowIndex rowIndex) const;
  int getDepthAtColumnIndex(ColumnIndex columnIndex) const;
  void pushRowIndex(RowIndex rowIndex);
  void pushColumnIndex(ColumnIndex columnIndex);
  void popDepth();
};

#endif
