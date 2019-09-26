#include "video_view.hpp"
VideoView::VideoView(): QVideoWidget(){
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void VideoView::adaptToView() {
    adjustSize();
}

void VideoView::mousePressEvent(QMouseEvent *event) {
    emit playButtonClicked();
    QWidget::mousePressEvent(event);
}
