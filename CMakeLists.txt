cmake_minimum_required(VERSION 3.25)
project(mini_cad_v1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets OpenGL OpenGLWidgets REQUIRED)
find_package(OpenCASCADE REQUIRED)
find_package(glfw3 REQUIRED)

set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/imgui")

set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

add_executable(mini_cad
    main.cpp
    mainwindow.cpp
    occtviewer.cpp

    commands/CreateBoxCommand.cpp
    commands/CreateSphereCommand.cpp
    commands/CreateCylinderCommand.cpp
    history/CommandManager.cpp

    ${IMGUI_SOURCES}
)

target_link_libraries(mini_cad PRIVATE
    Qt6::Widgets
    Qt6::OpenGL
    Qt6::OpenGLWidgets
    glfw

    TKernel
    TKMath
    TKBRep
    TKGeomBase
    TKGeomAlgo
    TKPrim
    TKBO
    TKTopAlgo
    TKV3d
    TKOpenGl
)

target_include_directories(mini_cad PRIVATE
    ${OpenCASCADE_INCLUDE_DIR}
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)

enable_testing()

add_executable(tests
    tests/test_command_manager.cpp
    history/CommandManager.cpp
)

target_link_libraries(tests
    gtest gtest_main
    pthread
)
