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

#include "video_groupbox.hpp"
#include "control_panel_groupbox.hpp"
#include "log_widget.hpp"

class Core: public QObject {
    Q_OBJECT
public:
    
    // Default Constructor
    Core(VideoGroupBox *v, ControPannelGroupBox *c, LogWidget *l);
    
    void setExe(QString exeLoc);

public slots:
    
    void compute();
    
private:

	void matlabCode();
    
    VideoGroupBox *videoBox;
    
    ControPannelGroupBox *controlBox;
    
    std::string exeLoc;
    
    // Log recorder
    LogWidget *log;
};

#endif
