#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "buttons.h"

#include <string>

int x = 100;
int y = 275;

std::string string = "Hello Imgui";

int w;
int h;

void imWin(GLFWwindow* window){
    glfwGetWindowSize(window, &w, &h);
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_NoBackground;
    window_flags |= ImGuiWindowFlags_NoMove;
    //window_flags |= ImGuiWindowFlags_NoNavFocus;
    window_flags |= ImGuiWindowFlags_NoTitleBar;
    window_flags |= ImGuiWindowFlags_NoResize;
    //window_flags |= ImGuiWindowFlags_AlwaysAutoResize;

    bool* open_ptr = new bool(true);
    ImGui::Begin("ImGUI window", open_ptr, window_flags); 
    if(Input::fullscreen == 0){
        if(x > h+200) {
            x = 0;
        }
        if(x < -50) {
        x = h+200;
        }
    } else {
        if(x > h+800) {
            x = 0;
        }
        if(x < -50) {
        x = h+800;
        }
    }

    if(Input::moveRight == 1) {
        ImGui::SetWindowPos(ImVec2(x, y));
        x = x + 4;
    }
    if(Input::moveLeft == 1) {
        ImGui::SetWindowPos(ImVec2(x, y));
        x = x - 4;
    }
    ImGui::Text("Hello ImGui!");
    ImGui::End();
}