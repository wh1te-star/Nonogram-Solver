#ifndef VERSANO_CORE_LINEPOSITION_H
#define VERSANO_CORE_LINEPOSITION_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Position/IPosition.h"

namespace VersaNo::Core {

class LinePosition : public IPosition {
  private:
    Orientation orientation;
    CellIndex cellIndex;

  public:
    explicit LinePosition(Orientation orientation, CellIndex index);

  public:
    const Orientation &getOrientation() const;
    const CellIndex &getCellIndex() const;

  public:
    bool operator==(const LinePosition &other) const;
    bool operator!=(const LinePosition &other) const;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_LINEPOSITION_H
