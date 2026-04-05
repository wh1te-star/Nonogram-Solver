#include "Rendering/RenderingSystem/RenderingSystem.h"

int main() {
  VersaNo::Rendering::RenderingSystem renderingSystem = VersaNo::Rendering::RenderingSystem();
  int initResult = renderingSystem.initialize();
  if (initResult) {
    return initResult;
  }

  renderingSystem.renderingLoop();

  renderingSystem.finalize();

  return 0;
}