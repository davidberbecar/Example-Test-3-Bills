cmake_minimum_required(VERSION 3.31)
project(Example_Test_3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(Qt6_DIR "/Users/davidberbecar/Qt/6.9.0/macos/lib/cmake/Qt6")
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

add_executable(Example_Test_3 main.cpp
        Bill.h
        Bill.cpp
        Repository.h
        Repository.cpp
        Service.h
        Service.cpp
        gui.cpp
        gui.h
        gui.ui
)

target_link_libraries(Example_Test_3
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)