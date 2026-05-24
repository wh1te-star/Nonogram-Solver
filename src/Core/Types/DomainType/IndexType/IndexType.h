#ifndef VERSANO_CORE_INDEXTYPE_H
#define VERSANO_CORE_INDEXTYPE_H

#include "Core/ClosedRange/ClosedRange.h"

namespace VersaNo::Core {

template <typename Derived, typename Tag, typename L = void>
struct IndexType : IntType<Derived, Tag> {
    using IntType<Derived, Tag>::IntType;

    // Prefix increment operator (Index++)
    Derived &operator++() {
        ++this->value;
        return static_cast<Derived &>(*this);
    }

    // Shift by offset (Index + Length = Index)
    template <typename U = L, typename = std::enable_if_t<!std::is_same_v<U, void>>>
    Derived operator+(const U &len) const {
        return Derived(this->value + len.value);
    }

    // Distance between indices (Index - Index = Length)
    template <typename U = L, typename = std::enable_if_t<!std::is_same_v<U, void>>>
    U operator-(const Derived &rhs) const {
        return U(this->value - rhs.value);
    }

    // Comparison operators for index and length types (only comparable with same Tag types)
    template <typename T, typename = std::enable_if_t<std::is_same_v<Tag, typename T::TagType>>>
    bool operator<(const T &rhs) const {
        return this->value < rhs.value;
    }

    template <typename T, typename = std::enable_if_t<std::is_same_v<Tag, typename T::TagType>>>
    bool operator<=(const T &rhs) const {
        return this->value <= rhs.value;
    }

    template <typename T, typename = std::enable_if_t<std::is_same_v<Tag, typename T::TagType>>>
    bool operator>(const T &rhs) const {
        return this->value > rhs.value;
    }

    template <typename T, typename = std::enable_if_t<std::is_same_v<Tag, typename T::TagType>>>
    bool operator>=(const T &rhs) const {
        return this->value >= rhs.value;
    }

    // ClosedRange generator for iterating from start to lastIndex (inclusive)
    static ClosedRange<Derived> closedRange(int start, int lastIndex) {
        return ClosedRange<Derived>(start, lastIndex);
    }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_INDEXTYPE_H