set(SRCS
    imgui.cpp
    imgui_demo.cpp
    imgui_draw.cpp
    imgui_impl_glfw.cpp
    imgui_impl_opengl3.cpp
    imgui_tables.cpp
    imgui_widgets.cpp
    )

add_library(imgui STATIC ${SRCS})
target_include_directories(imgui PUBLIC 
                            "${CMAKE_CURRENT_SOURCE_DIR}"
                            "${PROJECT_SOURCE_DIR}/glfw/include"
                            )