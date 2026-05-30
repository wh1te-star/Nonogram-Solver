#ifndef VERSANO_CORE_LENGTHTYPE_H
#define VERSANO_CORE_LENGTHTYPE_H

#include <type_traits>

namespace VersaNo::Core {

template <typename Derived, typename Tag> 
struct LengthType : IntType<Derived, Tag> {
    using IntType<Derived, Tag>::IntType;

    Derived operator+(const Derived &rhs) const { return Derived(this->value + rhs.value); }
    Derived operator+(const size_t &rhs) const { return Derived(this->value + rhs); }
    Derived operator-(const Derived &rhs) const { return Derived(this->value - rhs.value); }
    Derived operator-(const size_t &rhs) const { return Derived(this->value - rhs); }

    template <typename T, typename = std::enable_if_t<std::is_same_v<Tag, typename T::TagType>>>
    bool operator<(const T &rhs) const  { return this->value < rhs.value; }

    template <typename T, typename = std::enable_if_t<std::is_same_v<Tag, typename T::TagType>>>
    bool operator<=(const T &rhs) const { return this->value <= rhs.value; }

    template <typename T, typename = std::enable_if_t<std::is_same_v<Tag, typename T::TagType>>>
    bool operator>(const T &rhs) const  { return this->value > rhs.value; }

    template <typename T, typename = std::enable_if_t<std::is_same_v<Tag, typename T::TagType>>>
    bool operator>=(const T &rhs) const { return this->value >= rhs.value; }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_LENGTHTYPE_H