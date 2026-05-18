#ifndef VERSANO_CORE_HINTGROUPTYPE_H
#define VERSANO_CORE_HINTGROUPTYPE_H

#include "Core/Types/PrimitiveType/ListType/ListType.h"
#include <algorithm>

namespace VersaNo::Core {

template <typename THintList, typename TIndex>
class HintGroupType : public ListType<THintList, TIndex> {
public:
    using Base = ListType<THintList, TIndex>;
    using Base::Base;

    size_t getMaxHintListSize() const {
        size_t maxSize = 0;
        for (const auto& list : this->data) {
            maxSize = (std::max)(maxSize, list.size());
        }
        return maxSize;
    }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_HINTGROUPTYPE_H