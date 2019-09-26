#ifndef MATLAB_WIDGET_HPP
#define MATLAB_WIDGET_HPP

#include <QTabWidget>

#include "general_view.hpp"
#include "hidden_var_view.hpp"

class MatlabWidget: public QWidget{
    Q_OBJECT
public:
    
    // Default constructor
    MatlabWidget();
    
    // Set C# Application location
    void setExeLoc(QString exeLoc);
    
signals:
    
    void createView(int id);
    
private:
    
    GeneralView *general;
    
    HiddenVarView *hiddenVar;
    
    // Log View
    LogView *log;
    
};

#endif
