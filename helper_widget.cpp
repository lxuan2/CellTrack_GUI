//
//  helper_widget_intro.cpp
//  CellTrack
//
//  Created by Xuan Li on 10/25/19.
//

#include "helper_widget.hpp"

HelperWidget::HelperWidget(QString name):QDialog(QApplication::focusWidget()) {
    group = new QGroupBox();
    
    if (name == "intro")
        createIntro();
    else if (name == "py_general")
        createPyGeneral();
    else if (name == "py_hidden")
        createPyHidden();
    else if (name == "ma_general")
        createMaGeneral();
    else if (name == "log")
        createLog();
    else
        createError();
    
    done = new QPushButton("  Done  ");
    QObject::connect(done, &QPushButton::clicked, this, &HelperWidget::accept);
    
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(group, 0, 0, 5, 5);
    layout->addWidget(done, 5, 4, Qt::AlignRight);
    setLayout(layout);
    setWindowModality(Qt::WindowModal);
    
    // set white background
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
}

void HelperWidget::createIntro() {
    QGridLayout *layout = new QGridLayout();
    
    QPixmap map(QCoreApplication::applicationDirPath() + "/Resources/help_intro.png");
    map.setDevicePixelRatio(2);
    QLabel *label= new QLabel();
    label->setPixmap(map);
    label->setAlignment(Qt::AlignCenter);
    
    layout->addWidget(label);
    group->setLayout(layout);
}

void HelperWidget::createPyGeneral() {
    QGridLayout *layout = new QGridLayout();
    
    QPixmap map(QCoreApplication::applicationDirPath() + "/Resources/help_py_general.png");
    map.setDevicePixelRatio(2);
    QLabel *label= new QLabel();
    label->setPixmap(map);
    label->setAlignment(Qt::AlignCenter);
    
    layout->addWidget(label);
    group->setLayout(layout);
}

void HelperWidget::createPyHidden() {
    QGridLayout *layout = new QGridLayout();
    
    QPixmap map(QCoreApplication::applicationDirPath() + "/Resources/help_py_hidden.png");
    map.setDevicePixelRatio(2);
    QLabel *label= new QLabel();
    label->setPixmap(map);
    label->setAlignment(Qt::AlignCenter);
    
    layout->addWidget(label);
    group->setLayout(layout);
}

void HelperWidget::createMaGeneral() {
    QGridLayout *layout = new QGridLayout();
    
    QPixmap map(QCoreApplication::applicationDirPath() + "/Resources/help_ma_general.png");
    map.setDevicePixelRatio(2);
    QLabel *label= new QLabel();
    label->setPixmap(map);
    label->setAlignment(Qt::AlignCenter);
    
    layout->addWidget(label);
    group->setLayout(layout);
}

void HelperWidget::createLog() {
    QGridLayout *layout = new QGridLayout();
    
    QPixmap map(QCoreApplication::applicationDirPath() + "/Resources/help_log.png");
    map.setDevicePixelRatio(2);
    QLabel *label= new QLabel();
    label->setPixmap(map);
    label->setAlignment(Qt::AlignCenter);
    
    layout->addWidget(label);
    group->setLayout(layout);
}

void HelperWidget::createError() {
    QGridLayout *layout = new QGridLayout();
    
    QPixmap map(QCoreApplication::applicationDirPath() + "/Resources/help_error.png");
    map.setDevicePixelRatio(2);
    QLabel *label= new QLabel();
    label->setPixmap(map);
    label->setAlignment(Qt::AlignCenter);
    
    layout->addWidget(label);
    group->setLayout(layout);
}
