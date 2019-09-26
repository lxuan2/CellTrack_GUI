#ifndef general_view_hpp
#define general_view_hpp

#include "core.hpp"
#include "log_view.hpp"
#include "video_view.hpp"
#include "video_groupbox.hpp"
#include "control_panel_groupbox.hpp"

class GeneralView: public QWidget{
    Q_OBJECT
public:
    
    // Default constructor
    GeneralView(LogView *log);
    
    // Set C# Application location
    void setExeLoc(QString exeLoc);
    
private:
    
    // Video widget
    VideoView *videoView;

    // Group boxes
    VideoGroupBox *videoBox;
    ControlPannel *controlBox;
    RunGroupBox   *runBox;
    
    // Computation Core
    Core *core;
};

#endif
