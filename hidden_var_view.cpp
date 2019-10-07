#include "hidden_var_view.hpp"

HiddenVarView::HiddenVarView(UserData *d, LogView * l){
    data = d;
    log = l;
    list = new QListWidget();
    QObject::connect(list, &QListWidget::currentTextChanged, this, &HiddenVarView::updateParameter);
    //list->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //list->setMaximumWidth(200);
    saveButton = new QPushButton("Save Data");
    QObject::connect(saveButton, &QPushButton::clicked, this, &HiddenVarView::saveHiddenVar);
    addButton = new QPushButton("Add");
    QObject::connect(addButton, &QPushButton::clicked, this, &HiddenVarView::addButtonClicked);
    removeButton = new QPushButton("Remove");
    QObject::connect(removeButton, &QPushButton::clicked, this, &HiddenVarView::removeButtonClicked);
    saveButton->setDisabled(true);
    addButton->setDisabled(true);
    removeButton->setDisabled(true);
    
    param0 = new VarItem("Parameter 0", 0.0);
    param1 = new VarItem("Parameter 1", 0.0);
    param2 = new VarItem("Parameter 2", 0.0);
    param3 = new VarItem("Parameter 3", 0.0);
    param4 = new VarItem("Parameter 4", 0.0);
    param5 = new VarItem("Parameter 5", 0.0);
    param6 = new VarItem("Parameter 6", 0.0);
    param7 = new VarItem("Parameter 7", 0.0);
    
    QObject::connect(param0, &VarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param1, &VarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param2, &VarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param3, &VarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param4, &VarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param5, &VarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param6, &VarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param7, &VarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    
    QGridLayout *lay = new QGridLayout();
    lay->addWidget(param0->nameLabel, 0, 0, Qt::AlignRight);
    lay->addWidget(param1->nameLabel, 1, 0, Qt::AlignRight);
    lay->addWidget(param2->nameLabel, 2, 0, Qt::AlignRight);
    lay->addWidget(param3->nameLabel, 3, 0, Qt::AlignRight);
    lay->addWidget(param4->nameLabel, 4, 0, Qt::AlignRight);
    lay->addWidget(param5->nameLabel, 5, 0, Qt::AlignRight);
    lay->addWidget(param6->nameLabel, 6, 0, Qt::AlignRight);
    lay->addWidget(param7->nameLabel, 7, 0, Qt::AlignRight);
    
    lay->addWidget(param0->valueBox, 0, 1, 1, 2, Qt::AlignLeft);
    lay->addWidget(param1->valueBox, 1, 1, 1, 2, Qt::AlignLeft);
    lay->addWidget(param2->valueBox, 2, 1, 1, 2, Qt::AlignLeft);
    lay->addWidget(param3->valueBox, 3, 1, 1, 2, Qt::AlignLeft);
    lay->addWidget(param4->valueBox, 4, 1, 1, 2, Qt::AlignLeft);
    lay->addWidget(param5->valueBox, 5, 1, 1, 2, Qt::AlignLeft);
    lay->addWidget(param6->valueBox, 6, 1, 1, 2, Qt::AlignLeft);
    lay->addWidget(param7->valueBox, 7, 1, 1, 2, Qt::AlignLeft);
    group = new QGroupBox();
    group->setTitle("Hidden Parameters");
    group->setLayout(lay);
    
    auto title = new QLabel("Video Name:");
    auto it = title->font();
    it.setPointSize(11);
    title->setFont(it);
    
    autoLoadCheckBox = new QCheckBox("Always load hidden parameters if the name matches");
    QObject::connect(autoLoadCheckBox, &QCheckBox::stateChanged, this, &HiddenVarView::autoLoadClicked);
    
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(title, 0, 0, Qt::AlignLeft);
    layout->addWidget(group, 1, 4, 15, 5);
    layout->addWidget(list, 1, 0, 19, 2);
    layout->addWidget(addButton, 20, 0);
    layout->addWidget(removeButton, 20, 1);
    layout->addWidget(saveButton, 20, 8);
    layout->addWidget(autoLoadCheckBox, 20, 4, 1, 4, Qt::AlignCenter);
    setLayout(layout);
    
    // Load presetting from the json file
    loadParameters();
    autoLoadCheckBox->setChecked(data->userPreference().autoLoadParameter);
}

void HiddenVarView::addItem(QString name) {
    QListWidgetItem *newItem = new QListWidgetItem();
    newItem->setText(name);
    newItem->setSizeHint(QSize(23, 23));
    newItem->setTextAlignment(Qt::AlignCenter);
    
    // Set font size
    auto it = newItem->font();
    it.setPointSize(14);
    newItem->setFont(it);
    
    // Add to the list
    list->addItem(newItem);
}

void HiddenVarView::loadParameters() {
    if (data->hiddenVarList().length() == 0)
        return;
    for (HVarSet i : data->hiddenVarList()){
        addItem(i.fileName);
    }
    updateParameter(data->hiddenVarList().at(0).fileName);
    list->setCurrentRow(0);
}

void HiddenVarView::parameterChanged(VarItem *param) {
    if (list->currentItem() == nullptr)
        return;
    saveButton->setEnabled(true);
    data->setHiddenVariable(list->currentItem()->text(), param->nameLabel->text(), param->valueBox->value());
}

void HiddenVarView::saveHiddenVar() {
    parameterChanged(param0);
    parameterChanged(param1);
    parameterChanged(param2);
    parameterChanged(param3);
    parameterChanged(param4);
    parameterChanged(param5);
    parameterChanged(param6);
    parameterChanged(param7);
    saveButton->setEnabled(false);
}

void HiddenVarView::updateParameter(const QString &currentText) {
    //std::cout<<currentText.toStdString()<<std::endl;
    auto i = data->hiddenVariable(currentText);
    param0->valueBox->setValue(i.param0);
    param1->valueBox->setValue(i.param1);
    param2->valueBox->setValue(i.param2);
    param3->valueBox->setValue(i.param3);
    param4->valueBox->setValue(i.param4);
    param5->valueBox->setValue(i.param5);
    param6->valueBox->setValue(i.param6);
    param7->valueBox->setValue(i.param7);
}

void HiddenVarView::addButtonClicked() {
    
}

void HiddenVarView::removeButtonClicked() {
    
}

void HiddenVarView::autoLoadClicked(int state) {
    data->setAutoLoad(autoLoadCheckBox->isChecked());
}
