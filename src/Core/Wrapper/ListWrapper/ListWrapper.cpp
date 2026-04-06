#include "Core/Wrapper/ListWrapper/ListWrapper.h"

namespace VersaNo::Core {

explicit ListWrapper::ListWrapper(Implementation i) : impl(std::move(i)) {}

size_t ListWrapper::size() const { return impl.size(); }
const Cell &ListWrapper::operator[](size_t i) const { return impl[i]; }

const Implementation &ListWrapper::getImpl() const { return impl; }
Implementation &ListWrapper::getImpl() { return impl; }

} // namespace VersaNo::Core