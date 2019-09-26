cmake_minimum_required(VERSION 3.5)
project(CellTrack_GUI)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5MultimediaWidgets REQUIRED)

add_executable(CellTrack main.cpp
	scene_delegate.hpp scene_delegate.cpp
	matlab_widget.hpp matlab_widget.cpp
	video_view.hpp video_view.cpp
	video_groupbox.hpp video_groupbox.cpp
	control_panel.hpp control_panel.cpp
	file_combobox.hpp file_combobox.cpp
	log_view.hpp log_view.cpp
	core.hpp core.cpp
	file_finder.hpp file_finder.cpp
	intro_widget.hpp intro_widget.cpp
	log_preview.hpp log_preview.cpp
	general_view.hpp general_view.cpp
	hidden_var_view.hpp hidden_var_view.cpp
)
set_property(TARGET CellTrack PROPERTY CXX_STANDARD 11)
target_link_libraries(CellTrack Qt5::Widgets Qt5::MultimediaWidgets)
