#ifndef VERSANO_CORE_INDEXWRAPPER_H
#define VERSANO_CORE_INDEXWRAPPER_H

namespace VersaNo::Core {

template <typename Derived, typename Tag, typename L>
struct IndexWrapper : IntWrapper<Derived, Tag> {
    using IntWrapper<Derived, Tag>::IntWrapper;

    // Index - Index = Length
    L operator-(const Derived& rhs) const { return L(this->value - rhs.value); }
    // Index + Length = Index
    Derived operator+(const L& len) const { return Derived(this->value + len.value); }
    // Index + int (オフセット移動)
    Derived operator+(int offset) const { return Derived(this->value + offset); }
    // Index < Length (境界チェック用)
    bool operator<(const L& len) const { return this->value < len.value; }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_INDEXWRAPPER_H