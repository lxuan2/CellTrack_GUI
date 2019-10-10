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
    
private slots:
    
    void updateParameter(const QString &currentText);
    
    void parameterChanged(DoubleVarItem *param);
    
    void strParameterChanged(StrVarItem *param);
    
    void addButtonClicked();
    
    void removeButtonClicked();
    
    void showInFolderClicked();
    
    void discardAllBTClicked();
    
    void autoLoadClicked(int state);
    
    void rmWithoutAskClicked(int state);
    
private:
    
    LogView * log;
    StrVarItem *filename;
    
    /*
    **************************************
    MARK: - Once changing parameters, update these variables
    **************************************
    */
    DoubleVarItem *param0;
    DoubleVarItem *param1;
    DoubleVarItem *param2;
    DoubleVarItem *param3;
    DoubleVarItem *param4;
    DoubleVarItem *param5;
    DoubleVarItem *param6;
    DoubleVarItem *param7;
    
    // Backgroud UserData Manager
    UserData *data;
    
    // Item list
    QListWidget * list;
    
    // Buttons
    QPushButton * addButton;
    QPushButton * removeButton;
    QPushButton * showInFolderBT;
    QPushButton * discardAllBT;
    
    // Checkboxes
    QCheckBox * autoLoadCheckBox;
    QCheckBox * rmWithoutAskCheckBox;
    
    // Helper Function
    void addItem(QString name);
    
    void loadParameters();
};

#endif
