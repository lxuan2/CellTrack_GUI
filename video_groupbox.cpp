#include "video_groupbox.hpp"

VideoGroupBox::VideoGroupBox(VideoView *out, RunGroupBox *run, LogView *l) {
    log = l;
    setTitle("Video");
    QObject::connect(this, &VideoGroupBox::adaptToView, out, &::VideoView::adaptToView);
    QObject::connect(this, &VideoGroupBox::updateSrc, run, &RunGroupBox::updateSrc);
    QObject::connect(out, &VideoView::playButtonClicked, this, &::VideoGroupBox::playClicked);
    
    player = new QMediaPlayer();
    player->setVolume(50);
    player->setVideoOutput(out);
    connect(player, &QMediaPlayer::durationChanged, this, &VideoGroupBox::setDuration);
    connect(player, &QMediaPlayer::positionChanged, this, &VideoGroupBox::setPosition);
    connect(player, &QMediaPlayer::stateChanged, this, &VideoGroupBox::stateChanged);
    
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
    QObject::connect(volumeSlider, &QSlider::valueChanged, this, &VideoGroupBox::volumeChanged);
    
    trackSlider = new QSlider(Qt::Horizontal);
    trackSlider->setRange(0, 30);
    trackSlider->setEnabled(false);
    QObject::connect(trackSlider, &QSlider::sliderReleased, this, &VideoGroupBox::positionChanged);
    
    durLabel = new QLabel("--:-- / --:--");
    
    finder = new FileFinder("Source");
    QObject::connect(finder, &FileFinder::contentChanged, this, &VideoGroupBox::loadOriginal);
    
    QLabel *playLabel = new QLabel("Start/Stop:");
    QLabel *volumeLabel = new QLabel("Volume:");
    playLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    volumeLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    
    auto *layout = new QGridLayout();
    layout->addWidget(trackSlider, 0, 1, 1, 15);
    layout->addWidget(durLabel, 0, 16);
    
    layout->addWidget(playLabel, 1, 1);
    layout->addWidget(playButton, 1, 3);
    layout->addWidget(loadOrgButton, 1, 15, 1, 2);
    
    layout->addWidget(volumeLabel, 2, 1);
    layout->addWidget(volumeSlider, 2, 3, 1, 8);
    layout->addWidget(loadResButton, 2, 15, 1, 2);
    
    layout->addWidget(finder, 3, 0, 1, 18);
    setLayout(layout);
}

VideoGroupBox::~VideoGroupBox() {
    player->~QMediaPlayer();
}

QString VideoGroupBox::finderFilePath() {
    return finder->currentText();
}

void VideoGroupBox::setResultPath(QString fn) {
    resAbsPath = fn;
    loadResult();
}

void VideoGroupBox::playClicked() {
    QMediaPlayer::State state = player->state();
    if (state == QMediaPlayer::PlayingState){
        play(false);
        log->write("- Stop -");
    } else {
        if (play(true))
            log->write("- Start -");
    }
}

/*###########################################
 #           Private Functions              #
 ###########################################*/

void VideoGroupBox::setPosition(qint64 progress) {
    if (!trackSlider->isSliderDown())
        trackSlider->setValue(int(progress / 1000));
    
    updateDurationInfo(progress / 1000);
}

void VideoGroupBox::setDuration(qint64 duration) {
    this->duration = duration / 1000;
    trackSlider->setMaximum(int(this->duration));
    trackSlider->setEnabled(true);
}

void VideoGroupBox::loadOriginal() {
    QString fileAbsPath = finder->currentText();
    if(!loadFile(fileAbsPath)) {
        emit updateSrc("N/A");
        return log->write("Error: No file or invalid file loaded.");
    }
    emit updateSrc(fileAbsPath);
    log->write(QString::fromStdString("- New Video Loaded: ") + fileAbsPath);
    orgAbsPath = fileAbsPath;
}

void VideoGroupBox::loadResult() {
    if(!loadFile(resAbsPath)) {
        return log->write("Error: No analyed video or invalid analyed video loaded.");
    }
    log->write(QString::fromStdString("- Analyzed Video Loaded: ") + resAbsPath);
}

void VideoGroupBox::positionChanged(){
    play(false);
    int position = trackSlider->value();
    player->setPosition(position * 1000);
}

void VideoGroupBox::volumeChanged(int volume) {
    player->setVolume(volume);
}

void VideoGroupBox::stateChanged(QMediaPlayer::State state) {
    if(player->state() == QMediaPlayer::StoppedState){
        log->write("- Stop -");
        emit changePlayButton(false);
    }
}

void VideoGroupBox::changePlayButton(bool play) {
    if (play)
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    else
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
}

bool VideoGroupBox::play(bool ans) {
    if (!ans) {
        player->pause();
        changePlayButton(false);
        return true;
    }
    QMediaPlayer::MediaStatus mediaState = player->mediaStatus();
    if (mediaState == QMediaPlayer::NoMedia){
        log->write("Error: No video play.");
        return false;
    }
    else if (mediaState == QMediaPlayer::UnknownMediaStatus || mediaState == QMediaPlayer::InvalidMedia){
        log->write("Error: Media State wrong. Please reload target video.");
        return false;
    }
    player->play();
    changePlayButton(true);
    emit adaptToView();
    return true;
}

bool VideoGroupBox::loadFile(QString fileAbsPath) {
    play(false);
    QFileInfo info(fileAbsPath);
    if (info.exists() && info.isFile()) {
        player->setMedia(QUrl::fromLocalFile(fileAbsPath));
        // Re-check all media status and make sure media loaded.
        QMediaPlayer::MediaStatus mediaState = player->mediaStatus();
        if (mediaState == QMediaPlayer::NoMedia ||
            mediaState == QMediaPlayer::UnknownMediaStatus ||
            mediaState == QMediaPlayer::InvalidMedia) {
            return false;
        }
        return true;
    }
    return false;
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
