#ifndef MATLAB_WIDGET_HPP
#define MATLAB_WIDGET_HPP

#include <QTabWidget>
#include <QCloseEvent>

#include "core.hpp"
#include "process_view.hpp"

class MatlabWidget: public QDialog{
    Q_OBJECT
public:
    
    // Default constructor
    MatlabWidget(QWidget *parent = nullptr);
    
signals:
    
    void createView(int id);
    
private:
    
    GeneralView *general;
    
    LogView *log;
    
    Core *core;
    
    ProcessView *proView;
    
    void closeEvent(QCloseEvent *event);
    
    void showProcessView(bool value);
};

#endif
