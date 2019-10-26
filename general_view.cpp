#include "general_view.hpp"
GeneralViewMA::GeneralViewMA(LogView *log){
    
    // Widget initialize
    videoView = new VideoView();
    
    // Groupbox initialize
    runBox     = new RunGroupBox("matlab", nullptr, log);
    videoBox   = new VideoGroupBox(videoView, runBox, log, "matlab", nullptr);
    controlBox = new ParameterMABox(log);
    
    QObject::connect(runBox, &RunGroupBox::run, this, &GeneralViewMA::runDetected);
    
    // Widget layout initialize
    auto layout = new QGridLayout();
    layout->addWidget(videoView, 0, 0);
    layout->addWidget(videoBox, 1, 0);
    layout->addWidget(controlBox, 0, 1);
    layout->addWidget(runBox, 1, 1);
    setLayout(layout);
}

void GeneralViewMA::runDetected() {
    videoBox->play(false);
    emit run();
}

QString GeneralViewMA::getVideoPath() {
    return videoBox->finderFilePath();
}

int GeneralViewMA::getMaxSize() {
    return controlBox->maxSize();
}

int GeneralViewMA::getMinSize() {
    return controlBox->minSize();
}

bool GeneralViewMA::isAreaChecked() {
    return controlBox->isAreaChecked();
}

bool GeneralViewMA::isEccentricityChecked() {
    return controlBox->isEccentricityChecked();
}

bool GeneralViewMA::isOrientationChecked() {
    return controlBox->isOrientationChecked();
}

QString GeneralViewMA::getAppPath() {
    return runBox->getAppPath();
}

void GeneralViewMA::setResultVideo(QString path) {
    runBox->updateRes(path);
    videoBox->setResultPath(path);
}

GeneralViewPy::GeneralViewPy(QString app, UserData *data, LogView *log){
    
    // Widget initialize
    videoView = new VideoView();
    
    // Groupbox initialize
    runBox     = new RunGroupBox("python", data, log);
    videoBox   = new VideoGroupBox(videoView, runBox, log, "python", data);
    controlBox = new ParameterPyBox(data, log);
    
    QObject::connect(runBox, &RunGroupBox::run, this, &GeneralViewPy::runDetected);
    
    // Widget layout initialize
    auto layout = new QGridLayout();
    layout->addWidget(videoView, 0, 0);
    layout->addWidget(videoBox, 1, 0);
    layout->addWidget(controlBox, 0, 1);
    layout->addWidget(runBox, 1, 1);
    setLayout(layout);
}

void GeneralViewPy::runDetected() {
    videoBox->play(false);
    emit run();
}

QString GeneralViewPy::getVideoPath() {
    return videoBox->finderFilePath();
}

QString GeneralViewPy::getAppPath() {
    return runBox->getAppPath();
}

void GeneralViewPy::setResultVideo(QString path) {
    runBox->updateRes(path);
    videoBox->setResultPath(path);
}
