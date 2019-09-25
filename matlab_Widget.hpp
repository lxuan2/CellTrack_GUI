#ifndef MATLAB_WIDGET_HPP
#define MATLAB_WIDGET_HPP

#include <QLabel>
#include <QString>
#include <QWidget>
#include <QLayout>
#include <QSpinBox>
#include <QGroupBox>
#include <QComboBox>
#include <QPushButton>
#include <QFileDialog>
#include <QResizeEvent>

#include "core.hpp"
#include "log_widget.hpp"
#include "video_view.hpp"
#include "video_groupbox.hpp"
#include "control_panel.hpp"

class MatlabWidget: public QWidget{
    Q_OBJECT
public:
    
    // Default constructor
    MatlabWidget(QWidget *parent = nullptr, QString appDirPath = "");
    
    // Set C# Application location
    void setExeLoc(QString exeLoc);
    
signals:
    
    void createView(int id);
    
private:
    
    // Video widget
    VideoView *videoWidget;
    
    // Log widget
    LogWidget *log;

    // Group boxes
    VideoGroupBox *videoBox;
    ControlPannel *controlBox;
    
    // Computation Core
    Core *core;
};

#endif
