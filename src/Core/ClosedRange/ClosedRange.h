#ifndef VERSANO_CORE_CLOSEDRANGE_H
#define VERSANO_CORE_CLOSEDRANGE_H

namespace VersaNo::Core {

template <typename TReturn>
class ClosedRange {
private:
    int startValue;
    int lastValue;
    bool isReverse;

public:
    ClosedRange(int start, int last) 
        : startValue(start), lastValue(last), isReverse(start > last) {}

    struct Iterator {
        int current;
        bool reverse;

        TReturn operator*() const { return TReturn(current); }
        
        Iterator& operator++() {
            if (reverse) {
                --current;
            } else {
                ++current;
            }
            return *this;
        }

        // 終了判定（lastを通り過ぎたら終了）
        bool operator!=(const Iterator& other) const {
            if (reverse) {
                return current >= other.current;
            } else {
                return current <= other.current;
            }
        }
    };

    Iterator begin() const { return Iterator{startValue, isReverse}; }
    Iterator end() const   { return Iterator{lastValue, isReverse}; }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_CLOSEDRANGE_H