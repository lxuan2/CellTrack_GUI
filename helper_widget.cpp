//
//  helper_widget_intro.cpp
//  CellTrack
//
//  Created by Xuan Li on 10/25/19.
//

#include "helper_widget.hpp"

HelperWidget_Intro::HelperWidget_Intro():QDialog(QApplication::focusWidget()) {
    setWindowModality(Qt::WindowModal);
}

HelperWidget_Log::HelperWidget_Log():QDialog(QApplication::focusWidget()) {
    setWindowModality(Qt::WindowModal);
}

HelperWidget_Hidden::HelperWidget_Hidden():QDialog(QApplication::focusWidget()) {
    setWindowModality(Qt::WindowModal);
}

HelperWidget_General_Py::HelperWidget_General_Py():QDialog(QApplication::focusWidget()) {
    setWindowModality(Qt::WindowModal);
}
