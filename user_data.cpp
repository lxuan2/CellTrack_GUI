#include "user_data.hpp"

UserData::UserData() {}

bool UserData::loadJson() {
    QFile loadFile((QCoreApplication::applicationDirPath() + "/userData.json"));
    if (!loadFile.exists())
        return false;
    
    if (!loadFile.open(QIODevice::ReadOnly))
        return false;
    
    QByteArray saveData = loadFile.readAll();
    QJsonParseError error;
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData, &error));
    if (error.error != QJsonParseError::NoError)
        return false;
    
    if (!read(loadDoc.object())) {
        clear();
        return false;
    }
    return true;
}

bool UserData::saveJson() {
    QFile saveFile((QCoreApplication::applicationDirPath() + "/userData.json"));

    if (!saveFile.open(QIODevice::WriteOnly))
        return false;

    QJsonObject gameObject;
    write(gameObject);
    QJsonDocument saveDoc(gameObject);
    saveFile.write(saveDoc.toJson());
    return true;
}

HVarSet UserData::hiddenVariable(QString name) {
    for (auto i : hVarList) {
        if (name == i.fileName)
            return i;
    }
    return HVarSet();
}

QVector<HVarSet> UserData::hiddenVarList() {
    return hVarList;
}

UPref UserData::userPreference() {
    return pref;
}

void UserData::clear() {
    hVarList.clear();
    pref.autoLoadParameter = true;
    pref.rmWithoutAsk = false;
}

 bool UserData::read(const QJsonObject &json) {
     bool pass = true;
     if (json.contains("userPreference") && json["userPreference"].isObject()) {
         QJsonObject obj = json["userPreference"].toObject();
         if (obj.contains("autoLoadParameter") && obj["autoLoadParameter"].isBool())
             pref.autoLoadParameter = obj["autoLoadParameter"].toBool();
         else pass = false;
         if (obj.contains("rmWithoutAsk") && obj["rmWithoutAsk"].isBool())
             pref.rmWithoutAsk = obj["rmWithoutAsk"].toBool();
         else pass = false;
     }
     else
         pass = false;
     
     if (json.contains("hiddenVariable") && json["hiddenVariable"].isArray()) {
         QJsonArray varArray = json["hiddenVariable"].toArray();
         hVarList.clear();
         hVarList.reserve(varArray.size());
         for (int varIndex = 0; varIndex < varArray.size(); ++varIndex) {
             QJsonObject varObject = varArray[varIndex].toObject();
             HVarSet set;
             if (varObject.contains("fileName") && varObject["fileName"].isString())
                 set.fileName = varObject["fileName"].toString();
             else pass = false;
            
             if (varObject.contains("parameter0") && varObject["parameter0"].isDouble())
                 set.param0 = varObject["parameter0"].toDouble();
             else pass = false;
            
             if (varObject.contains("parameter1") && varObject["parameter1"].isDouble())
                 set.param1 = varObject["parameter1"].toDouble();
             else pass = false;
            
             if (varObject.contains("parameter2") && varObject["parameter2"].isDouble())
                 set.param2 = varObject["parameter2"].toDouble();
             else pass = false;
            
             if (varObject.contains("parameter3") && varObject["parameter3"].isDouble())
                 set.param3 = varObject["parameter3"].toDouble();
             else pass = false;
            
             if (varObject.contains("parameter4") && varObject["parameter4"].isDouble())
                 set.param4 = varObject["parameter4"].toDouble();
             else pass = false;
            
             if (varObject.contains("parameter5") && varObject["parameter5"].isDouble())
                 set.param5 = varObject["parameter5"].toDouble();
             else pass = false;
            
             if (varObject.contains("parameter6") && varObject["parameter6"].isDouble())
                 set.param6 = varObject["parameter6"].toDouble();
             else pass = false;
            
             if (varObject.contains("parameter7") && varObject["parameter7"].isDouble())
                 set.param7 = varObject["parameter7"].toDouble();
             else pass = false;
             hVarList.append(set);
         }
     } else pass = false;
     return pass;
}

void UserData::write(QJsonObject &json) {
    QJsonArray array;
    for(HVarSet &i : hVarList) {
        QJsonObject obj;
        obj["fileName"] = i.fileName;
        obj["parameter0"] = i.param0;
        obj["parameter1"] = i.param1;
        obj["parameter2"] = i.param2;
        obj["parameter3"] = i.param3;
        obj["parameter4"] = i.param4;
        obj["parameter5"] = i.param5;
        obj["parameter6"] = i.param6;
        obj["parameter7"] = i.param7;
        array.append(obj);
    }
    json["hiddenVariable"] = array;
    
    QJsonObject prefObject;
    prefObject["autoLoadParameter"] = pref.autoLoadParameter;
    prefObject["rmWithoutAsk"] = pref.rmWithoutAsk;
    json["userPreference"] = prefObject;
}


void UserData::setHiddenVariable(QString filename, QString param, double value) {
    for(int i = 0; i < hVarList.size(); i++) {
        auto it = hVarList.at(i);
        if (it.fileName == filename){
            if(param == "Parameter 0:")
                hVarList[i].param0 = value;
            else if(param == "Parameter 1:")
                hVarList[i].param1 = value;
            else if(param == "Parameter 2:")
                hVarList[i].param2 = value;
            else if(param == "Parameter 3:")
                hVarList[i].param3 = value;
            else if(param == "Parameter 4:")
                hVarList[i].param4 = value;
            else if(param == "Parameter 5:")
                hVarList[i].param5 = value;
            else if(param == "Parameter 6:")
                hVarList[i].param6 = value;
            else if(param == "Parameter 7:")
                hVarList[i].param7 = value;
        }
    }
}

void UserData::setHiddenVariableStr(QString filename, QString param, QString value) {
    for(int i = 0; i < hVarList.size(); i++) {
        auto it = hVarList.at(i);
        if (it.fileName == filename){
            if(param == "File Name:")
                hVarList[i].fileName = value;
        }
    }
}

void UserData::setAutoLoad(bool i) {
    pref.autoLoadParameter = i;
}

void UserData::setRmWithoutAsk(bool i) {
    pref.rmWithoutAsk = i;
}

void UserData::addHiddenVariable(QString filename) {
    HVarSet set;
    set.fileName = filename;
    set.param0 = 0.0;
    set.param1 = 0.0;
    set.param2 = 0.0;
    set.param3 = 0.0;
    set.param4 = 0.0;
    set.param5 = 0.0;
    set.param6 = 0.0;
    set.param7 = 0.0;
    hVarList.append(set);
}

bool UserData::removeHiddenVariable(QString filename) {
    for(int i = 0; i < hVarList.size(); i++) {
        auto it = hVarList.at(i);
        if (it.fileName == filename){
            hVarList.removeAt(i);
            return true;
        }
    }
    return false;
}
