#include "cell_app.hpp"

CellApp::CellApp(QWidget *parent): QWidget(parent) {
    
    // Log initialize
    log = new LogWidget();
    
    // Widget initialize
    videoWidget = new DisplayWidget(log);
    log = new LogWidget();
    
    // Groupbox initialize
    videoBox = new VideoGroupBox(log);
    controlBox = new ControPannelGroupBox(log);
    
    QObject::connect(videoBox, &VideoGroupBox::play, videoWidget, &DisplayWidget::play);
    QObject::connect(videoBox, &VideoGroupBox::changeVolume, videoWidget, &DisplayWidget::changeVolume);
    QObject::connect(videoBox, &VideoGroupBox::changePosition, videoWidget, &DisplayWidget::changePosition);
    QObject::connect(videoBox, &VideoGroupBox::changeFile, videoWidget, &DisplayWidget::changeFile);
    QObject::connect(videoWidget, &DisplayWidget::changedPlayButton, videoBox, &VideoGroupBox::changePlayButton);
    
    // Widget layout initialize
    auto layout = new QGridLayout();
    layout->addWidget(videoWidget, 1, 0, 9, 16);
    layout->addWidget(videoBox, 10, 0, 1, 16);
    layout->addWidget(controlBox, 16, 0, 1, 16);
    layout->addWidget(log, 17, 0, 1, 16);
    setLayout(layout);
}
