#ifndef hidden_variable_hpp
#define hidden_variable_hpp

#include <QLabel>
#include <QDoubleSpinBox>
#include <QString>

class HiddenVar: public QObject{
    Q_OBJECT
public:
    
    HiddenVar(QString name = QString("untitled"), double value = 0.0);
    
    QLabel *nameLabel;
    
    QDoubleSpinBox *valueBox;
    
signals:
    
    void valueChanged(QString name, double value);
    
public slots:
    
    void updateValue();
};
#endif
