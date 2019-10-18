//
//  parameter_model.hpp
//  CellTrack
//
//  Created by Xuan Li on 10/18/19.
//

#ifndef parameter_model_hpp
#define parameter_model_hpp

#include <QString>

enum DataType { StringType, DoubleType };

class HidVarModel {
    
public:
    HidVarModel();
    
    void addModel(QString str, DataType type);
    
    QList<std::pair<QString, DataType>> model;
};

#endif /* parameter_model_hpp */
