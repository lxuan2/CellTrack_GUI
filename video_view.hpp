#ifndef VIDEO_VIEW_HPP
#define VIDEO_VIEW_HPP

#include <QVideoWidget>
#include <QSizePolicy>
#include <QResizeEvent>
#include <QMouseEvent>

class VideoView: public QVideoWidget{
    Q_OBJECT
public:
    
    // Default constructor
    VideoView();

signals:
    
    void playButtonClicked();
    
public slots:
    
    void adaptToView();
    
private:
    
    // Overloaded Mouse pressed Event
    void mousePressEvent(QMouseEvent *event);
};

#endif
