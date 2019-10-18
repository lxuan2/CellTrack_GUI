#ifndef user_data_hpp
#define user_data_hpp

#include <QVector>
#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QCoreApplication>
#include <QDebug>

#include "parameter_model.hpp"

// Hidden Variable Data Model
struct HVarSet {
    QList<QString> strList;
    QList<double> doubleList;
};

// User Preference Data Model
struct UPref {
    bool autoLoadParameter;
    bool rmWithoutAsk;
};

// User Data Model
class UserData {
    
public:
    
    // Default Constructor
    UserData();
    
    // Load user data from Json file
    bool loadJson();
    
    // Save user data to Json file
    bool saveJson();
    
    // Get information
    HVarSet hiddenVariable(int currentRow);
    
    QList<HVarSet> hiddenVarList();
    
    UPref userPreference();
    
    // Update content
    void clear();
    
    void addHiddenVariable(QString filename);
    
    bool removeHiddenVariable(int currentRow);
    
    void setHiddenVariable(int currentRow, int index, double value);
    
    void setHiddenVariableStr(int currentRow, int index, QString value);
    
    void setAutoLoad(bool i);
    
    void setRmWithoutAsk(bool i);
    
private:
    
    HidVarModel model;
    
    QList<HVarSet> hVarList;
    
    UPref pref;
    
    bool read(const QJsonObject &json);
    
    void write(QJsonObject &json);
};

#endif
