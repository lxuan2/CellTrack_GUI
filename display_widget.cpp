#include "display_widget.hpp"


DisplayWidget::DisplayWidget(LogWidget *l): QVideoWidget(){
    log = l;
    player = new QMediaPlayer();
    player->setVolume(50);
    player->setVideoOutput(this);
	setMinimumSize(450, 350);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    
    connect(player, &QMediaPlayer::durationChanged, this, &DisplayWidget::durationChanged);
    connect(player, &QMediaPlayer::positionChanged, this, &DisplayWidget::positionChanged);
    connect(player, &QMediaPlayer::stateChanged, this, &DisplayWidget::stateChanged);
}

DisplayWidget::~DisplayWidget() {
    player->~QMediaPlayer();
}

void DisplayWidget::play() {
    QMediaPlayer::State state = player->state();
    QMediaPlayer::MediaStatus mediaState = player->mediaStatus();

    // Playing state
    if (state == QMediaPlayer::PlayingState) {
        log->write("- Stop -");
        player->pause();
        emit changePlayButton(false);
    }
    // Not playing state
    else {
        if (mediaState == QMediaPlayer::NoMedia){
            log->write("Error: No video play.");
            return;
        }
        else if (mediaState == QMediaPlayer::UnknownMediaStatus || mediaState == QMediaPlayer::InvalidMedia){
            log->write("Error: Media State wrong. Please reload target video.");
            return;
        }
        log->write("- Start -");
        player->play();
        adjustSize();
        emit changePlayButton(true);
    }
}

void DisplayWidget::changeVolume(int volume) {
    player->setVolume(volume);
}

void DisplayWidget::changeFile(QString file) {
    QFileInfo check_file(file);
    if (check_file.exists() && check_file.isFile()) {
        log->write(QString::fromStdString("- New Video Loaded: ") + file);
		std::string x = file.toStdString();
        player->setMedia(QUrl::fromLocalFile(QString::fromStdString(x)));
        return;
    }
    log->write("Error: No file or invalid file to be loaded.");
    
}

void DisplayWidget::durationChanged(qint64 duration) {
    emit changeDuration(duration);
}

void DisplayWidget::positionChanged(qint64 progress) {
    emit changePosition(progress);
}

void DisplayWidget::seek(int seconds) {
    player->setPosition(seconds * 1000);
    if (player->state() != QMediaPlayer::PlayingState)
        play();
}

void DisplayWidget::stateChanged(QMediaPlayer::State state) {
    if(player->state() == QMediaPlayer::StoppedState){
        log->write("- Stop -");
        emit changePlayButton(false);
    }
}

void DisplayWidget::mousePressEvent(QMouseEvent *event) {
    play();
    QWidget::mousePressEvent(event);
}
