#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(){
    if(!glfwInit()){
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600 , "Dia duit", nullptr, nullptr);
    if(!window){
        std::cerr << "Failed to create the window" << std::endl;
        glfwTerminate();
        return -1;
    }
}