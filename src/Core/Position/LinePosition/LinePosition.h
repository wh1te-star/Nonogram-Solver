#ifndef VERSANO_CORE_LINEPOSITION_H
#define VERSANO_CORE_LINEPOSITION_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Position/IPosition.h"

namespace VersaNo::Core {

template <typename TOrientation>
class LinePosition : public IPosition {
public:
    using Index = typename LineTraits<TOrientation>::Index;

private:
    Index index;

public:
    explicit LinePosition(Index index) : index(index) {}

    static constexpr EOrientation getOrientation() {
        return std::is_same_v<TOrientation, RowOrientation> ? EOrientation::Row : EOrientation::Column;
    }

    const Index& getIndex() const { return index; }

    bool operator==(const LinePosition& other) const {
        return index == other.index;
    }
    bool operator!=(const LinePosition& other) const {
        return !(*this == other);
    }
};

using RowPosition = LinePosition<RowOrientation>;
using ColPosition = LinePosition<ColumnOrientation>;

} // namespace VersaNo::Core

#endif // VERSANO_CORE_LINEPOSITION_H