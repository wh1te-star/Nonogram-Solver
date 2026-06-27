#ifndef VERSANO_CORE_LISTTYPE_H
#define VERSANO_CORE_LISTTYPE_H

#include <vector>

namespace VersaNo::Core {

template <typename T, typename TIndex> class ListType {
  protected:
    std::vector<T> data;

  public:
    explicit ListType(std::vector<T> d) : data(std::move(d)) {}
    virtual ~ListType() = default;

    const std::vector<T> &list() const { return data; }
    std::vector<T> &list() { return data; }

    const T &operator[](TIndex index) const { return data[index.value]; }
    T &operator[](TIndex index) { return data[index.value]; }

    size_t size() const { return data.size(); }
    auto begin() { return data.begin(); }
    auto end() { return data.end(); }

    const T &front() const { return data.front(); }
    T &front() { return data.front(); }
    const T &back() const { return data.back(); }
    T &back() { return data.back(); }

    bool operator==(const ListType &other) const { return data == other.data; }
    bool operator!=(const ListType &other) const { return !(*this == other); }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_LISTTYPE_H