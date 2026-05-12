#ifndef VERSANO_CORE_HINTLISTTYPE_H
#define VERSANO_CORE_HINTLISTTYPE_H

namespace VersaNo::Core {

template <typename THintNumber, typename THintIndex>
class HintListType : public ListType<THintNumber, THintIndex> {
  public:
    using ListType<THintNumber, THintIndex>::ListType;

    explicit HintListType(const std::vector<int> &rawNumbers) {
        for (int n : rawNumbers) {
            this->data.emplace_back(n);
        }
    }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_HINTLISTTYPE_H