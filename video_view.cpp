#include "video_view.hpp"


VideoView::VideoView(LogWidget *l): QVideoWidget(){
    log = l;
    player = new QMediaPlayer();
    player->setVolume(50);
    player->setVideoOutput(this);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    
    connect(player, &QMediaPlayer::durationChanged, this, &VideoView::durationChanged);
    connect(player, &QMediaPlayer::positionChanged, this, &VideoView::positionChanged);
    connect(player, &QMediaPlayer::stateChanged, this, &VideoView::stateChanged);
}

VideoView::~VideoView() {
    player->~QMediaPlayer();
}

void VideoView::play() {
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

void VideoView::changeVolume(int volume) {
    player->setVolume(volume);
}

void VideoView::changeFile(QString file) {
    QFileInfo check_file(file);
    if (check_file.exists() && check_file.isFile()) {
        log->write(QString::fromStdString("- New Video Loaded: ") + file);
		std::string x = file.toStdString();
        player->setMedia(QUrl::fromLocalFile(QString::fromStdString(x)));
        return;
    }
    log->write("Error: No file or invalid file to be loaded.");
    
}

void VideoView::durationChanged(qint64 duration) {
    emit changeDuration(duration);
}

void VideoView::positionChanged(qint64 progress) {
    emit changePosition(progress);
}

void VideoView::seek(int seconds) {
    player->setPosition(seconds * 1000);
    if (player->state() != QMediaPlayer::PlayingState)
        play();
}

void VideoView::stateChanged(QMediaPlayer::State state) {
    if(player->state() == QMediaPlayer::StoppedState){
        log->write("- Stop -");
        emit changePlayButton(false);
    }
}

void VideoView::mousePressEvent(QMouseEvent *event) {
    play();
    QWidget::mousePressEvent(event);
}
