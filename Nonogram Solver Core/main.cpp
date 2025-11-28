/*
#include <vector>
#include <stack>
#include <string>
#include <optional>
#include <coroutine>
#include <cstdio>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <numeric>
#include <sstream>
#include "Board/Board/Board.h"
#include "Rendering/RenderingSystem/RenderingSystem.h"

int main() {
	RenderingSystem renderingSystem = RenderingSystem();
    int initResult = renderingSystem.initialize();
    if (initResult) {
        return initResult;
	}

	renderingSystem.renderingLoop();

	renderingSystem.finalize();

    return 0;
}
*/

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_internal.h"

// --- Global Setup Function Prototype ---
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// Function to programmatically set the initial docking layout
void SetupDockingLayout(ImGuiID dockspace_id); 

int main() {
    // --- 1. GLFW Initialization and Configuration ---
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // --- 2. Window Creation and GLAD Initialization ---
    GLFWwindow* window = glfwCreateWindow(1200, 800, "Glad Docking Test", NULL, NULL);
    if (window == NULL) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, 1200, 800);

    // --- 3. ImGui Initialization ---
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    // CRUCIAL: Enable Docking feature
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core"); 

    // --- 4. Render Loop ---
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // --- New Frame ---
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // --- DockSpace Setup ---
        // Create an invisible primary window to hold the dockspace
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
        
        ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
        ImGui::SetNextWindowSize(ImGui::GetMainViewport()->Size);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

        ImGui::Begin("DockSpaceParent", nullptr, window_flags);
        ImGui::PopStyleVar(3); // Pop the style vars used for the full-screen window

        // The ID of the DockSpace
        ImGuiID dockspace_id = ImGui::GetID("MyFullDockSpace");

        // Set up the layout only once when the program starts
        static bool first_time = true;
        if (first_time) {
            first_time = false;
            SetupDockingLayout(dockspace_id);
        }
        
        // Render the actual DockSpace
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_PassthruCentralNode);

        ImGui::End(); // End DockSpaceParent

        // --- Draw Actual Windows ---
        // These windows will be docked automatically due to SetupDockingLayout()
        ImGui::Begin("Left Panel"); 
        ImGui::Text("This is the left side (25%%).");
        ImGui::End();

        ImGui::Begin("Right Panel"); 
        ImGui::Text("This is the right side (75%%).");
        ImGui::End();
        
        // --- Rendering ---
        ImGui::Render();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        
        glfwSwapBuffers(window);
    }

    // --- 5. Cleanup ---
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
    return 0;
}

// Function to define the split layout (called only once)
void SetupDockingLayout(ImGuiID dockspace_id) {
    // 既存のノードがあれば削除
    ImGui::DockBuilderRemoveNode(dockspace_id); 
    // ドックノードを再構築
    ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_DockSpace);
    ImGui::DockBuilderSetNodeSize(dockspace_id, ImGui::GetMainViewport()->Size);

    ImGuiID dock_main_id = dockspace_id;
    ImGuiID dock_left_id;
    ImGuiID dock_right_id;

    // 画面全体を左側から25%で分割。dock_right_idは残りの部分のIDになる
    // Split the main area horizontally into two halves (25% left, 75% right)
    ImGui::DockBuilderSplitNode(dock_main_id, ImGuiDir_Left, 0.25f, &dock_left_id, &dock_right_id);

    // 各ウィンドウを生成されたIDにドッキング
    // Assign the windows to the split areas
    ImGui::DockBuilderDockWindow("Left Panel", dock_left_id);
    ImGui::DockBuilderDockWindow("Right Panel", dock_right_id);
    
    // レイアウトを適用
    ImGui::DockBuilderFinish(dockspace_id); 
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // Ensure the viewport matches the new window dimensions
    glViewport(0, 0, width, height);
}
