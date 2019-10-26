#ifndef general_view_hpp
#define general_view_hpp

#include "log_view.hpp"
#include "video_view.hpp"
#include "video_groupbox.hpp"
#include "user_data.hpp"
#include "control_panel_groupbox.hpp"

class GeneralView: public QWidget{
    Q_OBJECT
public:
    
    // Default constructor
    GeneralView(QString app, UserData *data, LogView *log);
    
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
    ControlPannel *controlBox;
    RunGroupBox   *runBox;
};

#endif
