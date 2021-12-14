#include <stdio.h>
#include <iostream>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui.h"

#include "MainWindow.cpp"

// Compile 'g++ main.cpp -o main glad.o -lglfw -ldl -I.'

int main()
{
    if(!glfwInit())
    {
        printf("Failed to initialize GLFW.");
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    const int windowWidth = 800;
    const int windowHeight = 600;
    const char* windowTitle = "Main";
    GLFWwindow* mainWindow = glfwCreateWindow(
        windowWidth,
        windowHeight,
        windowTitle,
        nullptr, // glfwPrimaryMonitor() for full-screen
        nullptr // resoure sharing
);

    if (mainWindow == nullptr)
    {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(mainWindow);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize Glad.\n");
        return -1;
    }

    glfwSetCursorEnterCallback(mainWindow, mouseIn);
    glfwSetKeyCallback(mainWindow, key_callback);

    glViewport(0, 0, windowWidth, windowHeight);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui_ImplGlfw_InitForOpenGL(mainWindow, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    MainWindow Window;

    ImGui::SetNextWindowPos(ImVec2(100, 275));

    while (!glfwWindowShouldClose(mainWindow))
    {
        Window.CreateWindow(mainWindow);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(mainWindow);

    glfwTerminate();

}