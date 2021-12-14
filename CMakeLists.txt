cmake_minimum_required(VERSION 3.10)

project(window)

add_subdirectory(glad)
add_subdirectory(imgui)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL)

add_subdirectory(glfw)

include_directories(imgui)

add_executable(window main.cpp)

target_link_libraries(window OpenGL::GL)
target_link_libraries(window glad)
target_link_libraries(window imgui)
target_link_libraries(window glfw)


target_include_directories(window PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/glad"
                            "${PROJECT_SOURCE_DIR}/glfw/include"
                        )