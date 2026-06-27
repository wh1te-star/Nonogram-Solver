#ifndef VERSANO_CORE_CLOSEDRANGE_H
#define VERSANO_CORE_CLOSEDRANGE_H

namespace VersaNo::Core {

template <typename TReturn>
class ClosedRange {
private:
    int startValue;
    int lastValue;
    bool isReverse;

    ClosedRange(int start, int last, bool reverse) 
        : startValue(start), lastValue(last), isReverse(reverse) {
        
        // If direction is Up but start > last (e.g., 0 -> -1)
        if (!isReverse && start > last) {
            // Make it empty by setting lastValue to be smaller than startValue
            // This ensures (current <= other.current) is false on the very first check
            lastValue = start - 1; 
        }
        // If direction is Down but start < last (e.g., -1 -> 0)
        else if (isReverse && start < last) {
            // Make it empty by setting lastValue to be larger than startValue
            // This ensures (current >= other.current) is false on the very first check
            lastValue = start + 1;
        }
    }

public:
    // Legacy constructor (auto-detects direction)
    ClosedRange(int start, int last) 
        : startValue(start), lastValue(last), isReverse(start > last) {}

    // Factory method for strict ascending range
    static ClosedRange Up(int start, int last) {
        return ClosedRange(start, last, false);
    }

    // Factory method for strict descending range
    static ClosedRange Down(int start, int last) {
        return ClosedRange(start, last, true);
    }

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

        // Comparison for loop termination
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