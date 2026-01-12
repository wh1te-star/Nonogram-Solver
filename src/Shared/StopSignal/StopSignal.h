#ifndef STOPSIGNAL_H
#define STOPSIGNAL_H

#include <atomic>

class StopSignal {
private:
  std::atomic<bool> stopFlag{false};

public:
  void requestStop();
  bool shouldStop() const;
};
#endif