#include "video_groupbox.hpp"

VideoGroupBox::VideoGroupBox(LogWidget *l) {
    log = l;
    setTitle("Video");
    loadOrgButton = new QPushButton("Load Original");
    QObject::connect(loadOrgButton, &QPushButton::clicked, this, &VideoGroupBox::loadOriginal);
    
    loadResButton = new QPushButton("Load Result");
    QObject::connect(loadResButton, &QPushButton::clicked, this, &VideoGroupBox::loadResult);
    
    playButton = new QToolButton();
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    QObject::connect(playButton, &QToolButton::clicked, this, &VideoGroupBox::playClicked);
    
    volumeSlider = new QSlider(Qt::Horizontal);
    volumeSlider->setRange(0, 100);
	volumeSlider->setValue(50);
    QObject::connect(volumeSlider, &QSlider::valueChanged, this, &VideoGroupBox::setVolume);
    
    trackSlider = new QSlider(Qt::Horizontal);
    trackSlider->setRange(0, 30);
    //trackSlider->setEnabled(false);
    QObject::connect(trackSlider, &QSlider::sliderReleased, this, &VideoGroupBox::setPosition);
    
    durLabel = new QLabel("--:-- / --:--");
    
    finder = new FileFinder("File location");
    QObject::connect(finder, &FileFinder::contentChanged, this, &VideoGroupBox::loadOriginal);
    
    auto *layout = new QGridLayout();
    layout->addWidget(trackSlider, 0, 1, 1, 15);
    layout->addWidget(durLabel, 0, 16);
    
    layout->addWidget(new QLabel("Start/Stop:"), 1, 1);
    layout->addWidget(playButton, 1, 2);
    layout->addWidget(loadOrgButton, 1, 15, 1, 2);
    
    layout->addWidget(new QLabel("Volume:"), 2, 1);
    layout->addWidget(volumeSlider, 2, 2, 1, 8);
    layout->addWidget(loadResButton, 2, 15, 1, 2);
    
    layout->addWidget(finder, 3, 0, 1, 18);
    setLayout(layout);
}

void VideoGroupBox::setVolume(int volume) {
    emit changeVolume(volume);
}

void VideoGroupBox::setPosition(){
    int position = trackSlider->value();
    emit seek(position);
}

void VideoGroupBox::playClicked() {
    emit play();
}

void VideoGroupBox::loadOriginal() {
    changePlayButton(false);
	QFileInfo info(finder->currentText());
	resultPath = info.path().toStdString();
    emit changeFile(finder->currentText());
}

void VideoGroupBox::loadResult() {
	changePlayButton(false);
    emit changeFile(QString::fromStdString(resultFullName));
}

void VideoGroupBox::changePlayButton(bool play) {
    if (play)
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    else
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
}

void VideoGroupBox::changeDuration(qint64 duration) {
    this->duration = duration / 1000;
    trackSlider->setMaximum(this->duration);
}

void VideoGroupBox::changePosition(qint64 progress) {
    if (!trackSlider->isSliderDown())
        trackSlider->setValue(progress / 1000);
    
    updateDurationInfo(progress / 1000);
}

void VideoGroupBox::updateDurationInfo(qint64 currentInfo) {
    QString tStr;
    if (currentInfo || duration) {
        QTime currentTime((currentInfo / 3600) % 60, (currentInfo / 60) % 60,
                          currentInfo % 60, (currentInfo * 1000) % 1000);
        QTime totalTime((duration / 3600) % 60, (duration / 60) % 60,
                        duration % 60, (duration * 1000) % 1000);
        QString format = "mm:ss";
        if (duration > 3600)
            format = "hh:mm:ss";
        tStr = currentTime.toString(format) + " / " + totalTime.toString(format);
    }
    else
        tStr = "--:-- / --:--";
    durLabel->setText(tStr);
}

QString VideoGroupBox::currentFile() {
    return finder->currentText();
}

void VideoGroupBox::setResualtName(std::string fn) {
	resultFullName = resultPath + "/" + fn;
	loadResult();
}
