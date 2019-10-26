#include "intro_widget.hpp"
#include "process_view.hpp"
#include <QDebug>
IntroWidget::IntroWidget(QWidget *parent): QWidget(parent) {
    #ifndef __APPLE__
    setContentsMargins(9, 0, 15, 13);
    #endif
    // Title Label
    radar = new Radar();
    QLabel *title = new QLabel("Welcome to CellTrack_GUI app.");
    
    // Description Label
    title->setStyleSheet("font-weight: bold; font-size: 13pt");
    QLabel *version = new QLabel("Version 1.0.1");
    version->setStyleSheet("color: gray; font-size: 10pt");
    
    // Action Label
    QLabel *action = new QLabel("Choose the language that your analysis program uses:   ");
    action->setStyleSheet("font-size: 12pt");
    
    // Check Boxes
    matlab = new QCheckBox("matlab");
    python = new QCheckBox("python");
    QObject::connect(matlab, &QCheckBox::stateChanged, this, &IntroWidget::matlabClicked);
    QObject::connect(python, &QCheckBox::stateChanged, this, &IntroWidget::pythonClicked);
    
    QWidget *checkboxes = new QWidget();
    QHBoxLayout *l = new QHBoxLayout();
    l->addWidget(matlab);
    l->addWidget(python);
    checkboxes->setLayout(l);
    
    // Button
    OK = new QPushButton(" Start ");
    QObject::connect(OK, &QPushButton::clicked, this, &IntroWidget::closeWindow);
    OK->setDisabled(true);
    
    info = new QToolButton();
    info->setIcon(style()->standardIcon(QStyle::SP_FileDialogInfoView));
    info->setStyleSheet("border-radius: 13px");
    QObject::connect(info, &QPushButton::clicked, this, &IntroWidget::infoClicked);
    
    QGroupBox *group = new QGroupBox();
    QGridLayout *lay = new QGridLayout();
    lay->addWidget(title, 0, 0, Qt::AlignLeft);
    lay->addWidget(info, 0, 0, Qt::AlignRight);
    lay->addWidget(version, 1, 0, Qt::AlignLeft);
    lay->addWidget(action, 2, 0, Qt::AlignLeft);
    lay->addWidget(checkboxes, 3, 0);
    lay->addWidget(OK, 4, 0, Qt::AlignRight);
    group->setLayout(lay);
    
    // Widget layout initialize
    auto layout = new QGridLayout();
    layout->addWidget(radar, 0, 0, Qt::AlignCenter);
    layout->addWidget(group, 0, 1, Qt::AlignCenter);
    layout->setHorizontalSpacing(14);
    setLayout(layout);
    setFixedSize(sizeHint());
    radar->start();
}

void IntroWidget::closeWindow() {
    if (matlab->isChecked())
        createView(1);
    else if (python->isChecked())
        createView(2);
    else
        return;
    radar->stop();
    close();
}

void IntroWidget::matlabClicked() {
    if (matlab->isChecked()) {
        OK->setDisabled(false);
        python->setCheckState(Qt::Unchecked);
        return;
    }
    if (!python->isChecked()) {
        OK->setDisabled(true);
    }
}

void IntroWidget::pythonClicked() {
    if (python->isChecked()) {
        OK->setDisabled(false);
        matlab->setCheckState(Qt::Unchecked);
        return;
    }
    if (!matlab->isChecked()) {
        OK->setDisabled(true);
    }
}

void IntroWidget::infoClicked() {
    HelperWidget dialog("intro");
    dialog.exec();
}
