#ifndef VERSANO_CORE_ISENDER_H
#define VERSANO_CORE_ISENDER_H

namespace VersaNo::Rendering {

template <typename T> class ISender {
  public:
    virtual ~ISender() = default;
    virtual bool isRequested() const = 0;
    virtual void send(const T &data) = 0;
};

} // namespace VersaNo::Rendering

#endif // VERSANO_CORE_ISENDER_H