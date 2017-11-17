cmake_minimum_required(VERSION 2.8)

project(opengl)

# OpenGL Mathematics
add_subdirectory(${PROJECT_SOURCE_DIR}/glm-0.9.8.5)

# Model loading library
add_subdirectory(${PROJECT_SOURCE_DIR}/assimp-4.0.1)

add_subdirectory(01GettingStarted)
add_subdirectory(02Lighting)
add_subdirectory(03ModelLoading)