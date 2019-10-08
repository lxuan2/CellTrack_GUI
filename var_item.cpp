#include "var_item.hpp"

VarItem::VarItem(QString name, double value) {
    nameLabel = new QLabel(name + ":");
    valueBox = new QDoubleSpinBox();
    valueBox->setRange(-999999999, 999999999);
    valueBox->setDecimals(5);
    valueBox->setValue(value);
    
    QObject::connect(valueBox, &QDoubleSpinBox::editingFinished, this, &VarItem::updateValue);
}

void VarItem::updateValue() {
    emit valueChanged(this);
}

StrVarItem::StrVarItem(QString name, QString value) {
    nameLabel = new QLabel(name + ":");
    valueBox = new QLineEdit();
    valueBox->setText(value);
    
    QObject::connect(valueBox, &QLineEdit::textChanged, this, &StrVarItem::updateValue);
}

void StrVarItem::updateValue() {
    emit valueChanged(this);
}
