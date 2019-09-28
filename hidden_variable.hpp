#ifndef hidden_variable_hpp
#define hidden_variable_hpp

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QDoubleSpinBox>

class HiddenVar: public QWidget {
    Q_OBJECT
public:
    
    HiddenVar(QString name = QString("untitled"), double value = 0.0);
    
    QString name();
    
    double value();
    
    void setName(QString name);
    
    void setValue(double value);
    
private:
    
    QLabel * nameLabel;
    
    QDoubleSpinBox *valueBox;
};
#endif
