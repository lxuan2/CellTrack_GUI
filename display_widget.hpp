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
    
public slots:
    
    void play();
    
    void changeVolume(int volume);
    
    void changePosition(int position);
    
    void changeFile(QString file);
    
private:
    
    // Video player
    QMediaPlayer *player;
};

#endif
