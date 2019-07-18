#include "display_widget.hpp"

DisplayWidget::DisplayWidget(LogWidget *l) {
    log = l;
    player = new QMediaPlayer();
    player->setVolume(50);
    player->setVideoOutput(this);
    setMinimumSize(200, 250);
}

DisplayWidget::~DisplayWidget() {
    player->~QMediaPlayer();
}

void DisplayWidget::play() {
    QMediaPlayer::State state = player->state();
    QMediaPlayer::MediaStatus mediaState = player->mediaStatus();

    // Playing state
    if (state == QMediaPlayer::PlayingState) {
        player->pause();
        emit changedPlayButton(false);
    }
    // Not playing state
    else {
        if (mediaState == QMediaPlayer::NoMedia){
            // no media
            return;
        }
        else if (mediaState == QMediaPlayer::UnknownMediaStatus || mediaState == QMediaPlayer::InvalidMedia){
            // error
            return;
        }
        player->play();
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
    player->setMedia(QUrl::fromLocalFile(file));
}
