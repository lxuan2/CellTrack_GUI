#include "parameter_model.hpp"

HidVarModel::HidVarModel(): model() {}

void HidVarModel::addModel(QString str, DataType type) {
    if (str == "filename")
        return model.push_front(std::pair<QString, DataType>(str, type));
    model.push_back(std::pair<QString, DataType>(str, type));
}
