#ifndef VERSANO_CORE_LISTWRAPPER_H
#define VERSANO_CORE_LISTWRAPPER_H

namespace VersaNo::Core {

template <typename T, typename Idx>
class ListWrapper {
protected:
    std::vector<T> data;
public:
    ListWrapper() = default;
    explicit ListWrapper(size_t size) : data(size) {}
    explicit ListWrapper(std::vector<T> v) : data(std::move(v)) {}

    T& operator[](Idx i) { return data[i.value]; }
    const T& operator[](Idx i) const { return data[i.value]; }
    size_t size() const { return data.size(); }
    auto begin() { return data.begin(); }
    auto end() { return data.end(); }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_LISTWRAPPER_H
