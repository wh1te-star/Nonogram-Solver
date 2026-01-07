#ifndef SHAREDDATA_H
#define SHAREDDATA_H

template <typename T>
class SharedDataBuffer : public ISender<T>, public IReceiver<T> {
private:
    std::atomic<bool> requestFlag{false};
    mutable std::mutex mtx;
    T sharedData;
public:
    bool isRequested() const override { return requestFlag.load(std::memory_order_relaxed); }
    void send(const T& data) override {
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

#endif