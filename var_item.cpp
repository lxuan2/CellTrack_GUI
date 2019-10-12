#include "var_item.hpp"

DoubleVarItem::DoubleVarItem(QString name, double value) {
    nameLabel = new QLabel(name + ":");
    valueBox = new QLineEdit();
    valueBox->setValidator(dynamic_cast<QValidator*>(new QDoubleValidator()));
    
    QObject::connect(valueBox, &QLineEdit::textChanged, this, &DoubleVarItem::updateValue);
}

void DoubleVarItem::updateValue() {
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
