cmake_minimum_required(VERSION 3.25)
project(mini_cad_v1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets OpenGL OpenGLWidgets REQUIRED)
find_package(OpenCASCADE REQUIRED)

add_executable(mini_cad
    main.cpp
    mainwindow.cpp
    occtviewer.cpp

    mainwindow.h
    occtviewer.h

    commands/CreateBoxCommand.cpp
    commands/Command.h
    commands/CreateBoxCommand.h
    commands/CreateCylinderCommand.h
    commands/CreateSphereCommand.h
    history/CommandManager.h
    commands/CreateSphereCommand.cpp
    commands/CreateCylinderCommand.cpp
    history/CommandManager.cpp

    Doxyfile
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
