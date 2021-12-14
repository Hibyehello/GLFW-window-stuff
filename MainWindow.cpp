#include <stdio.h>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui.h"

#include "Input.cpp"
#include "imWin.cpp"

class MainWindow{
    public:
        void CreateWindow(GLFWwindow* window);
};

void MainWindow::CreateWindow(GLFWwindow* window)
    {              // RED ------------ Green --------- Blue
        glClearColor(46.0f / 255.0f, 68.0f / 255.0f, 153.0f / 255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        joystick();
        imWin(window);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
        glfwPollEvents();

        if(quit == 1){
            glfwDestroyWindow(window);
            glfwTerminate();
        }
    }
