#include "setting_app.hpp"

SettingApp::SettingApp(QWidget *parent): QWidget(parent) {
    finder = new FileFinder("Open File");
    QObject::connect(finder, &FileFinder::contentChanged, this, &SettingApp::closeWindow);
    
    // Widget layout initialize
    auto layout = new QGridLayout();
    layout->addWidget(new QLabel("The generated C# application location is needed"), 0, 8);
    layout->addWidget(finder, 1, 0, 1, 20);
    setLayout(layout);
}

void SettingApp::closeWindow() {
    emit toMain(finder->currentText());
    close();
}


