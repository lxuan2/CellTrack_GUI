#ifndef SETTING_APP_HPP
#define SETTING_APP_HPP

#include <QWidget>
#include <QLayout>
#include <QString>

#include "file_finder.hpp"

class PreSettingView: public QWidget{
    Q_OBJECT
public:
    
    // Default constructor
    PreSettingView(QWidget *parent = nullptr);
    
signals:

    void createView(int id);
    
    void setExeLoc(QString exeLoc);

    
private slots:
    
    void closeWindow();
    
private:
    
    FileFinder *finder;
};

#endif
