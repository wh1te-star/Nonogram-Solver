#ifndef VERSANO_CORE_INTTYPE_H
#define VERSANO_CORE_INTTYPE_H

namespace VersaNo::Core {

template <typename Derived, typename Tag> struct IntType {
    int value;
    using TagType = Tag;

    explicit constexpr IntType(int v = 0) : value(v) {}

    bool operator==(const Derived &rhs) const { return value == rhs.value; }
    bool operator!=(const Derived &rhs) const { return value != rhs.value; }
    bool operator<(const Derived &rhs) const { return value < rhs.value; }
    bool operator>(const Derived &rhs) const { return value > rhs.value; }
    bool operator<=(const Derived &rhs) const { return value <= rhs.value; }
    bool operator>=(const Derived &rhs) const { return value >= rhs.value; }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_INTTYPE_H