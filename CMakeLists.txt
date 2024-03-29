cmake_minimum_required(VERSION 3.5)
project(CellTrack_GUI)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5MultimediaWidgets REQUIRED)

add_executable(CellTrack main.cpp
	scene_delegate.hpp scene_delegate.cpp
	matlab_widget.hpp  matlab_widget.cpp
	video_view.hpp     video_view.cpp
	video_groupbox.hpp video_groupbox.cpp
	parameter_groupbox.hpp parameter_groupbox.cpp
	file_combobox.hpp  file_combobox.cpp
	log_view.hpp       log_view.cpp
	core.hpp           core.cpp
	file_finder.hpp    file_finder.cpp
	intro_widget.hpp   intro_widget.cpp
	log_preview.hpp    log_preview.cpp
	general_view.hpp   general_view.cpp
	hidden_var_view.hpp hidden_var_view.cpp
	run_groupbox.hpp   run_groupbox.cpp
	var_item.hpp       var_item.cpp
	user_data.hpp      user_data.cpp
	python_widget.hpp  python_widget.cpp
	process_view.hpp   process_view.cpp
	radar.hpp	   radar.cpp
	parameter_model.hpp parameter_model.cpp
	helper_widget.hpp  helper_widget.cpp
)
# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
target_link_libraries(CellTrack Qt5::Widgets Qt5::MultimediaWidgets)
