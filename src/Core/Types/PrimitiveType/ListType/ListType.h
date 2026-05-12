#ifndef VERSANO_CORE_LISTTYPE_H
#define VERSANO_CORE_LISTTYPE_H

#include <vector>

namespace VersaNo::Core {

template <typename T, typename TIndex>
class ListType {
protected:
    std::vector<T> data;

public:
    explicit ListType(std::vector<T> d) : data(std::move(d)) {}
    virtual ~ListType() = default;

    const T& operator[](TIndex index) const { return data[index.value]; }
    T& operator[](TIndex index) { return data[index.value]; }

    size_t size() const { return data.size(); }
    auto begin() { return data.begin(); }
    auto end() { return data.end(); }
    
    bool operator==(const ListType& other) const { return data == other.data; }
    bool operator!=(const ListType& other) const { return !(*this == other); }
};

}

#endif // VERSANO_CORE_LISTTYPE_H
