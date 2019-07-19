#include "video_groupbox.hpp"

VideoGroupBox::VideoGroupBox(LogWidget *l) {
    log = l;
    setTitle("Video");
    loadOrgButton = new QPushButton("Load Original");
    QObject::connect(loadOrgButton, &QPushButton::clicked, this, &VideoGroupBox::loadOriginal);
    
    loadResButton = new QPushButton("Load Result");
    QObject::connect(loadOrgButton, &QPushButton::clicked, this, &VideoGroupBox::loadResult);
    
    playButton = new QToolButton();
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    QObject::connect(playButton, &QToolButton::clicked, this, &VideoGroupBox::playClicked);
    
    browseButton = new QPushButton("Browse");
    QObject::connect(browseButton, &QPushButton::clicked, this, &VideoGroupBox::browse);
    
    volumeSlider = new QSlider(Qt::Horizontal);
    volumeSlider->setRange(0, 100);
    QObject::connect(volumeSlider, &QSlider::valueChanged, this, &VideoGroupBox::setVolume);
    
    trackSlider = new QSlider(Qt::Horizontal);
    //trackSlider->setRange(0, player->duration() / 1000);
    //trackSlider->setEnabled(false);
    QObject::connect(trackSlider, &QSlider::valueChanged, this, &VideoGroupBox::setPosition);
    
    fileBox = new FileCombobox();
    fileBox->setEditable(true);
    fileBox->setFrame(true);
    QObject::connect(fileBox, &FileCombobox::enterPressed, this, &VideoGroupBox::loadOriginal);
    
    auto *layout = new QGridLayout();
    layout->addWidget(trackSlider, 0, 0, 1, 16);
    
    layout->addWidget(new QLabel("Start/Stop:"), 1, 0);
    layout->addWidget(playButton, 1, 1);
    layout->addWidget(loadOrgButton, 1, 14, 1, 2);
    
    layout->addWidget(new QLabel("Volume:"), 2, 0);
    layout->addWidget(volumeSlider, 2, 1);
    layout->addWidget(loadResButton, 2, 14, 1, 2);
    
    layout->addWidget(new QLabel("File Location:"), 3, 0);
    layout->addWidget(fileBox, 3, 1, 1, 14);
    layout->addWidget(browseButton, 3, 15);
    setLayout(layout);
}

void VideoGroupBox::setVolume(int volume) {
    emit changeVolume(volume);
}

void VideoGroupBox::setPosition(int position){
    emit changePosition(position);
}

void VideoGroupBox::playClicked() {
    emit play();
}

void VideoGroupBox::browse() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open Video File", QDir::homePath());
    if (!fileName.isEmpty()) {
        if (fileBox->findText(fileName) == -1)
            fileBox->addItem(fileName);
        fileBox->setCurrentIndex(fileBox->findText(fileName));
        loadOriginal();
    }
}

void VideoGroupBox::loadOriginal() {
    changePlayButton(false);
    QString file = fileBox->currentText();
    emit changeFile(file);
}

void VideoGroupBox::loadResult() {
    changePlayButton(false);
    QString file = fileBox->currentText();
    emit changeFile(file);
}

void VideoGroupBox::changePlayButton(bool play) {
    if (play)
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    else
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
}

/*void VideoGroupBox::durationChanged(qint64 dur)
{
    duration = dur / 1000;
    trackSlider->setMaximum(duration);
}*/
