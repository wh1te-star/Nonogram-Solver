#ifndef VERSAN_CORE_FONTDATA_H
#define VERSAN_CORE_FONTDATA_H

#include "imgui.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace VersaNo::Rendering {

class FontData {
  private:
    static const int minFontSize = 10;
    static const int maxFontSize = 70;
    static const int fontSizeStep = 5;
    static ImFont *fonts[(maxFontSize - minFontSize) / fontSizeStep + 1];
    static const ImWchar glyph_ranges_numbers[];

    FontData() = delete;

  public:
    static void initFontData();
    static ImFont *getFontByCellSize(int cellSize);
};

} // namespace VersaNo::Rendering

#endif // VERSAN_CORE_FONTDATA_H
