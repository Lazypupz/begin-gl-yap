#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdlib.h>


int scrnWidth = 800;
int scrnHeight = 600;

void framebuffer_size_callback(GLFWwindow* window,int width, int height){
    glViewport(0,0,width,height);


}

int main(){
    if(!glfwInit()){
        std::cerr << "failed to init glfw" << std::endl;
        return -1;
    }
    glfwWindowHint(GLFW_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(scrnWidth, scrnHeight, "Minecraft", nullptr, nullptr);
    if(!window){
        std::cerr << "Failed to create the window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cerr << "failed to make glad" << std::endl;
        return -1;

    }
    float verts[] = {
        -0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.5f, 0.0f, 0.0f
    };

    unsigned int VBO, VAO;
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);



    

    return 0;
}