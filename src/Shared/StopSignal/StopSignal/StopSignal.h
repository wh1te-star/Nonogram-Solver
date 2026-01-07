#ifndef STOPSIGNAL_H
#define STOPSIGNAL_H

#include "Shared/StopSignal/IStopSignal.h"
#include <atomic>

class StopSignal : public IStopSignal {
private:
  std::atomic<bool> stopFlag{false};

public:
  void requestStop() override;
  bool shouldStop() const override;
};
#endif