#ifndef python_widget_hpp
#define python_widget_hpp

#include <QTabWidget>
#include <QCloseEvent>

#include "general_view.hpp"
#include "hidden_var_view.hpp"

class PythonWidget: public QDialog{
    Q_OBJECT
public:
    
    // Default constructor
    PythonWidget(QWidget *parent = nullptr);
    
signals:
    
    void createView(int id);
    
private:
    
    GeneralView *general;
    
    HiddenVarView *hiddenVar;
    
    LogView *log;
    
    UserData data;
    
    void closeEvent(QCloseEvent *event);
};


#endif
