#ifndef ISTOPSIGNAL_H
#define ISTOPSIGNAL_H

class IStopSignal {
public:
    virtual ~IStopSignal() = default;
    virtual void requestStop() = 0;
    virtual bool shouldStop() const = 0;
};

#endif