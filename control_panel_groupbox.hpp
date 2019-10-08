#ifndef CONTROL_PANNEL_HPP
#define CONTROL_PANNEL_HPP

#include <QLabel>
#include <QSlider>
#include <QLayout>
#include <QSpinBox>
#include <QCheckBox>
#include <QGroupBox>
#include <QPushButton>
#include <QMediaPlayer>

#include "log_view.hpp"
#include "run_groupbox.hpp"

class ControlPannel: public QGroupBox
{
    Q_OBJECT
public:
    
    // Default constructor
    ControlPannel(LogView *l);
    
    // Max cell size in the spinbox
    int maxSize();
    
    // Min cell size in the spinbox
    int minSize();
    
    // Aera seleted or unselected
    bool isAreaChecked();
    
    // Eccentricity seleted or unselected
    bool isEccentricityChecked();
    
    // Orientation seleted or unselected
    bool isOrientationChecked();
    
private:
    
    // SpinBox
    QSpinBox *maxCellSize;
    QSpinBox *minCellSize;
    
    // CheckBox
    QCheckBox *areaCheckbox;
    QCheckBox *eccentricityChecbox;
    QCheckBox *orientationCheckbox;
    
    // Log widget
    LogView *log;
};

#endif
