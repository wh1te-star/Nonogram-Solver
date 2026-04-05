#ifndef VERSAN_CORE_RENDERINGSYSTEM_H
#define VERSAN_CORE_RENDERINGSYSTEM_H

#include "imgui.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace VersaN::Rendering {

class RenderingSystem {
  private:
    GLFWwindow *window;
    ImGuiIO *io;

    static void glfw_error_callback(int error, const char *description);

  public:
    RenderingSystem();
    int initialize();
    void renderingLoop();
    void finalize();
};

} // namespace VersanN::Rendering

#endif // VERSAN_CORE_RENDERINGSYSTEM_H
