#ifndef SETTING_APP_HPP
#define SETTING_APP_HPP

#include <QWidget>
#include <QLayout>
#include <QString>

#include "file_finder.hpp"

class SettingApp: public QWidget{
    Q_OBJECT
public:
    
    // Default constructor
    SettingApp(QWidget *parent = nullptr);
    
signals:
    
    void toMain(QString exeLoc);
    
private slots:
    
    void closeWindow();
    
private:
    
    FileFinder *finder;
};

#endif
