#ifndef INTRO_WIDGET_HPP
#define INTRO_WIDGET_HPP

#include <QWidget>
#include <QLayout>
#include <QString>

#include "file_finder.hpp"

class IntroWidget: public QWidget{
    Q_OBJECT
public:
    
    // Default constructor
    IntroWidget(QWidget *parent = nullptr);
    
signals:

    void createView(int id);
    
    void setExeLoc(QString exeLoc);

    
private slots:
    
    void closeWindow();
    
private:
    
    FileFinder *finder;
};

#endif
