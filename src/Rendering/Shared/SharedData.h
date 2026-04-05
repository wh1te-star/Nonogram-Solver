#ifndef VERSAN_CORE_SHAREDDATA_H
#define VERSAN_CORE_SHAREDDATA_H

#include "Rendering/Shared/IReceiver.h"
#include "Rendering/Shared/ISender.h"

#include <atomic>
#include <mutex>

namespace VersaN::Rendering {

template <typename T> class SharedDataBuffer : public ISender<T>, public IReceiver<T> {
  private:
    std::atomic<bool> requestFlag{false};
    mutable std::mutex mtx;
    T sharedData;

  public:
    explicit SharedDataBuffer(const T &initialData) : sharedData(initialData) {}

    bool isRequested() const override { return requestFlag.load(std::memory_order_relaxed); }
    void send(const T &data) override {
        std::lock_guard<std::mutex> lock(mtx);
        sharedData = data;
        requestFlag.store(false);
    }

    void request() override { requestFlag.store(true); }
    T receive() const override {
        std::lock_guard<std::mutex> lock(mtx);
        return sharedData;
    }
};

} // namespace VersaN::Rendering

#endif // VERSAN_CORE_SHAREDDATA_H