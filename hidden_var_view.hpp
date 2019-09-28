//
//  hidden_variables.hpp
//  CellTrack
//
//  Created by Xuan Li on 9/25/19.
//

#ifndef hidden_variables_hpp
#define hidden_variables_hpp

#include <QListWidget>

#include "log_view.hpp"
#include "hidden_variable.hpp"

class HiddenVarView: public QWidget{
    Q_OBJECT
public:
    
    // Default constructor
    HiddenVarView(LogView * l);
    
private:
    
    QListWidget * list;
    
    QPushButton * saveButton;
    
    LogView * log;
    
    HiddenVar *param0;
    HiddenVar *param1;
    HiddenVar *param2;
    HiddenVar *param3;
    HiddenVar *param4;
    HiddenVar *param5;
    HiddenVar *param6;
    HiddenVar *param7;
    
    void addItem(QString name);
};

#endif
