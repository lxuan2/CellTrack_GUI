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
#include <QTime>

#include "file_combobox.hpp"
#include "log_widget.hpp"
#include "file_finder.hpp"

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
    
    // Sliders
    QSlider *volumeSlider;
    QSlider *trackSlider;
    
    // File finder
    FileFinder *finder;
    
    // Log recorder
    LogWidget *log;
    
    // Max duration
    qint64 duration;
    
    // Duration label
    QLabel *durLabel;
    
    void updateDurationInfo(qint64 currentInfo);
};

#endif
