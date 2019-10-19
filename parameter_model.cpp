#include "parameter_model.hpp"

HidVarModel::HidVarModel(): model() {
//    addModel("filename", StringType);
//    addModel("parameter0", DoubleType);
//    addModel("parameter1", DoubleType);
//    addModel("parameter2", DoubleType);
//    addModel("parameter3", DoubleType);
//    addModel("parameter4", DoubleType);
//    addModel("parameter5", DoubleType);
//    addModel("parameter6", DoubleType);
//    addModel("parameter7", DoubleType);
}

void HidVarModel::addModel(QString str, DataType type) {
    if (str == "filename")
        return model.push_front(std::pair<QString, DataType>(str, type));
    model.push_back(std::pair<QString, DataType>(str, type));
}
