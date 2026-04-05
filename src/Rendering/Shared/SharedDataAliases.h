#ifndef VERSAN_CORE_SHARED_DATA_ALIASES_H
#define VERSAN_CORE_SHARED_DATA_ALIASES_H

#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Rendering/Shared/SharedData.h"

namespace VersaNo::Rendering {

using SharedNonogramBoard = SharedDataBuffer<Core::NonogramBoard>;

} // namespace VersaNo::Rendering

#endif