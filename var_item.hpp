#ifndef hidden_variable_hpp
#define hidden_variable_hpp

#include <QLabel>
#include <QString>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QLayout>

class DoubleVarItem: public QWidget{
    Q_OBJECT
public:
    
    DoubleVarItem(QString name = QString("untitled"), double value = 0.0);
    
    QLabel *nameLabel;
    
    QLineEdit *valueBox;
    
signals:
    
    void valueChanged(DoubleVarItem *param);
    
public slots:
    
    void updateValue();
};

class StrVarItem: public QWidget{
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
