#include "intro_widget.hpp"

IntroWidget::IntroWidget(QWidget *parent): QWidget(parent) {
    finder = new FileFinder("Open File");
    QObject::connect(finder, &FileFinder::contentChanged, this, &IntroWidget::closeWindow);
    
    // Widget layout initialize
    auto layout = new QGridLayout();
    layout->addWidget(new QLabel("The generated C# application location is needed"), 0, 8);
    layout->addWidget(finder, 1, 0, 1, 20);
    setLayout(layout);
}

void IntroWidget::closeWindow() {
    createView(0);
    emit setExeLoc(finder->currentText());
    close();
}

