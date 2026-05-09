#ifndef VERSANO_CORE_HINTPOSITION_H
#define VERSANO_CORE_HINTPOSITION_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Position/IPosition.h"

namespace VersaNo::Core {

class HintPosition : public IPosition {
  private:
    Orientation orientation;
    CellIndex cellIndex;
    int hintIndex;

  public:
    explicit HintPosition(Orientation orientation, CellIndex cellIndex, int hintIndex);

  public:
    const Orientation &getOrientation() const;
    const CellIndex &getCellIndex() const;
    int getHintIndex() const;

  public:
    bool operator==(const HintPosition &other) const;
    bool operator!=(const HintPosition &other) const;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_HINTPOSITION_H