#ifndef VERSANO_CORE_LENGTHWRAPPER_H
#define VERSANO_CORE_LENGTHWRAPPER_H

namespace VersaNo::Core {

template <typename Derived, typename Tag>
struct LengthWrapper : IntWrapper<Derived, Tag> {
    using IntWrapper<Derived, Tag>::IntWrapper;

    Derived operator+(const Derived& rhs) const { return Derived(this->value + rhs.value); }
    Derived operator-(const Derived& rhs) const { return Derived(this->value - rhs.value); }
    Derived operator*(int multiplier) const { return Derived(this->value * multiplier); }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_LENGTHWRAPPER_H
