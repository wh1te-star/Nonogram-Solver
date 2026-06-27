#ifndef VERSANO_CORE_INDEXTYPE_H
#define VERSANO_CORE_INDEXTYPE_H

#include "Core/ClosedRange/ClosedRange.h"
#include "Core/Types/PrimitiveType/IntType/IntType.h"

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
    template <
      typename U,
      typename = std::enable_if_t<std::is_same_v<U, L> && !std::is_same_v<U, void>>>
    Derived operator+(const U &len) const {
        return Derived(this->value + len.value);
    }
    Derived operator+(int offset) const { return Derived(this->value + offset); }

    // Shift by offset (Index - Length = Index)
    template <
      typename U,
      typename = std::enable_if_t<std::is_same_v<U, L> && !std::is_same_v<U, void>>>
    Derived operator-(const U &len) const {
        return Derived(this->value - len.value);
    }
    Derived operator-(int offset) const { return Derived(this->value - offset); }

    // Distance between indices (Index - Index = Length)
    template <
      typename ReturnType = L,
      typename = std::enable_if_t<!std::is_same_v<ReturnType, void>>>
    ReturnType operator-(const Derived &rhs) const {
        return ReturnType(this->value - rhs.value);
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

    // Generator for ascending range only (Returns empty range if start > lastIndex)
    static ClosedRange<Derived> closedRangeUp(int start, int lastIndex) {
        return ClosedRange<Derived>::Up(start, lastIndex);
    }

    // Generator for descending range only (Returns empty range if start < lastIndex)
    static ClosedRange<Derived> closedRangeDown(int start, int lastIndex) {
        return ClosedRange<Derived>::Down(start, lastIndex);
    }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_INDEXTYPE_H