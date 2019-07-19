#ifndef VIDEO_GROUPBOX_HPP
#define VIDEO_GROUPBOX_HPP

#include <QWidget>
#include <QGroupBox>
#include <QSlider>
#include <QPushButton>
#include <QMediaPlayer>
#include <QToolButton>
#include <QStyle>
#include <QLayout>
#include <QLabel>
#include <QFileDialog>
#include <iostream>

#include "file_combobox.hpp"
#include "log_widget.hpp"

class VideoGroupBox: public QGroupBox {
    Q_OBJECT
public:
    
    // Default constructor
    VideoGroupBox(LogWidget *l);

public slots:
    
    void setVolume(int volume);
    
    void setPosition(int position);
    
    void playClicked();
    
    void browse();
    
    void loadOriginal();
    
    void loadResult();
    
    void changePlayButton(bool play);
    
signals:
    
    void play();
    
    void changeVolume(int volume);
    
    void changePosition(int position);
    
    void changeFile(QString file);
    
    //void durationChanged(qint64 dur);
    
    //void positionChanged(qint64 progress);
    
private:
    
    // Buttons
    QPushButton *loadOrgButton;
    QPushButton *loadResButton;
    QToolButton *playButton;
    QPushButton *browseButton;
    
    // Sliders
    QSlider *volumeSlider;
    QSlider *trackSlider;
    
    // Combobox
    FileCombobox *fileBox;
    
    // Log recorder
    LogWidget *log;
    
    // Max duration
    qint64 duration;
    

};

#endif
