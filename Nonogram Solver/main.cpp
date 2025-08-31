#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_internal.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <string>

// �O���b�h�̃T�C�Y
const int GRID_FULL_SIZE = 15; // �w�b�_�[�܂ޑS�̂̃O���b�h�T�C�Y
const int HEADER_SIZE = 5;     // �w�b�_�[�̍s/��

// �Z���̏�Ԃ��`
enum class CellState {
    Unknown,
    Filled,
    Marked,
    Empty
};

/// GLFW�̃G���[�R�[���o�b�N
void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

void RenderNonogramUI() {
    // 1. ���C���̃r���[�|�[�g�̃T�C�Y���擾
    const ImGuiViewport* viewport = ImGui::GetMainViewport();

    // 2. ���ɕ`�悷��E�B���h�E�̈ʒu�ƃT�C�Y��ݒ�
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);

    // 3. �E�B���h�E�̑������\���ɂ���t���O
    ImGuiWindowFlags window_flags =
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoSavedSettings |
        ImGuiWindowFlags_NoBringToFrontOnFocus;

    // 4. �E�B���h�E�̕`����J�n
    ImGui::Begin("Nonogram UI", NULL, window_flags);

    // �E�B���h�E�̗��p�\�ȕ`��̈���擾
    ImVec2 window_size = ImGui::GetContentRegionAvail();

    // �E�B���h�E�̏c���̒Z�����ɍ��킹�ă}�X�̃T�C�Y���v�Z
    float min_size = ImMin(window_size.x, window_size.y);
    float cell_size = (min_size / GRID_FULL_SIZE) - 9.0f;

    // �O���b�h���e�[�u���Ƃ��ĕ`��
    if (ImGui::BeginTable("NonogramGrid", GRID_FULL_SIZE, ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_Borders)) {

        // �J�����̕���ݒ�
        for (int i = 0; i < GRID_FULL_SIZE; ++i) {
            ImGui::TableSetupColumn("##", ImGuiTableColumnFlags_WidthFixed, cell_size);
        }

        // �e�[�u���̃Z����`��
        for (int r = 0; r < GRID_FULL_SIZE; ++r) {
            ImGui::TableNextRow();
            for (int c = 0; c < GRID_FULL_SIZE; ++c) {
                ImGui::TableSetColumnIndex(c);

                // Corrected logic for header cells
                if (r < HEADER_SIZE || c < HEADER_SIZE) {
                    // Header Part
                    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.9f, 0.9f, 0.9f, 1.0f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.9f, 0.9f, 0.9f, 1.0f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.9f, 0.9f, 0.9f, 1.0f));

                    // Use a button with the text as its label, ensuring a consistent size.
                    std::string header_id = "header_" + std::to_string(r) + "_" + std::to_string(c);
                    if (r < HEADER_SIZE && c < HEADER_SIZE) {
                        ImGui::Button(" ", ImVec2(cell_size, cell_size)); // Use space as a label
                    }
                    else if (r < HEADER_SIZE) {
                        ImGui::Button(std::to_string(c - HEADER_SIZE + 1).c_str(), ImVec2(cell_size, cell_size));
                    }
                    else {
                        ImGui::Button(std::to_string(r - HEADER_SIZE + 1).c_str(), ImVec2(cell_size, cell_size));
                    }
                    ImGui::PopStyleColor(3);
                }
                else {
                    // �Q�[���v���C�G���A
                    int grid_r = r - HEADER_SIZE;
                    int grid_c = c - HEADER_SIZE;

                    // ���w��̃��W�b�N�Ɋ�Â��ĐF�ƃe�L�X�g������
                    int mod_val = (grid_r + grid_c) % 3;

                    ImVec4 button_color;
                    const char* text_label = "";

                    if (mod_val == 0) {
                        button_color = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
                    }
                    else if (mod_val == 1) {
                        button_color = ImVec4(0.8f, 0.8f, 0.8f, 1.0f);
                        text_label = "X";
                    }
                    else {
                        button_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
                    }

                    ImGui::PushStyleColor(ImGuiCol_Button, button_color);
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.7f, 0.7f, 0.7f, 1.0f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.5f, 0.5f, 0.5f, 1.0f));

                    std::string id = "cell_" + std::to_string(grid_r) + "_" + std::to_string(grid_c);
                    if (ImGui::Button(text_label, ImVec2(cell_size, cell_size))) {
                        // �N���b�N���̓���������ɋL�q
                    }
                    ImGui::PopStyleColor(3);
                }
            }
        }
        ImGui::EndTable();
    }

    ImGui::End();
}
int main() {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // GLFW��OpenGL�̃o�[�W�����q���g
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // �E�B���h�E�쐬
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Nonogram UI", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // GLAD�̏�����
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "Failed to initialize GLAD\n");
        return 1;
    }

    // Dear ImGui�R���e�L�X�g�̍쐬�Ə�����
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    // ���C�����[�v
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // ImGui�̐V�����t���[�����J�n
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // UI�̕`��֐����Ăяo��
        RenderNonogramUI();

        // �`��ƕ\��
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f); // �w�i�F
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // �N���[���A�b�v
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}