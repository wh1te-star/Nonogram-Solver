#ifndef VERSANO_CORE_HINTLIST_H
#define VERSANO_CORE_HINTLIST_H

namespace VersaNo::Core {

template <typename THintNumber, typename THintIndex>
class HintListType : public ListType<THintNumber, THintIndex> {
  public:
    using ListType<THintNumber, THintIndex>::ListType;

  public:
    using ListType::ListType;

    explicit HintListType(const std::vector<int> &rawNumbers) {
        for (int n : rawNumbers) {
            this->data.emplace_back(n);
        }
    }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_HINTLIST_H