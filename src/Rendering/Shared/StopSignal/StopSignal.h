#ifndef VERSAN_CORE_STOPSIGNAL_H
#define VERSAN_CORE_STOPSIGNAL_H

#include <atomic>

namespace VersaN::Rendering {

class StopSignal {
  private:
    std::atomic<bool> stopFlag{false};

  public:
    void requestStop();
    bool shouldStop() const;
};

} // namespace VersaN::Rendering

#endif // VERSAN_CORE_STOPSIGNAL_H