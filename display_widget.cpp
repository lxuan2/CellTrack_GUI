#include "display_widget.hpp"

DisplayWidget::DisplayWidget() {
    player = new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile("/Users/xuanli/Downloads/cyto_data1.mp4"));
    player->setVideoOutput(this);
    setMinimumSize(400, 250);
    player->play();
}
