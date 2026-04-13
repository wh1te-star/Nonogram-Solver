#ifndef VERSANO_CORE_INDEXTYPE_H
#define VERSANO_CORE_INDEXTYPE_H

namespace VersaNo::Core {

template <typename Derived, typename Tag, typename L = void>
struct IndexType : IntType<Derived, Tag> {
    using IntType<Derived, Tag>::IntType;

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
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_INDEXTYPE_H