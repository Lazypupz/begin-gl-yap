cmake_minimum_required(VERSION 3.10)

# Set the project name
project(BeginGLYap)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(BeginGLYap mmain.cpp)

# Find OpenGL
find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIRS})
    target_link_libraries(BeginGLYap ${OPENGL_LIBRARIES})
endif()

# Find GLUT
find_package(GLUT REQUIRED)
if (GLUT_FOUND)
    include_directories(${GLFW_INCLUDE_DIRS})
    target_link_libraries(BeginGLYap ${GLFW_INCLUDE_DIRS})
endif()