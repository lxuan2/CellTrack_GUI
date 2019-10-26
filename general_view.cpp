#include "general_view.hpp"
GeneralView::GeneralView(QString app, UserData *data, LogView *log){
    
    // Widget initialize
    videoView = new VideoView();
    
    // Groupbox initialize
    runBox     = new RunGroupBox(app, data, log);
    videoBox   = new VideoGroupBox(videoView, runBox, log, app, data);
    controlBox = new ControlPannel(log);
    
    QObject::connect(runBox, &RunGroupBox::run, this, &GeneralView::runDetected);
    
    // Widget layout initialize
    auto layout = new QGridLayout();
    layout->addWidget(videoView, 0, 0);
    layout->addWidget(videoBox, 1, 0);
    layout->addWidget(controlBox, 0, 1);
    layout->addWidget(runBox, 1, 1);
    setLayout(layout);
}

void GeneralView::runDetected() {
    videoBox->play(false);
    emit run();
}

QString GeneralView::getVideoPath() {
    return videoBox->finderFilePath();
}

int GeneralView::getMaxSize() {
    return controlBox->maxSize();
}

int GeneralView::getMinSize() {
    return controlBox->minSize();
}

bool GeneralView::isAreaChecked() {
    return controlBox->isAreaChecked();
}

bool GeneralView::isEccentricityChecked() {
    return controlBox->isEccentricityChecked();
}

bool GeneralView::isOrientationChecked() {
    return controlBox->isOrientationChecked();
}

QString GeneralView::getAppPath() {
    return runBox->getAppPath();
}

void GeneralView::setResultVideo(QString path) {
    runBox->updateRes(path);
    videoBox->setResultPath(path);
}
