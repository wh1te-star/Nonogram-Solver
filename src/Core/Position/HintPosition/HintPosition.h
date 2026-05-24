#ifndef VERSANO_CORE_HINTPOSITION_H
#define VERSANO_CORE_HINTPOSITION_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Position/IPosition.h"

namespace VersaNo::Core {

template <typename TOrientation>
class HintPosition : public IPosition {
public:
    using LineIndex = typename LineTraits<TOrientation>::Index;
    using PeerIndex = typename LineTraits<TOrientation>::PeerIndex;

private:
    LineIndex lineIndex;
    PeerIndex inlineIndex;

public:
    explicit HintPosition(LineIndex lineIndex, PeerIndex inlineIndex)
        : lineIndex(lineIndex), inlineIndex(inlineIndex) {}

    static constexpr EOrientation getOrientation() {
        return std::is_same_v<TOrientation, RowOrientation> ? EOrientation::Row : EOrientation::Column;
    }

    const LineIndex& getLineIndex() const { return lineIndex; }
    const PeerIndex& getInlineIndex() const { return inlineIndex; }

    bool operator==(const HintPosition& other) const {
        return lineIndex == other.lineIndex && inlineIndex == other.inlineIndex;
    }
    bool operator!=(const HintPosition& other) const {
        return !(*this == other);
    }
};

using RowHintPosition = HintPosition<RowOrientation>;
using ColHintPosition = HintPosition<ColumnOrientation>;

} // namespace VersaNo::Core

#endif // VERSANO_CORE_HINTPOSITION_H