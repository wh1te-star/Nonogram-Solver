#ifndef VERSANO_CORE_INTWRAPPER_H
#define VERSANO_CORE_INTWRAPPER_H

namespace VersaNo::Core {

template <typename Derived, typename Tag>
struct IntWrapper {
    int value;
    explicit IntWrapper(int v = 0) : value(v) {}
    
    bool operator==(const IntWrapper &other) const { return value == other.value; }
    bool operator!=(const IntWrapper &other) const { return value != other.value; }
    bool operator<(const IntWrapper &other) const { return value < other.value; }
    bool operator>(const IntWrapper &other) const { return value > other.value; }
    bool operator<=(const IntWrapper &other) const { return value <= other.value; }
    bool operator>=(const IntWrapper &other) const { return value >= other.value; }
    Derived& operator++() { ++value; return static_cast<Derived&>(*this); }
    Derived operator++(int) { Derived temp = static_cast<Derived&>(*this); ++value; return temp; }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_INTWRAPPER_H