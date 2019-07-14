#ifndef CONTROL_PANNEL_GROUPBOX_HPP
#define CONTROL_PANNEL_GROUPBOX_HPP

#include <QMediaPlayer>
#include <QGroupBox>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QLayout>
#include <QLabel>

class QAbstractButton;
class QAbstractSlider;
class QComboBox;

class ControPannelGroupBox: public QGroupBox
{
    Q_OBJECT
public:
    
    // Default constructor
    ControPannelGroupBox();
    
private:
    
    QSpinBox *maxCellSize;
    QSpinBox *minCellSize;
    QPushButton *analyzeButton;
};

#endif
