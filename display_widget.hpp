#ifndef DISPLAY_WIDGET_HPP
#define DISPLAY_WIDGET_HPP

#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFileInfo>
#include <QMouseEvent>

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
    
    void changeFile(QString file);
    
    void seek(int seconds);
    
    void durationChanged(qint64 duration);
    
    void positionChanged(qint64 progress);
    
    void stateChanged(QMediaPlayer::State state);

signals:
    
    void changePlayButton(bool play);
    
    void changeDuration(qint64 duration);
    
    void changePosition(qint64 progress);
    
private:
    
    // Video player
    QMediaPlayer *player;
    
    // Log recorder
    LogWidget *log;
    
    void mousePressEvent(QMouseEvent *event);
};

#endif
