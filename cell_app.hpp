#ifndef CELL_APP_HPP
#define CELL_APP_HPP

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

class CellApp: public QWidget{
    Q_OBJECT
public:
    
    // Default constructor
    CellApp(QWidget *parent = nullptr);
    
public slots:
    
    // Show CellApp as a window
    void showWindow(QString exeLoc);
    
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
