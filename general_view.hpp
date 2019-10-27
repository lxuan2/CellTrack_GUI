#ifndef general_view_hpp
#define general_view_hpp

#include "log_view.hpp"
#include "video_view.hpp"
#include "video_groupbox.hpp"
#include "user_data.hpp"
#include "parameter_groupbox.hpp"

class GeneralViewMA: public QWidget{
    Q_OBJECT
public:
    
    // Default constructor
    GeneralViewMA(LogView *log);
    
    QString getVideoPath();
    
    int getMaxSize();
    
    int getMinSize();
    
    bool isAreaChecked();
    
    bool isEccentricityChecked();
    
    bool isOrientationChecked();
    
    QString getAppPath();
    
    void setResultVideo(QString path);
    
signals:
    
    void run();
    
private slots:
    
    void runDetected();
    
private:
    
    // Video widget
    VideoView *videoView;

    // Group boxes
    VideoGroupBox *videoBox;
    ParameterMABox *controlBox;
    RunGroupBox   *runBox;
};

class GeneralViewPy: public QWidget{
    Q_OBJECT
public:
    
    // Default constructor
    GeneralViewPy(QString app, UserData *data, LogView *log, HiddenVarView *hidden);
    
    QString getVideoPath();
    
    QString getAppPath();
    
    void setResultVideo(QString path);
    
signals:
    
    void run();
    
private slots:
    
    void runDetected();
    
private:
    
    // Video widget
    VideoView *videoView;

    // Group boxes
    VideoGroupBox *videoBox;
    ParameterPyBox *controlBox;
    RunGroupBox   *runBox;
};

#endif
