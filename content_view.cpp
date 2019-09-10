#include "content_view.hpp"

ContentView::ContentView(QWidget *parent, QString appDirPath): QWidget(parent) {
    
    // Log initialize
    log = new LogWidget(appDirPath);
    
    // Widget initialize
    videoWidget = new DisplayWidget(log);
    
    // Groupbox initialize
    videoBox = new VideoGroupBox(log);
    controlBox = new ControPannelGroupBox(log);
    
    // Compuation Core initialize
    core = new Core(videoBox, controlBox, log);
    
    QObject::connect(controlBox, &ControPannelGroupBox::compute, core, &Core::compute);
	QObject::connect(core, &Core::loadResualt, videoBox, &VideoGroupBox::setResualtName);
    QObject::connect(videoBox, &VideoGroupBox::play, videoWidget, &DisplayWidget::play);
    QObject::connect(videoBox, &VideoGroupBox::changeVolume, videoWidget, &DisplayWidget::changeVolume);
    QObject::connect(videoBox, &VideoGroupBox::seek, videoWidget, &DisplayWidget::seek);
    QObject::connect(videoBox, &VideoGroupBox::changeFile, videoWidget, &DisplayWidget::changeFile);
    QObject::connect(videoWidget, &DisplayWidget::changePlayButton, videoBox, &VideoGroupBox::changePlayButton);
    QObject::connect(videoWidget, &DisplayWidget::changeDuration, videoBox, &VideoGroupBox::changeDuration);
    QObject::connect(videoWidget, &DisplayWidget::changePosition, videoBox, &VideoGroupBox::changePosition);
    
    // Widget layout initialize
    auto layout = new QGridLayout();
    layout->addWidget(videoWidget, 0, 0);
    layout->addWidget(videoBox, 1, 0);
    layout->addWidget(controlBox, 0, 1, 2, 1);
    setLayout(layout);
}

void ContentView::setExeLoc(QString exeLoc) {
	core->setExe(exeLoc);
}
