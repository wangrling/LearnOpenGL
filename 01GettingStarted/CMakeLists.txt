cmake_minimum_required(VERSION 2.8)

add_compile_options(-std=c++11)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${OPENGL_INCLUDE_DIR} ${GLFW_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/glad/include)

add_executable(01hello_window_clear 01hello_window_clear.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c)
target_link_libraries(01hello_window_clear ${OPENGL_LIBRARIES} glfw dl)

add_executable(02hello_triangle 02hello_triangle.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c)
target_link_libraries(02hello_triangle ${OPENGL_LIBRARIES} glfw dl)

add_executable(03shader_program 03shader_program.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c)
target_link_libraries(03shader_program ${OPENGL_LIBRARIES} glfw dl)

add_executable(04textures_combined 04textures_combined.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c ${PROJECT_SOURCE_DIR}/stb_image.cpp)
target_link_libraries(04textures_combined ${OPENGL_LIBRARIES} glfw dl)

add_executable(05transformation_matrix 05transformation_matrix.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c ${PROJECT_SOURCE_DIR}/stb_image.cpp)
target_link_libraries(05transformation_matrix ${OPENGL_LIBRARIES} glfw dl glm)

add_executable(06coordinate_system 06coordinate_system.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c ${PROJECT_SOURCE_DIR}/stb_image.cpp)
target_link_libraries(06coordinate_system ${OPENGL_LIBRARIES} glfw dl glm)