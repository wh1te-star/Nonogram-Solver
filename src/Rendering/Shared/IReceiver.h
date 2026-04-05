#ifndef VERSAN_CORE_IRECEIVER_H
#define VERSAN_CORE_IRECEIVER_H

namespace VersaNo::Rendering {

template <typename T> class IReceiver {
  public:
    virtual ~IReceiver() = default;
    virtual void request() = 0;
    virtual T receive() const = 0;
};

} // namespace VersaNo::Rendering

#endif // VERSAN_CORE_IRECEIVER_H