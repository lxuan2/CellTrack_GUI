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
#include <QStackedWidget>

#include "log_view.hpp"
#include "run_groupbox.hpp"
#include "hidden_var_view.hpp"

class ParameterMABox: public QGroupBox
{
    Q_OBJECT
public:
    
    // Default constructor
    ParameterMABox(LogView *l);
    
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

class ParameterPyBox: public QGroupBox
{
    Q_OBJECT
public:
    
    // Default constructor
    ParameterPyBox(HiddenVarView *hidden, LogView *l);
    
public slots:
    
    void updateSrc(QString str);
    
private:
    
    QStackedWidget *widget;
    
    QList<QLabel*> *list;
    
    HiddenVarView *hidden;
    
    // Log widget
    LogView *log;
};

#endif
