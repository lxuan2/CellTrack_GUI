#ifndef user_data_hpp
#define user_data_hpp

#include <QVector>
#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QCoreApplication>

struct HVarSet {
    QString fileName;
    double param0;
    double param1;
    double param2;
    double param3;
    double param4;
    double param5;
    double param6;
    double param7;
};

struct UPref {
    bool autoLoadParameter;
    bool rmWithoutAsk;
};

class UserData {
    
public:
    
    UserData();
    
    // Load and Write operations
    bool loadJson();
    
    bool saveJson();
    
    // Get information
    HVarSet hiddenVariable(QString name);
    
    QVector<HVarSet> hiddenVarList();
    
    UPref userPreference();
    
    // Update content
    void clear();
    
    void addHiddenVariable(QString filename);
    
    bool removeHiddenVariable(QString filename);
    
    void setHiddenVariable(QString filename, QString param, double value);
    
    void setHiddenVariableStr(QString filename, QString param, QString value);
    
    void setAutoLoad(bool i);
    
    void setRmWithoutAsk(bool i);
    
private:
    
    QVector<HVarSet> hVarList;
    
    UPref pref;
    
    bool read(const QJsonObject &json);
    
    void write(QJsonObject &json);
};

#endif
