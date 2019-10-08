//
//  hidden_variables.hpp
//  CellTrack
//
//  Created by Xuan Li on 9/25/19.
//

#ifndef hidden_variables_hpp
#define hidden_variables_hpp

#include <QListWidget>
#include <QGroupBox>
#include <QCheckBox>
#include <QMessageBox>

#include "log_view.hpp"
#include "var_item.hpp"
#include "user_data.hpp"

class HiddenVarView: public QWidget{
    Q_OBJECT
public:
    
    // Default constructor
    HiddenVarView(UserData *d, LogView * l);
    
    void saveHiddenVar();
    
private slots:
    
    void parameterChanged(VarItem *param);
    
    void strParameterChanged(StrVarItem *param);
    
    void updateParameter(const QString &currentText);
    
    void addButtonClicked();
    
    void removeButtonClicked();
    
    void showInFolderClicked();
    
    void discardAllBTClicked();
    
    void autoLoadClicked(int state);
    
private:
    
    QListWidget * list;
    
    QPushButton * addButton;
    QPushButton * removeButton;
    QPushButton * showInFolderBT;
    QPushButton * discardAllBT;
    
    QCheckBox * autoLoadCheckBox;
    
    LogView * log;
    
    QGroupBox *group;
    
    StrVarItem *filename;
    VarItem *param0;
    VarItem *param1;
    VarItem *param2;
    VarItem *param3;
    VarItem *param4;
    VarItem *param5;
    VarItem *param6;
    VarItem *param7;
    
    UserData *data;
    
    void addItem(QString name);
    
    void loadParameters();
};

#endif
