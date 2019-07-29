#ifndef CORE_HPP
#define CORE_HPP

#include <QFileInfo>
#include <string>

#include "video_groupbox.hpp"
#include "control_panel_groupbox.hpp"
#include "log_widget.hpp"

class Core: public QObject {
    Q_OBJECT
public:
    
    // Default Constructor
    Core(VideoGroupBox *v, ControPannelGroupBox *c, LogWidget *l);
    
public slots:
    
    void compute();
    
private:
    
    VideoGroupBox *videoBox;
    
    ControPannelGroupBox *controlBox;
    
    // Log recorder
    LogWidget *log;
};

#endif
