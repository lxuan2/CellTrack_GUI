#include "hidden_variable.hpp"
#include <iostream>
HiddenVar::HiddenVar(QString name, double value) {
    nameLabel = new QLabel(name + ":");
    valueBox = new QDoubleSpinBox();
    valueBox->setRange(-999999999, 999999999);
    valueBox->setDecimals(5);
    valueBox->setValue(value);
    
    QObject::connect(valueBox, &QDoubleSpinBox::editingFinished, this, &HiddenVar::updateValue);
}

void HiddenVar::updateValue() {
    emit valueChanged(nameLabel->text(), valueBox->value());
}
