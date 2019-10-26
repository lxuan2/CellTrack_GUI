#ifndef MATLAB_WIDGET_HPP
#define MATLAB_WIDGET_HPP

#include <QTabWidget>
#include <QCloseEvent>

#include "core.hpp"
#include "process_view.hpp"
#include "helper_widget.hpp"

class MatlabWidget: public QWidget{
    Q_OBJECT
public:
    
    // Default constructor
    MatlabWidget(QWidget *parent = nullptr);
    
signals:
    
    void createView(int id);
    
private slots:
    
    void closeWindow();
    
    void infoClicked();
    
private:
    
    GeneralView *general;
    
    LogView *log;
    
    QTabWidget *tabView;
    
    Core *core;
    
    ProcessView *proView;
    
    QPushButton *switchButton;
    
    QToolButton *infoButton;
    
    void closeEvent(QCloseEvent *event);
};

#endif
