#ifndef INTRO_WIDGET_HPP
#define INTRO_WIDGET_HPP

#include <QDialog>
#include <QLayout>
#include <QString>
#include <QPixmap>
#include <QImage>
#include <QLabel>
#include <QGraphicsView>
#include <QCheckBox>
#include <QPushButton>
#include <QCoreApplication>

#include "file_finder.hpp"

class IntroWidget: public QDialog{
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
    
    QCheckBox *matlab;
    QCheckBox *python;
    
    QPushButton *OK;
    
    void matlabClicked();
    void pythonClicked();
};

#endif
