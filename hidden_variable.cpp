#include "hidden_variable.hpp"
HiddenVar::HiddenVar(QString name, double value) {
    nameLabel = new QLabel(name + ":");
    valueBox = new QDoubleSpinBox();
    valueBox->setValue(value);
    QHBoxLayout *l = new QHBoxLayout();
    l->addWidget(nameLabel);
    l->addWidget(valueBox);
    setLayout(l);
}

QString HiddenVar::name() {
    return nameLabel->text();
}

double HiddenVar::value() {
    return valueBox->value();
}

void HiddenVar::setName(QString name) {
    nameLabel->setText(name);
}

void HiddenVar::setValue(double value) {
    valueBox->setValue(value);
}
