TEMPLATE = app
TARGET = cell

QT += network \
      xml \
      multimedia \
      multimediawidgets \
      widgets

HEADERS = \
    cell_app.hpp \
    display_widget.hpp \
    video_groupbox.hpp \
    control_panel_groupbox.hpp \
    file_combobox.hpp \
    log_widget.hpp \
    core.hpp \
    file_finder.hpp \
    setting_app.hpp
SOURCES = cell.cpp \
    cell_app.cpp \
    display_widget.cpp \
    video_groupbox.cpp \
    control_panel_groupbox.cpp \
    file_combobox.cpp \
    log_widget.cpp \
    core.cpp \
    file_finder.cpp \
    setting_app.cpp

target.path = /Users/xuanli/Desktop/cell/src
INSTALLS += target
