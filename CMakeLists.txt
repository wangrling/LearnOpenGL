cmake_minimum_required(VERSION 2.8)

project(opengl)

add_compile_options(-std=c++11)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${OPENGL_INCLUDE_DIR} ${GLFW_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/glad/include)

# OpenGL Mathematics
add_subdirectory(${PROJECT_SOURCE_DIR}/glm-0.9.8.5)
