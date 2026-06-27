#ifndef VERSANO_CORE_ADDITIVEINTTYPE_H
#define VERSANO_CORE_ADDITIVEINTTYPE_H

#include "Core/Types/PrimitiveType/IntType/IntType.h"

namespace VersaNo::Core {

template <typename Derived, typename Tag>
struct AdditiveIntType : public IntType<Derived, Tag> {
    using IntType<Derived, Tag>::IntType;

    Derived operator+(const Derived &rhs) const {
        return Derived(this->value + rhs.value);
    }

    Derived& operator+=(const Derived &rhs) {
        this->value += rhs.value;
        return static_cast<Derived&>(*this);
    }

    Derived operator-(const Derived &rhs) const {
        return Derived(this->value - rhs.value);
    }

    Derived& operator-=(const Derived &rhs) {
        this->value -= rhs.value;
        return static_cast<Derived&>(*this);
    }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_ADDITIVEINTTYPE_H