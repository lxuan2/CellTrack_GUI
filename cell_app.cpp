#include "cell_app.hpp"

CellApp::CellApp(QWidget *parent): QWidget(parent) {
    
    // Log initialize
    log = new LogWidget();
    
    // Widget initialize
    videoWidget = new DisplayWidget(log);
    
    // Groupbox initialize
    videoBox = new VideoGroupBox(log);
    controlBox = new ControPannelGroupBox(log);
    
    QObject::connect(videoBox, &VideoGroupBox::play, videoWidget, &DisplayWidget::play);
    QObject::connect(videoBox, &VideoGroupBox::changeVolume, videoWidget, &DisplayWidget::changeVolume);
    QObject::connect(videoBox, &VideoGroupBox::changePosition, videoWidget, &DisplayWidget::changePosition);
    QObject::connect(videoBox, &VideoGroupBox::changeFile, videoWidget, &DisplayWidget::changeFile);
    QObject::connect(videoWidget, &DisplayWidget::changedPlayButton, videoBox, &VideoGroupBox::changePlayButton);
    
    // Widget layout initialize
    auto layout = new QVBoxLayout();
    layout->addWidget(videoWidget, 0, 0);
    layout->addWidget(videoBox, 1, 0);
    layout->addWidget(controlBox, 2, 0);
    layout->addWidget(log, 4, 0);
    setLayout(layout);
}
