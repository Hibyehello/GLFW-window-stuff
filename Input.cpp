#include <GLFW/glfw3.h>
#include "glad/glad.h"
#include "buttons.h"
#include <stdio.h>

int quit = 0;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_W && action == GLFW_PRESS)
    {
        printf("W pressed\n");
    }
    
    if (key == GLFW_KEY_F && action == GLFW_PRESS && Input::fullscreen == 0) 
    {
        glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, 1920, 1080, 60);
        Input::fullscreen = 1;
    } else if (key == GLFW_KEY_F && action == GLFW_PRESS && Input::fullscreen == 1) 
    {
         glfwSetWindowMonitor(window, nullptr, 0, 0, 800, 600, 60);
         Input::fullscreen = 0;
    }

    if (key == GLFW_KEY_Q && action == GLFW_PRESS) {
        quit = 1;
    }
}

void mouseIn(GLFWwindow* window, int entered) {
    if (entered)
    {
        printf("Mouse in window\n");
    } else
    {
        printf("Mouse left window\n");
    }
}

//void joystick_callback(int jid, int event)
//{
//        if (glfwJoystickIsGamepad(GLFW_JOYSTICK_2))
//    {
//        printf("Joystick connected!");
//    }
//
//}

void joystick(){
    int present = glfwJoystickPresent(GLFW_JOYSTICK_1);

    int axesCount;
    int buttonCount;

    const float *axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCount);
    const unsigned char *buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount);

    if(1 == present) {
        int pressed = 0;

        printf("\n\n\n\n\n\n\n");
        printf("Axes Count: %d\n", axesCount);
        printf("Left Stick X axis: %f\n", axes[0]);
        printf("Left Stick Y axis: %f\n", axes[1]);
        printf("Right Stick X axis: %f\n", axes[3]);
        printf("Right Stick Y axis: %f\n", axes[4]);
        printf("Left Analog Shoulder: %f\n", axes[2]);
        printf("Right Analog Shoulder: %f\n", axes[5]);

        if(axes[0] > 0.2){
             Input::moveLeft = 0;
             Input::moveRight = 1;
        } else if(axes[0] < -0.2){
             Input::moveRight = 0;
             Input::moveLeft = 1;
        } else {
             Input::moveRight = 0;
             Input::moveLeft = 0;
        }

        if(GLFW_PRESS == buttons[STEAM_A]){
            printf("A button pressed\n");
        }
        if(GLFW_PRESS == buttons[STEAM_B]){
            printf("B button pressed\n");
        }

        if(GLFW_PRESS == buttons[STEAM_X]){
            printf("X button pressed\n");
        }

         if(GLFW_PRESS == buttons[STEAM_Y]){
             printf("Y button pressed\n");
        }
        
        if(GLFW_PRESS == buttons[STEAM_L]){
             printf("Left Shoulder button pressed\n");
        }
        
        if(GLFW_PRESS == buttons[STEAM_R]){
             printf("Right Shoulder button pressed\n");
        }

        if(GLFW_PRESS == buttons[STEAM_ZL]){
             printf("Left Analog Shoulder button pressed\n");
        }
        
        if(GLFW_PRESS == buttons[STEAM_ZR]){
             printf("Right Analog Shoulder button pressed\n");
        }

        if(GLFW_PRESS == buttons[STEAM_SL]){
             printf("Start Left button pressed\n");
        }

        if(GLFW_PRESS == buttons[STEAM_SR]){
             printf("Start Right button pressed\n");
        }

        if(GLFW_PRESS == buttons[STEAM_S]){
             printf("Start button pressed\n");
        }

        if(GLFW_PRESS == buttons[STEAM_LS]){
             printf("Left Stick button pressed\n");
        }

        if(GLFW_PRESS == buttons[STEAM_RTP]){
             printf("Right Touchpad Clicked button pressed\n");
        }

        if(GLFW_PRESS == buttons[STEAM_BL]){
             printf("Back Left button pressed\n");
        }

        if(GLFW_PRESS == buttons[STEAM_BR]){
             printf("Back Right button pressed\n");
        }

        if(GLFW_PRESS == buttons[STEAM_DU]){
             printf("D-Up pressed\n");
        }

        if(GLFW_PRESS == buttons[STEAM_DR]){
             printf("D-Right pressed\n");
        }

        if(GLFW_PRESS == buttons[STEAM_DD]){
             printf("D-Down pressed\n");
        }

        if(GLFW_PRESS == buttons[STEAM_DL]){
             printf("D-Left pressed\n");
        }
    }
}

