#ifndef VERSANO_CORE_LISTWRAPPER_H
#define VERSANO_CORE_LISTWRAPPER_H

namespace VersaNo::Core {

template <typename Implementation, typename Tag>
class ListWrapper {
protected:
    Implementation impl;

public:
    explicit ListWrapper(Implementation i);

    size_t size() const;
    const Cell& operator[](size_t i) const;
    
    const Implementation& getImpl() const;
    Implementation& getImpl();
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_LISTWRAPPER_H

