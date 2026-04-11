#ifndef VERSANO_CORE_INTTYPE_H
#define VERSANO_CORE_INTTYPE_H

namespace VersaNo::Core {

template <typename Derived, typename Tag> struct IntType {
    int value;
    explicit IntType(int v = 0) : value(v) {}

    bool operator==(const IntType &other) const { return value == other.value; }
    bool operator!=(const IntType &other) const { return value != other.value; }
    bool operator<(const IntType &other) const { return value < other.value; }
    bool operator>(const IntType &other) const { return value > other.value; }
    bool operator<=(const IntType &other) const { return value <= other.value; }
    bool operator>=(const IntType &other) const { return value >= other.value; }
    Derived &operator++() {
        ++value;
        return static_cast<Derived &>(*this);
    }
    Derived operator++(int) {
        Derived temp = static_cast<Derived &>(*this);
        ++value;
        return temp;
    }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_INTTYPE_H