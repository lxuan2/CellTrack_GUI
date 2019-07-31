#ifndef VIDEO_GROUPBOX_HPP
#define VIDEO_GROUPBOX_HPP

#include <QTime>
#include <string>
#include <QLabel>
#include <QStyle>
#include <QLayout>
#include <QSlider>
#include <QWidget>
#include <QFileInfo>
#include <QGroupBox>
#include <QToolButton>
#include <QPushButton>
#include <QMediaPlayer>


#include "log_widget.hpp"
#include "file_finder.hpp"
#include "file_combobox.hpp"

class VideoGroupBox: public QGroupBox {
    Q_OBJECT
public:
    
    // Default constructor
    VideoGroupBox(LogWidget *l);
    
    // Current file full path
    QString currentFile();

public slots:
    
    // Set result video Name
	void setResualtName(std::string fn);
    
    // Set Volume
    void setVolume(int volume);
    
    // Set playback postion
    void setPosition();
    
    // Play button clicked
    void playClicked();
    
    // Load Original Video to player
    void loadOriginal();
    
    // Load Result Video to player
    void loadResult();
    
    // Change Play button icon
    void changePlayButton(bool play);
    
    // Change video duration
    void changeDuration(qint64 duration);
    
    // Change playback postion
    void changePosition(qint64 progress);
    
signals:
    
    // Play button clicked
    void play();
    
    // Change volume
    void changeVolume(int volume);
    
    // Change video file
    void changeFile(QString file);
    
    // Seek playback postion
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

    // Result video full name(path + name)
	std::string resultFullName;
    
    // Result video directory
	std::string resultPath;
    
    // Update duration info label
    void updateDurationInfo(qint64 currentInfo);
};

#endif
