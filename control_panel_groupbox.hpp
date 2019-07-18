#ifndef CONTROL_PANNEL_GROUPBOX_HPP
#define CONTROL_PANNEL_GROUPBOX_HPP

#include <QMediaPlayer>
#include <QGroupBox>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QLayout>
#include <QLabel>

#include "log_widget.hpp"

class ControPannelGroupBox: public QGroupBox
{
    Q_OBJECT
public:
    
    // Default constructor
    ControPannelGroupBox(LogWidget *l);
    
private:
    
    QSpinBox *maxCellSize;
    QSpinBox *minCellSize;
    QPushButton *analyzeButton;
    
    // Log recorder
    LogWidget *log;
};

#endif
