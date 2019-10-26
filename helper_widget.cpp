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
    layout->addWidget(new QLabel("intro"));
    group->setLayout(layout);
}

void HelperWidget::createPyGeneral() {
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(new QLabel("general_py"));
    group->setLayout(layout);
}

void HelperWidget::createPyHidden() {
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(new QLabel("hidden_py"));
    group->setLayout(layout);
}

void HelperWidget::createMaGeneral() {
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(new QLabel("general_ma"));
    group->setLayout(layout);
}

void HelperWidget::createLog() {
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(new QLabel("log"));
    group->setLayout(layout);
}

void HelperWidget::createError() {
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(new QLabel("error"));
    group->setLayout(layout);
}
