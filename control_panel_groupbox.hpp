#ifndef CONTROL_PANNEL_GROUPBOX_HPP
#define CONTROL_PANNEL_GROUPBOX_HPP

#include <QMediaPlayer>
#include <QGroupBox>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QLayout>
#include <QLabel>
#include <QCheckBox>

#include "log_widget.hpp"

class ControPannelGroupBox: public QGroupBox
{
    Q_OBJECT
public:
    
    // Default constructor
    ControPannelGroupBox(LogWidget *l);
    
    int maxSize();
    
    int minSize();
    
    bool isAreaChecked();
    
    bool isEccentricityChecked();
    
    bool isOrientationChecked();
    
public slots:
    
    void anaButtonClicked();
    
signals:
    
    void compute();
    
private:
    
    QSpinBox *maxCellSize;
    QSpinBox *minCellSize;
    QPushButton *analyzeButton;
    QCheckBox *areaCheckbox;
    QCheckBox *eccentricityChecbox;
    QCheckBox *orientationCheckbox;
    
    
    
    // Log recorder
    LogWidget *log;
};

#endif
