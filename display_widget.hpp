#ifndef DISPLAY_WIDGET_HPP
#define DISPLAY_WIDGET_HPP

#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include "log_widget.hpp"

class DisplayWidget: public QVideoWidget{
    Q_OBJECT
public:
    
    // Default constructor
    DisplayWidget(LogWidget *l);
    
    // Destructor
    ~DisplayWidget();
    
    // Player pointer
    QMediaPlayer* playerPtr();
    
public slots:
    
    void play();
    
    void changeVolume(int volume);
    
    void changePosition(int position);
    
    void changeFile(QString file);

signals:
    
    void changedPlayButton(bool play);
    
private:
    
    // Video player
    QMediaPlayer *player;
    
    // Log recorder
    LogWidget *log;
};

#endif
