cmake_minimum_required(VERSION 2.8)

add_compile_options(-std=c++11)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${OPENGL_INCLUDE_DIR} ${GLFW_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/glad/include)

add_executable(23depth_testing 23depth_testing.cpp ${PROJECT_SOURCE_DIR}/stb_image.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c ${PROJECT_SOURCE_DIR}/stb_image.cpp)
target_link_libraries(23depth_testing ${OPENGL_LIBRARIES} glfw dl glm assimp)