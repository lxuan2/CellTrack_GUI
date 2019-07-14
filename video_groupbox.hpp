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
#include <QComboBox>
#include <QFileDialog>

class VideoGroupBox: public QGroupBox{
    Q_OBJECT
public:
    
    // Default constructor
    VideoGroupBox();

public slots:
    
    void setVolume(int volume);
    
    void setPosition(int position);
    
    void playClicked();
    
    void browse();
    
    void loadOriginal();
    
    void loadResult();
    
signals:
    
    void play();
    
    void changeVolume(int volume);
    
    void changePosition(int position);
    
    void changeFile(QString file);
    
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
    QComboBox *fileCombobox;
};

#endif
