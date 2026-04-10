#ifndef VERSANO_CORE_LENGTHWRAPPER_H
#define VERSANO_CORE_LENGTHWRAPPER_H

namespace VersaNo::Core {

template <typename Derived, typename Tag> struct LengthType : IntType<Derived, Tag> {
    using IntType<Derived, Tag>::IntType;

    Derived operator+(const Derived &rhs) const { return Derived(this->value + rhs.value); }
    Derived operator-(const Derived &rhs) const { return Derived(this->value - rhs.value); }
    Derived operator*(int multiplier) const { return Derived(this->value * multiplier); }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_LENGTHWRAPPER_H
