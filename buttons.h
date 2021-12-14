#include <GLFW/glfw3.h>

#pragma once

namespace Input{
    void joystick();
    int moveRight;
    int moveLeft;
    int fullscreen;
}

#ifdef __linux__
    int STEAM_RIGHTTP_TAP = 0;
    int STEAM_LEFTTP_TAP = 1; 
    int STEAM_A = 2;
    int STEAM_B = 3;
    int STEAM_X = 4;
    int STEAM_Y = 5;
    int STEAM_L = 6;
    int STEAM_R = 7;
    int STEAM_ZL = 8;
    int STEAM_ZR = 9;
    int STEAM_SL = 10;
    int STEAM_SR = 11;
    int STEAM_S = 12;
    int STEAM_LS = 13;
    int STEAM_LTP = 14;
    int STEAM_BL = 15;
    int STEAM_BR = 16;
    int STEAM_DU = 17;
    int STEAM_DD = 18;
    int STEAM_DL = 19;
    int STEAM_DR = 20;
#else
    int STEAM_RIGHTTP_TAP = 21;
    int STEAM_LEFTTP_TAP = 20; 
    int STEAM_A = 0;
    int STEAM_B = 1;
    int STEAM_X = 2;
    int STEAM_Y = 3;
    int STEAM_L = 4;
    int STEAM_R = 5;
    int STEAM_ZL = 21;
    int STEAM_ZR = 20;
    int STEAM_SR = 8;
    int STEAM_SL = 9;
    int STEAM_DU = 11;
    int STEAM_DD = 12;
    int STEAM_DL = 13;
    int STEAM_DR = 14;    
    int STEAM_S = 10;
    int STEAM_LS = 6;
    int STEAM_RTP = 7;
    int STEAM_BL = 15;
    int STEAM_BR = 16;

#endif  