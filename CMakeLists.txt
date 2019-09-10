cmake_minimum_required(VERSION 3.5)
project(CellTrack_GUI)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5MultimediaWidgets REQUIRED)

add_executable(CellTrack main.cpp
	scene_delegate.hpp scene_delegate.cpp
	content_view.hpp content_view.cpp
	display_widget.hpp display_widget.cpp
	video_groupbox.hpp video_groupbox.cpp
	control_panel_groupbox.hpp control_panel_groupbox.cpp
	file_combobox.hpp file_combobox.cpp
	log_widget.hpp log_widget.cpp
	core.hpp core.cpp
	file_finder.hpp file_finder.cpp
	pre_setting_view.hpp pre_setting_view.cpp
	log_preview.hpp log_preview.cpp
)
set_property(TARGET CellTrack PROPERTY CXX_STANDARD 11)
target_link_libraries(CellTrack Qt5::Widgets Qt5::MultimediaWidgets)
