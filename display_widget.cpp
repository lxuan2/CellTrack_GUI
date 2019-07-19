#include "display_widget.hpp"

DisplayWidget::DisplayWidget(LogWidget *l): QVideoWidget(){
    log = l;
    player = new QMediaPlayer();
    player->setVolume(50);
    player->setVideoOutput(this);
    setMinimumHeight(250);
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
        emit changedPlayButton(false);
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
        emit changedPlayButton(true);
    }
}

void DisplayWidget::changeVolume(int volume) {
    player->setVolume(volume);
}

void DisplayWidget::changePosition(int position) {
    player->setPosition(position);
}

void DisplayWidget::changeFile(QString file) {
    log->write("- New Video Loaded -");
    player->setMedia(QUrl::fromLocalFile(file));
}

QMediaPlayer* DisplayWidget::playerPtr() {
    return player;
}
