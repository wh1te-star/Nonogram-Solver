#include "Rendering/RenderingSystem/RenderingSystem.h"

using namespace VersaN;
int main() {
  Rendering::RenderingSystem renderingSystem = Rendering::RenderingSystem();
  int initResult = renderingSystem.initialize();
  if (initResult) {
    return initResult;
  }

  renderingSystem.renderingLoop();

  renderingSystem.finalize();

  return 0;
}
