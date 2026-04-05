#ifndef VERSAN_CORE_ISENDER_H
#define VERSAN_CORE_ISENDER_H

namespace VersaN::Rendering {

template <typename T> class ISender {
  public:
    virtual ~ISender() = default;
    virtual bool isRequested() const = 0;
    virtual void send(const T &data) = 0;
};

} // namespace VersaN::Rendering

#endif // VERSAN_CORE_ISENDER_H