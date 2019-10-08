#ifndef hidden_variable_hpp
#define hidden_variable_hpp

#include <QLabel>
#include <QDoubleSpinBox>
#include <QString>
#include <QLineEdit>

class VarItem: public QObject{
    Q_OBJECT
public:
    
    VarItem(QString name = QString("untitled"), double value = 0.0);
    
    QLabel *nameLabel;
    
    QDoubleSpinBox *valueBox;
    
signals:
    
    void valueChanged(VarItem *param);
    
public slots:
    
    void updateValue();
};

class StrVarItem: public QObject{
    Q_OBJECT
public:
    
    StrVarItem(QString name = QString("untitled"), QString value = "untitled");
    
    QLabel *nameLabel;
    
    QLineEdit *valueBox;
    
signals:
    
    void valueChanged(StrVarItem *param);
    
public slots:
    
    void updateValue();
};
#endif
