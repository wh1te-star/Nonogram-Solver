#ifndef ISENDER_H
#define ISENDER_H

template <typename T>
class ISender {
public:
    virtual ~ISender() = default;
    virtual bool isRequested() const = 0;
    virtual void send(const T& data) = 0;
};

#endif