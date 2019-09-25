#ifndef CONTROL_PANNEL_HPP
#define CONTROL_PANNEL_HPP

#include <QLabel>
#include <QDialog>
#include <QSlider>
#include <QLayout>
#include <QSpinBox>
#include <QCheckBox>
#include <QGroupBox>
#include <QPushButton>
#include <QMediaPlayer>

#include "log_widget.hpp"
#include "log_preview.hpp"

class ControlPannel: public QGroupBox
{
    Q_OBJECT
public:
    
    // Default constructor
    ControlPannel(LogWidget *l);
    
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
    
public slots:
    
    // Anaylze button clicked recieving block
    void anaButtonClicked();
    
    // View Log button clicked recieving block
    void logButtonClicked();
    
signals:
    
    // Call C# app and generate video
    void compute();
    
private:
    
    // SpinBox
    QSpinBox *maxCellSize;
    QSpinBox *minCellSize;
    
    // Button
    QPushButton *analyzeButton;
    QPushButton *logButton;
    
    // CheckBox
    QCheckBox *areaCheckbox;
    QCheckBox *eccentricityChecbox;
    QCheckBox *orientationCheckbox;
    
    // Log widget
    LogWidget *log;
};

#endif