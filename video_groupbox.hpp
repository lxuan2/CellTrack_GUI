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
#include <QTime>

#include "file_combobox.hpp"
#include "log_widget.hpp"

class VideoGroupBox: public QGroupBox {
    Q_OBJECT
public:
    
    // Default constructor
    VideoGroupBox(LogWidget *l);
    
    QString currentFile();

public slots:
    
    void setVolume(int volume);
    
    void setPosition();
    
    void playClicked();
    
    void browse();
    
    void loadOriginal();
    
    void loadResult();
    
    void changePlayButton(bool play);
    
    void changeDuration(qint64 duration);
    
    void changePosition(qint64 progress);
    
signals:
    
    void play();
    
    void changeVolume(int volume);
    
    void changeFile(QString file);
    
    void seek(int seconds);
    
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
    
    // Duration label
    QLabel *durLabel;
    
    void updateDurationInfo(qint64 currentInfo);
};

#endif
