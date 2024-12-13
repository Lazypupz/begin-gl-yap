#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Shader { 
    public:


        unsigned int ID;


        void ShaderCompile(std::string& vPath, std::string& fPath){
            std::string vertexCode = LoadShader(vPath);
            std::string fragmentCode = LoadShader(fPath);

            unsigned int vertex = CompileShader(GL_VERTEX_SHADER, vertexCode);
            unsigned int fragment = CompileShader(GL_FRAGMENT_SHADER, fragmentCode);

            ID = glCreateProgram();
            glAttachShader(ID, vertex);
            glAttachShader(ID, fragment);
            glLinkProgram(ID);
            checkShaderCompilation(ID, "PROGRAM");

            glDeleteShader(vertex);
            glDeleteShader(fragment);

        }

        void Use() const{
            glUseProgram(ID);
        }


    private:
        static std::string LoadShader(const std::string& filepath){
            std::ifstream file(filepath);
            if(!file.is_open()){
                throw std::runtime_error("Failed to Open Shader File" + filepath);
            }

            std::stringstream buffer;
            buffer << file.rdbuf();
            return  buffer.str();
        }


        static void checkShaderCompilation(unsigned int shader, const std::string& type){
            int succcess;
            char infolog[512];
            
            if(type != "PROGRAM"){
                glGetShaderiv(shader, GL_COMPILE_STATUS, &succcess);
                if(!succcess){
                    glGetShaderInfoLog(shader, 512, NULL, infolog);
                    std::cerr << "Compilation Failed " << type << infolog << std::endl;
                }
            }else{
                glGetShaderiv(shader, GL_LINK_STATUS, &succcess);
                if(!succcess){
                    glGetShaderInfoLog(shader, sizeof(infolog) * sizeof(char), nullptr, infolog);
                    std::cerr << "Linking failed  " << type << "\n" << infolog << std::endl;
                }
            }

            
        }
        static unsigned int CompileShader(unsigned int type, const std::string source){
            unsigned int shader = glCreateShader(type);
            const char* src = source.c_str();
            glShaderSource(shader, 1 ,&src, nullptr);
            glCompileShader(shader);

            checkShaderCompilation(shader, type == GL_VERTEX_SHADER ?  "GL_VERTEX_SHADER" : "GL_FRAGMENT_SHADER");
        }

};


float treeVertices[] = {
    
    //topo triangle
    0.0f, 0.6f, 0.0f,
   -0.35f, 0.1f, 0.0f,
    0.35f, 0.1f, 0.0f,
    //middle triangle
    0.0f, 0.4f, 0.0f,
   -0.41f, -0.1f, 0.0f,   
    0.41f, -0.1f, 0.0f,
    //bottom triangle
    0.0f,  0.2f, 0.0f,
   -0.51f, -0.3f, 0.0f,
    0.51f, -0.3f, 0.0f
};


float trunkVertices[] = {
    -0.1f, -0.3f, 0.0f,  
    0.1f, -0.3f, 0.0f,  
    -0.1f, -0.7f, 0.0f,  
    0.1f, -0.7f, 0.0f,  
};


GLuint treeVBO, treeVAO, trunkVAO, trunkVBO;


void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0,width,height);
}


int initWinGLFW(GLFWwindow*& window) {
     
    if (!glfwInit()) {
        std::cerr << "Failed to init glfw" << std::endl;
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    

    window = glfwCreateWindow(800, 600, "CHRISTMAS TREE", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to display window" << std::endl;
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

   
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "failed to init GLAD" << std::endl;
        return -1;
    }
    return 0;
}



void treeObjects() {



    glGenVertexArrays(1, &treeVAO);
    glGenBuffers(1, &treeVBO);
    glBindVertexArray(treeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, treeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(treeVertices), treeVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    

    glGenVertexArrays(1, &trunkVAO);
    glGenBuffers(1, &trunkVBO);
    glBindVertexArray(trunkVAO);
    glBindBuffer(GL_ARRAY_BUFFER, trunkVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(trunkVertices), trunkVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    
}

int main(void) {
    
    GLFWwindow* window;
    initWinGLFW(window);

    treeObjects();

    Shader shader;

    
    GLuint uniTreeColour = glGetUniformLocation(Use(), "treeColour");
    GLuint uniTrunkColour = glGetUniformLocation(shaderProgram, "treeColour");


    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.67f, 0.84f, 1.0f, 1.0f); // light blue
        glClear(GL_COLOR_BUFFER_BIT);
        
        shader.ShaderCompile()
        glUseProgram(shaderProgram);

        glUniform4f(uniTreeColour, 0.0f, 1.0f, 0.0f, 1.0f);
        glBindVertexArray(treeVAO);
        glDrawArrays(GL_TRIANGLES, 0, 9); 

        glUniform4f(uniTrunkColour, 0.55f, 0.27f, 0.07f, 1.0f);
        glBindVertexArray(trunkVAO);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}

