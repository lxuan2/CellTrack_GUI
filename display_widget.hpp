#ifndef DISPLAY_WIDGET_HPP
#define DISPLAY_WIDGET_HPP

#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class DisplayWidget: public QVideoWidget{
    Q_OBJECT
public:
    
    // Default constructor
    DisplayWidget();
    
private:
    
    // Video player
    QMediaPlayer *player;
};

#endif
