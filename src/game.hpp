#pragma once
#include "common.hpp"
class Game{
public:
    Game();
        
private:
    GLFWwindow* window;

    int initWin();

    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};