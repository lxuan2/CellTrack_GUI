#ifndef CONTENT_VIEW_HPP
#define CONTENT_VIEW_HPP

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
#include "display_widget.hpp"
#include "video_groupbox.hpp"
#include "control_panel_groupbox.hpp"

class ContentView: public QWidget{
    Q_OBJECT
public:
    
    // Default constructor
    ContentView(QWidget *parent = nullptr);
    
    // Set C# Application location
    void setExeLoc(QString exeLoc);
    
signals:
    
    void createView(int id);
    
private:
    
    // Video widget
    DisplayWidget *videoWidget;
    
    // Log widget
    LogWidget *log;

    // Group boxes
    VideoGroupBox *videoBox;
    ControPannelGroupBox *controlBox;
    
    // Computation Core
    Core *core;
};

#endif
