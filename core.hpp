#ifndef CORE_HPP
#define CORE_HPP

#if defined(_WIN32) || defined(_WIN64)

#define OS_Windows 1
#include <Windows.h>

#endif

#include <QFileInfo>
#include <string>
#include <fstream>
#include <QString>
#include <stdio.h>

#include "log_view.hpp"
#include "video_groupbox.hpp"
#include "control_panel_groupbox.hpp"


class Core: public QObject {
    Q_OBJECT
public:
    
    // Parameterized Constructor
    Core(VideoGroupBox *v, ControlPannel *c, LogView *l);
    
    // Set C# App .exe name and path
    void setExe(QString exeLoc);

signals:

    // Load Result video signal
	void loadResualt(QString fn);

public slots:
    
    // Computation function that runs C# App and generate the video
    void compute(bool ans);
    
private:
    
    // Video Box Pointer
    VideoGroupBox *videoBox;
    
    // Control pannel Pointer
    ControlPannel *controlBox;
    
    // C# App .exe Full path (include path and file name)
    std::string exeLoc;
	
    // C# App .exe dirctory
	std::string path;
    
    // Log recorder
    LogView *log;
    
    // compute() helper function
    bool matlabCode();
};

#endif
