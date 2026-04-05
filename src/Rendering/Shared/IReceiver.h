#ifndef VERSAN_CORE_IRECEIVER_H
#define VERSAN_CORE_IRECEIVER_H

namespace VersaN::Rendering {

template <typename T> class IReceiver {
  public:
    virtual ~IReceiver() = default;
    virtual void request() = 0;
    virtual T receive() const = 0;
};

} // namespace VersaN::Rendering

#endif // VERSAN_CORE_IRECEIVER_H