#ifndef VERSANO_CORE_PLACEMENTTYPE_H
#define VERSANO_CORE_PLACEMENTTYPE_H

#include "Core/Types/PrimitiveType/ListType/ListType.h"
#include "Core/Cell/Cell/Cell.h"
#include <vector>
#include <cassert>

namespace VersaNo::Core {

template <typename TIndex>
class Placement : public ListType<Cell, TIndex> {
public:
    using Base = ListType<Cell, TIndex>;
    using Base::Base;

    explicit Placement(std::vector<Cell> d) : Base(std::move(d)) { 
        assert(!this->hasNone()); 
    }

    bool hasNone() const {
        for (const auto& cell : this->data) {
            if (cell.getColor() == CellColor::None) {
                return true;
            }
        }
        return false;
    }

    Placement operator+(const Placement &other) const {
        auto d = this->data;
        d.insert(d.end(), other.data.begin(), other.data.end());
        return Placement(d);
    }

    std::vector<TIndex> getHintIndex() const {
        std::vector<TIndex> hintIndexList;
        for (size_t i = 0; i < this->data.size(); ++i) {
            if (i == 0 || this->data[i - 1].getColor() != CellColor::Black) {
                if (this->data[i].getColor() == CellColor::Black) {
                    hintIndexList.emplace_back(static_cast<int>(i));
                }
            }
        }
        return hintIndexList;
    }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_PLACEMENTTYPE_H