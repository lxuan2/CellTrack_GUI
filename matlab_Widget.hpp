#ifndef MATLAB_WIDGET_HPP
#define MATLAB_WIDGET_HPP

#include <QTabWidget>
#include <QCloseEvent>

#include "general_view.hpp"
#include "hidden_var_view.hpp"

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
    
    void closeEvent(QCloseEvent *event);
};

#endif
