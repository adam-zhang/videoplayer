cmake_minimum_required(VERSION 3.5)
project(VideoPlayer)
add_definitions(-Wall)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets CONFIG REQUIRED)
set(sources main.cpp
	MainWidget.cpp
	VideoWidget.cpp
	ControlWidget.cpp
	MainWindow.cpp)
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
