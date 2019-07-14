#include "cell_app.hpp"

CellApp::CellApp(QWidget *parent): QWidget(parent) {
    
    // Widget initialize
    videoWidget = new DisplayWidget();
    
    // Groupbox initialize
    videoBox = new VideoGroupBox();
    controlBox = new ControPannelGroupBox();
    
    QObject::connect(videoBox, &VideoGroupBox::play, videoWidget, &DisplayWidget::play);
    QObject::connect(videoBox, &VideoGroupBox::changeVolume, videoWidget, &DisplayWidget::changeVolume);
    QObject::connect(videoBox, &VideoGroupBox::changePosition, videoWidget, &DisplayWidget::changePosition);
    QObject::connect(videoBox, &VideoGroupBox::changeFile, videoWidget, &DisplayWidget::changeFile);
    
    // Widget layout initialize
    auto layout = new QGridLayout();
    layout->addWidget(videoWidget, 1, 0, 9, 16);
    layout->addWidget(videoBox, 10, 0, 1, 16);
    layout->addWidget(controlBox, 16, 0, 1, 16);
    setLayout(layout);
}
