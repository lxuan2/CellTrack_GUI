//
//  helper_widget_intro.cpp
//  CellTrack
//
//  Created by Xuan Li on 10/25/19.
//

#include "helper_widget.hpp"

HelperWidget::HelperWidget():QDialog(QApplication::focusWidget()) {
    setWindowModality(Qt::WindowModal);
}
