#ifndef DISPLAY_WIDGET_HPP
#define DISPLAY_WIDGET_HPP

#include <string>
#include <QFileInfo>
#include <QSizePolicy>
#include <QMouseEvent>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QResizeEvent>
#include <QMediaPlaylist>

#include "log_widget.hpp"

class DisplayWidget: public QVideoWidget{
    Q_OBJECT
public:
    
    // Default constructor
    DisplayWidget(LogWidget *l);
    
    // Destructor
    ~DisplayWidget();
    
public slots:
    
    // Click play media button
    void play();
    
    // Change the player volume
    void changeVolume(int volume);
    
    // Change the video file
    void changeFile(QString file);
    
    // Seek the playback position
    void seek(int seconds);
    
    // Duration changed
    void durationChanged(qint64 duration);
    
    // Postion changed
    void positionChanged(qint64 progress);
    
    // Update GUI if the player stopped
    void stateChanged(QMediaPlayer::State state);

signals:
    
    // Change play button
    void changePlayButton(bool play);
    
    // Change video Duration
    void changeDuration(qint64 duration);
    
    // Change playback Postion
    void changePosition(qint64 progress);
    
private:
    
    // Video player
    QMediaPlayer *player;
    
    // Log recorder
    LogWidget *log;
    
    // Overloaded Mouse pressed Event
    void mousePressEvent(QMouseEvent *event);
};

#endif
