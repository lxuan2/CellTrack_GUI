#ifndef VIDEO_GROUPBOX_HPP
#define VIDEO_GROUPBOX_HPP

#include <QTime>
#include <string>
#include <QLabel>
#include <QStyle>
#include <QLayout>
#include <QSlider>
#include <QFileInfo>
#include <QGroupBox>
#include <QToolButton>
#include <QPushButton>
#include <QMediaPlayer>

#include "log_view.hpp"
#include "video_view.hpp"
#include "file_finder.hpp"
#include "run_groupbox.hpp"

class VideoGroupBox: public QGroupBox {
    Q_OBJECT
public:
    
    // Default constructor
    VideoGroupBox(VideoView *out = nullptr, RunGroupBox *run = nullptr, LogView *l = nullptr);
    
    // Destructor
    ~VideoGroupBox();
    
    // Absolute path for current file in file finder
    QString finderFilePath();
    
signals:
    
    void adaptToView();
    
    void updateSrc(QString fp);
    
public slots:

    // Set result video Name and load
    void setResultPath(QString fn);
    
    // Play clicked
    void playClicked();
    
    // Start or stop the player
    bool play(bool ans);
    
private slots:
    
    // Set playback postion
    void setPosition(qint64 progress);
    
    // Set video duration
    void setDuration(qint64 duration);
    
    // Load Original Video to player
    void loadOriginal();
    
    // Load Result Video to player
    void loadResult();
    
    // Playback postion changed by slider
    void positionChanged();
    
    // Volume changed by slider
    void volumeChanged(int volume);
    
    // Media player state changed
    void stateChanged(QMediaPlayer::State state);
    
private:
    
    // Video player
    QMediaPlayer *player;
    
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
    LogView *log;
    
    // Max duration
    qint64 duration;
    
    // Duration label
    QLabel *durLabel;

    // Result video full name(path + name)
	QString resAbsPath;
    
    // video directory
	QString orgAbsPath;
    
    // Load file to the player
    bool loadFile(QString fileAbsPath);
    
    // Change Play button icon
    void changePlayButton(bool play);
    
    // Update duration info label
    void updateDurationInfo(qint64 currentInfo);
};

#endif
