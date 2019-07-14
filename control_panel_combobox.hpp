#ifndef DISPLAY_CONTROLS_H
#define DISPLAY_CONTROLS_H

#include <QMediaPlayer>
#include <QWidget>
#include <QSlider>

class QAbstractButton;
class QAbstractSlider;
class QComboBox;

class DisplayControl: public QWidget
{
    Q_OBJECT
public:
    
    // Default constructor
    DisplayControl(QWidget *parent = 0);
    
    int volume() const;
    
public slots:
    
    void setState(QMediaPlayer::State state);
    
    void setVolume(int volume);
    
    void setMuted(bool muted);
    
    void setPlaybackRate(float rate);
    
signals:
    
    void play();
    
    void changeVolume(int volume);
    
private slots:
    
    void playClicked();
    
private:
    
    // Buttons
    QAbstractButton *playButton;
    QAbstractSlider *volumeSlider;
    QSlider *progressSlider;
};

#endif
