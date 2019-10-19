#ifndef python_widget_hpp
#define python_widget_hpp

#include <QTabWidget>
#include <QCloseEvent>

#include "core.hpp"
#include "process_view.hpp"
#include "general_view.hpp"
#include "hidden_var_view.hpp"

class PythonWidget: public QWidget{
    Q_OBJECT
public:
    
    // Default constructor
    PythonWidget(QWidget *parent = nullptr);
    
signals:
    
    void createView(int id);
    
private slots:
    
    void closeWindow();
    
private:
    
    GeneralView *general;
    
    HiddenVarView *hiddenVar;
    
    LogView *log;
    
    UserData data;
    
    Core *core;
    
    ProcessView *proView;
    
    QPushButton *switchButton;
    
    void closeEvent(QCloseEvent *event);
    
    void showProcessView(bool value, QLabel *timeStr);
};


#endif
