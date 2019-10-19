#include "user_data.hpp"

UserData::UserData() {
    jsonFilePath = QCoreApplication::applicationDirPath() + "/userData.json";
}

bool UserData::loadJson() {
    QFile loadFile(jsonFilePath);
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
    QFile saveFile(jsonFilePath);

    if (!saveFile.open(QIODevice::WriteOnly))
        return false;

    QJsonObject gameObject;
    write(gameObject);
    QJsonDocument saveDoc(gameObject);
    saveFile.write(saveDoc.toJson());
    return true;
}

HVarSet UserData::hiddenVariable(int currentRow) {
    return hVarList.at(currentRow);
}

QList<HVarSet> UserData::hiddenVarList() {
    return hVarList;
}

UPref UserData::userPreference() {
    return pref;
}

void UserData::clear() {
    pref.autoLoadParameter = true;
    pref.rmWithoutAsk = false;
    hVarList.clear();
}

/*
**************************************
MARK: - Once changing parameters, update this function
**************************************
*/
 bool UserData::read(const QJsonObject &json) {
     bool pass = true;
     
     // Read User Preference
     if (json.contains("UserPreference") && json["UserPreference"].isObject()) {
         QJsonObject obj = json["UserPreference"].toObject();
         if (obj.contains("autoLoadParameter") && obj["autoLoadParameter"].isBool())
             pref.autoLoadParameter = obj["autoLoadParameter"].toBool();
         else pass = false;
         if (obj.contains("rmWithoutAsk") && obj["rmWithoutAsk"].isBool())
             pref.rmWithoutAsk = obj["rmWithoutAsk"].toBool();
         else pass = false;
     }else pass = false;
     
     // Read Hidden Variable Template
     if (json.contains("Template") && json["Template"].isObject()) {
         QJsonObject obj = json["Template"].toObject();
         if (!obj.contains("filename"))
             return false;
         QStringList keyList = obj.keys();
         for (int i = 0; i < keyList.size(); i++) {
             if(obj[keyList[i]].isString())
                 model.addModel(keyList[i], StringType);
             else if (obj[keyList[i]].isDouble()){
                 model.addModel(keyList[i], DoubleType);
             } else return false;
         }
     } else return false;
     
     // Read Hidden Variables
     if (json.contains("HiddenVariable") && json["HiddenVariable"].isArray()) {
         QJsonArray varArray = json["HiddenVariable"].toArray();
         hVarList.clear();
         hVarList.reserve(varArray.size());
         for (int varIndex = 0; varIndex < varArray.size(); ++varIndex) {
             QJsonObject varObject = varArray[varIndex].toObject();
             HVarSet set;
             for(auto i : model.model){
                 switch (i.second) {
                     case DataType::StringType:
                         if (varObject.contains(i.first) && varObject[i.first].isString())
                             set.strList.push_back(varObject[i.first].toString());
                         else return false;
                         break;
                         
                     case DataType::DoubleType:
                         if (varObject.contains(i.first) && varObject[i.first].isDouble())
                             set.doubleList.push_back(varObject[i.first].toDouble());
                         else return false;
                         break;
                         
                     default:
                         qDebug() << "\nXuan: data type does not exist.\n";
                         break;
                 }
             }
             hVarList.append(set);
         }
     } else pass = false;
     return pass;
}

/*
**************************************
MARK: - Once changing parameters, update this function
**************************************
*/
void UserData::write(QJsonObject &json) {
    QJsonObject commentObject;
    commentObject["0_Overview"] = "The Json file needs contain three things: Template, HiddenVariable and UserPreference.";
    commentObject["1_Template"] = "Template is the template for hidden variables. You need specify what is included in each HiddenVariable object. Note that 'filename' must be included.";
    commentObject["2_HiddenVariable"] = "HiddenVariable is a JSON array. Each object in the array contains all necessary hidden variables, which are passed to python script as arguments. Note that 'filename' is the identifier for matching videos.";
    commentObject["3_UserPreference"] = "UserPreference contains all user preference settings. For example, if you check 'Always apply hidden parameters if the name matches' in hidden variable tab, it is recorded for next time use.";
    json["CommentThatCanbeDelete"] = commentObject;
    
    QJsonObject templateObject;
    for (auto i : model.model) {
        switch (i.second) {
            case DataType::StringType:
                templateObject[i.first] = "";
                break;
                
            case DataType::DoubleType:
                templateObject[i.first] = 0.0;
                break;
                
            default:
                qDebug() << "\nXuan: data type does not exist.\n";
                break;
        }
    }
    json["Template"] = templateObject;
    
    QJsonArray array;
    for(HVarSet i : hVarList) {
        QJsonObject obj;
        int strIndex = 0;
        int doubleIndex = 0;
        for(auto it : model.model){
            switch (it.second) {
                case DataType::StringType:
                    obj[it.first] = i.strList.at(strIndex);
                    strIndex++;
                    break;
                    
                case DataType::DoubleType:
                    obj[it.first] = i.doubleList.at(doubleIndex);
                    doubleIndex++;
                    break;
                    
                default:
                    qDebug() << "\nXuan: data type does not exist-.\n";
                    break;
            }
        }
        array.append(obj);
    }
    json["HiddenVariable"] = array;
    
    QJsonObject prefObject;
    prefObject["autoLoadParameter"] = pref.autoLoadParameter;
    prefObject["rmWithoutAsk"] = pref.rmWithoutAsk;
    json["UserPreference"] = prefObject;
}

/*
**************************************
MARK: - Once changing parameters, update this function
**************************************
*/
void UserData::setHiddenVariable(int currentRow, int index, double value) {
    auto set = hVarList.at(currentRow);
    set.doubleList.replace(index, value);
    hVarList.replace(currentRow, set);
}

void UserData::setHiddenVariableStr(int currentRow, int index, QString value) {
    auto set = hVarList.at(currentRow);
    set.strList.replace(index, value);
    hVarList.replace(currentRow, set);
}

void UserData::setAutoLoad(bool i) {
    pref.autoLoadParameter = i;
}

void UserData::setRmWithoutAsk(bool i) {
    pref.rmWithoutAsk = i;
}

/*
**************************************
MARK: - Once changing parameters, update this function
**************************************
*/
void UserData::addHiddenVariable(QString filename) {
    HVarSet set;
    for(auto i : model.model){
        switch (i.second) {
            case DataType::StringType:
                set.strList.push_back("");
                break;
                
            case DataType::DoubleType:
                set.doubleList.push_back(0.0);
                break;
                
            default:
                qDebug() << "\nXuan: data type does not exist--.\n";
                break;
        }
    }
    set.strList.replace(0, filename);
    hVarList.append(set);
}

bool UserData::removeHiddenVariable(int currentRow) {
    if (currentRow >= hVarList.size())
        return false;
    hVarList.removeAt(currentRow);
    return true;
}

HidVarModel UserData::hidenVarModel() const{
    return model;
}
