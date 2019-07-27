cmake_minimum_required(VERSION 3.5)
project(Cell)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5MultimediaWidgets REQUIRED)

add_executable(cell cell.cpp
	cell_app.hpp cell_app.cpp
	display_widget.hpp display_widget.cpp
	video_groupbox.hpp video_groupbox.cpp
	control_panel_groupbox.hpp control_panel_groupbox.cpp
	file_combobox.hpp file_combobox.cpp
	log_widget.hpp log_widget.cpp)
set_property(TARGET cell PROPERTY CXX_STANDARD 11)
target_link_libraries(cell Qt5::Widgets Qt5::MultimediaWidgets)