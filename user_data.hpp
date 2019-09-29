#ifndef user_data_hpp
#define user_data_hpp

#include <QVector>
#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

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
};

class UserData {
    
public:
    
    UserData();
    
    bool loadJson(QString filePath);
    
    bool saveJson(QString filePath);
    
    HVarSet hiddenVariable(QString name);
    
    QVector<HVarSet> hiddenVarList();
    
    UPref userPreference();
    
    void clear();
    
    void setHiddenVariable(QString filename, QString param, double value);
    
    void setAutoLoad(bool i);
    
private:
    
    QVector<HVarSet> hVarList;
    
    UPref pref;
    
    bool read(const QJsonObject &json);
    
    void write(QJsonObject &json);
};

#endif
