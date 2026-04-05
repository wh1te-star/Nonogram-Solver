#ifndef VERSANO_CORE_STOPSIGNAL_H
#define VERSANO_CORE_STOPSIGNAL_H

#include <atomic>

namespace VersaNo::Rendering {

class StopSignal {
  private:
    std::atomic<bool> stopFlag{false};

  public:
    void requestStop();
    bool shouldStop() const;
};

} // namespace VersaNo::Rendering

#endif // VERSANO_CORE_STOPSIGNAL_H