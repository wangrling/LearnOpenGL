cmake_minimum_required(VERSION 2.8)

add_compile_options(-std=c++11)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${OPENGL_INCLUDE_DIR} ${GLFW_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/glad/include)

add_executable(11color_test 11color_test.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c ${PROJECT_SOURCE_DIR}/stb_image.cpp)
target_link_libraries(11color_test ${OPENGL_LIBRARIES} glfw dl glm)

add_executable(12ambient_diffuse 12ambient_diffuse.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c ${PROJECT_SOURCE_DIR}/stb_image.cpp)
target_link_libraries(12ambient_diffuse ${OPENGL_LIBRARIES} glfw dl glm)

add_executable(13specular_light 13specular_light.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c ${PROJECT_SOURCE_DIR}/stb_image.cpp)
target_link_libraries(13specular_light ${OPENGL_LIBRARIES} glfw dl glm)

add_executable(14materials 14materials.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c ${PROJECT_SOURCE_DIR}/stb_image.cpp)
target_link_libraries(14materials ${OPENGL_LIBRARIES} glfw dl glm)

add_executable(15diffuse_map 15diffuse_map.cpp ${PROJECT_SOURCE_DIR}/stb_image.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c ${PROJECT_SOURCE_DIR}/stb_image.cpp)
target_link_libraries(15diffuse_map ${OPENGL_LIBRARIES} glfw dl glm)

add_executable(16specular_map 16specular_map.cpp ${PROJECT_SOURCE_DIR}/stb_image.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c ${PROJECT_SOURCE_DIR}/stb_image.cpp)
target_link_libraries(16specular_map ${OPENGL_LIBRARIES} glfw dl glm)

add_executable(17direction_light 17direction_light.cpp ${PROJECT_SOURCE_DIR}/stb_image.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c ${PROJECT_SOURCE_DIR}/stb_image.cpp)
target_link_libraries(17direction_light ${OPENGL_LIBRARIES} glfw dl glm)

add_executable(18point_light 18point_light.cpp ${PROJECT_SOURCE_DIR}/stb_image.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c ${PROJECT_SOURCE_DIR}/stb_image.cpp)
target_link_libraries(18point_light ${OPENGL_LIBRARIES} glfw dl glm)

add_executable(19flash_light 19flash_light.cpp ${PROJECT_SOURCE_DIR}/stb_image.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c ${PROJECT_SOURCE_DIR}/stb_image.cpp)
target_link_libraries(19flash_light ${OPENGL_LIBRARIES} glfw dl glm)

add_executable(20soft_edge_light 20soft_edge_light.cpp ${PROJECT_SOURCE_DIR}/stb_image.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c ${PROJECT_SOURCE_DIR}/stb_image.cpp)
target_link_libraries(20soft_edge_light ${OPENGL_LIBRARIES} glfw dl glm)

add_executable(21multiple_light 21multiple_light.cpp ${PROJECT_SOURCE_DIR}/stb_image.cpp ${PROJECT_SOURCE_DIR}/glad/src/glad.c ${PROJECT_SOURCE_DIR}/stb_image.cpp)
target_link_libraries(21multiple_light ${OPENGL_LIBRARIES} glfw dl glm)