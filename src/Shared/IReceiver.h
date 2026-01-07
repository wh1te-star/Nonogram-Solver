#ifndef IRECEIVER_H
#define IRECEIVER_H

template <typename T>
class IReceiver {
public:
    virtual ~IReceiver() = default;
    virtual void request() = 0;
    virtual T receive() const = 0;
};

#endif