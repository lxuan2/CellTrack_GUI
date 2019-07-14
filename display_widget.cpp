#include "display_widget.hpp"

DisplayWidget::DisplayWidget() {
    player = new QMediaPlayer();
    player->setVolume(50);
    player->setVideoOutput(this);
    setMinimumSize(400, 250);
}

void DisplayWidget::play() {
    QMediaPlayer::State state = player->state();
    if (state == QMediaPlayer::PlayingState)
        player->pause();
    else
        player->play();
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
