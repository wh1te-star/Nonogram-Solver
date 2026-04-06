#ifndef VERSANO_CORE_INTWRAPPER_H
#define VERSANO_CORE_INTWRAPPER_H

namespace VersaNo::Core {

template <typename Tag>
class IntWrapper {
protected:
    int value;

public:
    explicit IntWrapper(int v);
    
    int get() const;

    bool operator==(const IntWrapper& other);
    bool operator!=(const IntWrapper& other);
    bool operator<(const IntWrapper& other);
    bool operator>(const IntWrapper& other);
    bool operator<=(const IntWrapper& other);
    bool operator>=(const IntWrapper& other);
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_INTWRAPPER_H