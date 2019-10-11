#include "intro_widget.hpp"

IntroWidget::IntroWidget(QWidget *parent): QDialog(parent) {
    // Title Label
    QPixmap map("./Radar.png");
    map.setDevicePixelRatio(4);
    QLabel *icon = new QLabel();
    icon->setPixmap(map);
    QLabel *title = new QLabel("Welcome to CellTrack_GUI app.");
    
    // Description Label
    title->setStyleSheet("font-weight: bold; color: black; font-size: 13pt");
    QLabel *version = new QLabel(" Version 1.0");
    version->setStyleSheet("color: gray; font-size: 10pt");
    
    // Action Label
    QLabel *action = new QLabel("The generated C# application location is needed.    ");
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
    OK = new QPushButton("Start");
    QObject::connect(OK, &QPushButton::clicked, this, &IntroWidget::closeWindow);
    OK->setDisabled(true);
    
    // Widget layout initialize
    auto layout = new QGridLayout();
    layout->addItem(new QSpacerItem(10, 10), 0, 0);
    layout->addWidget(icon, 0, 1, 5, 3);
    layout->addItem(new QSpacerItem(15, 15), 0, 4);
    layout->addWidget(title, 0, 5, 1, 4, Qt::AlignBottom);
    layout->addWidget(version, 1, 5, 1, 4, Qt::AlignTop);
    layout->addWidget(action, 2, 5, 1, 4, Qt::AlignTop);
    layout->addWidget(checkboxes, 3, 5, 2, 4);
    layout->addWidget(OK, 5, 8);
    setLayout(layout);
    setFixedSize(sizeHint());
}

void IntroWidget::closeWindow() {
    if (matlab->isChecked())
        createView(1);
    else if (python->isChecked())
        createView(2);
    else
        return;
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
