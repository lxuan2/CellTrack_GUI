TEMPLATE = app
TARGET = CellTrack

QT += network \
      xml \
      multimedia \
      multimediawidgets \
      widgets

HEADERS = \
    scene_delegate.hpp \
    content_view.hpp \
    display_widget.hpp \
    video_groupbox.hpp \
    control_panel_groupbox.hpp \
    file_combobox.hpp \
    log_widget.hpp \
    core.hpp \
    file_finder.hpp \
    pre_setting_view.hpp

SOURCES = main.cpp \
    scene_delegate.cpp \
    content_view.cpp \
    display_widget.cpp \
    video_groupbox.cpp \
    control_panel_groupbox.cpp \
    file_combobox.cpp \
    log_widget.cpp \
    core.cpp \
    file_finder.cpp \
    pre_setting_view.cpp

target.path = /Users/xuanli/Developer/CellTrack_GUI/src
INSTALLS += target
ICON = appIcon.icns
