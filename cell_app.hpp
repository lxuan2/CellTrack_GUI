#ifndef CELL_APP_HPP
#define CELL_APP_HPP

#include <iostream>
#include <QDebug>
#include <QLabel>
#include <QWidget>
#include <QLayout>
#include <QSpinBox>
#include <QGroupBox>
#include <QComboBox>
#include <QPushButton>
#include <QFileDialog>

#include "display_widget.hpp"
#include "video_groupbox.hpp"
#include "control_panel_groupbox.hpp"


class CellApp: public QWidget{
    Q_OBJECT
public:
    
    // Default constructor
    CellApp(QWidget *parent = nullptr);
    
private:
    
    // Video widget
    DisplayWidget *videoWidget;

    // Group boxes
    VideoGroupBox *videoBox;
    ControPannelGroupBox *controlBox;
};

#endif
