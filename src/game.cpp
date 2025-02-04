
#include "game.hpp"



Game::Game()
{
    initWin();
}

GLFWwindow* window;




int Game::initWin(){
    if(!glfwInit){ 
        std::cerr << "Failed to init GLFW" << std::endl;
        return -1;
    }
    glfwWindowHint(GLFW_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    window = glfwCreateWindow(800,600,"main", nullptr, nullptr);
    if(!window){
        std::cerr << "Failed to create window" << std::endl;
        return -1;
    }
    glfwGetCurrentContext();

    if(!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))){
        std::cerr << "NO GLAD" << std::endl;
        return -1;
    }

    while(!glfwWindowShouldClose){
        glClearColor(1.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();


    }
    glfwTerminate();
    return 0;
}

int main(){
    Game();
}

