TEMPLATE = app
TARGET = CellTrack

QT += network \
      xml \
      multimedia \
      multimediawidgets \
      widgets

HEADERS = \
    scene_delegate.hpp \
    matlab_widget.hpp \
    video_view.hpp \
    video_groupbox.hpp \
    control_panel_groupbox.hpp \
    file_combobox.hpp \
    log_view.hpp \
    core.hpp \
    file_finder.hpp \
    intro_widget.hpp \
    log_preview.hpp \
    general_view.hpp \
    hidden_var_view.hpp \
    run_groupbox.hpp \
    var_item.hpp \
    user_data.hpp \
    python_widget.hpp \
    process_view.hpp \
    radar.hpp

SOURCES = main.cpp \
    scene_delegate.cpp \
    matlab_widget.cpp \
    video_view.cpp \
    video_groupbox.cpp \
    control_panel_groupbox.cpp \
    file_combobox.cpp \
    log_view.cpp \
    core.cpp \
    file_finder.cpp \
    intro_widget.cpp \
    log_preview.cpp \
    general_view.cpp \
    hidden_var_view.cpp \
    run_groupbox.cpp \
    var_item.cpp \
    user_data.cpp \
    python_widget.cpp \
    process_view.cpp \
    radar.cpp

target.path = /Users/xuanli/Developer/CellTrack_GUI/src
INSTALLS += target
ICON = appIcon.icns
