#include "matlab_Widget.hpp"

MatlabWidget::MatlabWidget(QWidget *parent, QString appDirPath): QWidget(parent) {
    
    // Log initialize
    log = new LogWidget(appDirPath);
    
    // Widget initialize
    videoWidget = new VideoView(log);
    
    // Groupbox initialize
    videoBox = new VideoGroupBox(log);
    controlBox = new ControlPannel(log);
    
    // Compuation Core initialize
    core = new Core(videoBox, controlBox, log);
    
    QObject::connect(controlBox, &ControlPannel::compute, core, &Core::compute);
	QObject::connect(core, &Core::loadResualt, videoBox, &VideoGroupBox::setResualtName);
    QObject::connect(videoBox, &VideoGroupBox::play, videoWidget, &VideoView::play);
    QObject::connect(videoBox, &VideoGroupBox::changeVolume, videoWidget, &VideoView::changeVolume);
    QObject::connect(videoBox, &VideoGroupBox::seek, videoWidget, &VideoView::seek);
    QObject::connect(videoBox, &VideoGroupBox::changeFile, videoWidget, &VideoView::changeFile);
    QObject::connect(videoWidget, &VideoView::changePlayButton, videoBox, &VideoGroupBox::changePlayButton);
    QObject::connect(videoWidget, &VideoView::changeDuration, videoBox, &VideoGroupBox::changeDuration);
    QObject::connect(videoWidget, &VideoView::changePosition, videoBox, &VideoGroupBox::changePosition);
    
    // Widget layout initialize
    auto layout = new QGridLayout();
    layout->addWidget(videoWidget, 0, 0);
    layout->addWidget(videoBox, 1, 0);
    layout->addWidget(controlBox, 0, 1, 2, 1);
    setLayout(layout);
    setWindowTitle("CellTrack_GUI");
    resize(800, 600);
}

void MatlabWidget::setExeLoc(QString exeLoc) {
	core->setExe(exeLoc);
}
