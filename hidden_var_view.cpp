#include "hidden_var_view.hpp"

HiddenVarView::HiddenVarView(UserData *d, LogView * l){
    data = d;
    log = l;
    list = new QListWidget();
    QObject::connect(list, &QListWidget::currentTextChanged, this, &HiddenVarView::updateParameter);
    
    addButton = new QPushButton("Add");
    QObject::connect(addButton, &QPushButton::clicked, this, &HiddenVarView::addButtonClicked);
    removeButton = new QPushButton("Remove");
    QObject::connect(removeButton, &QPushButton::clicked, this, &HiddenVarView::removeButtonClicked);
    showInFolderBT = new QPushButton("Show in Folder");
    QObject::connect(showInFolderBT, &QPushButton::clicked, this, &HiddenVarView::showInFolderClicked);
    discardAllBT = new QPushButton("Discard All Changes");
    QObject::connect(discardAllBT, &QPushButton::clicked, this, &HiddenVarView::discardAllBTClicked);
    
    filename = new StrVarItem("File Name", "");
    param0 = new VarItem("Parameter 0", 0.0);
    param1 = new VarItem("Parameter 1", 0.0);
    param2 = new VarItem("Parameter 2", 0.0);
    param3 = new VarItem("Parameter 3", 0.0);
    param4 = new VarItem("Parameter 4", 0.0);
    param5 = new VarItem("Parameter 5", 0.0);
    param6 = new VarItem("Parameter 6", 0.0);
    param7 = new VarItem("Parameter 7", 0.0);
    
    QObject::connect(filename, &StrVarItem::valueChanged, this, &HiddenVarView::strParameterChanged);
    QObject::connect(param0, &VarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param1, &VarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param2, &VarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param3, &VarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param4, &VarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param5, &VarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param6, &VarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param7, &VarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    
    QGridLayout *lay = new QGridLayout();
    lay->addWidget(filename->nameLabel, 0, 0, Qt::AlignRight);
    lay->addWidget(param0->nameLabel, 1, 0, Qt::AlignRight);
    lay->addWidget(param1->nameLabel, 2, 0, Qt::AlignRight);
    lay->addWidget(param2->nameLabel, 3, 0, Qt::AlignRight);
    lay->addWidget(param3->nameLabel, 4, 0, Qt::AlignRight);
    lay->addWidget(param4->nameLabel, 5, 0, Qt::AlignRight);
    lay->addWidget(param5->nameLabel, 6, 0, Qt::AlignRight);
    lay->addWidget(param6->nameLabel, 7, 0, Qt::AlignRight);
    lay->addWidget(param7->nameLabel, 8, 0, Qt::AlignRight);
    
    lay->addWidget(filename->valueBox, 0, 1, 1, 2, Qt::AlignLeft);
    lay->addWidget(param0->valueBox, 1, 1, 1, 2, Qt::AlignLeft);
    lay->addWidget(param1->valueBox, 2, 1, 1, 2, Qt::AlignLeft);
    lay->addWidget(param2->valueBox, 3, 1, 1, 2, Qt::AlignLeft);
    lay->addWidget(param3->valueBox, 4, 1, 1, 2, Qt::AlignLeft);
    lay->addWidget(param4->valueBox, 5, 1, 1, 2, Qt::AlignLeft);
    lay->addWidget(param5->valueBox, 6, 1, 1, 2, Qt::AlignLeft);
    lay->addWidget(param6->valueBox, 7, 1, 1, 2, Qt::AlignLeft);
    lay->addWidget(param7->valueBox, 8, 1, 1, 2, Qt::AlignLeft);
    group = new QGroupBox();
    group->setTitle("Hidden Parameters");
    group->setLayout(lay);
    
    auto title = new QLabel("Video Name:");
    auto it = title->font();
    it.setPointSize(11);
    title->setFont(it);
    
    autoLoadCheckBox = new QCheckBox("Always apply hidden parameters if the name matches");
    QObject::connect(autoLoadCheckBox, &QCheckBox::stateChanged, this, &HiddenVarView::autoLoadClicked);
    
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(title, 0, 0, Qt::AlignLeft);
    layout->addWidget(group, 1, 4, 15, 5);
    layout->addWidget(list, 1, 0, 18, 2);
    layout->addWidget(addButton, 19, 0);
    layout->addWidget(removeButton, 19, 1);
    layout->addWidget(discardAllBT, 20, 0, 1, 2);
    layout->addWidget(showInFolderBT, 20, 8);
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
    list->setCurrentRow(0);
}

void HiddenVarView::parameterChanged(VarItem *param) {
    if (list->currentItem() == nullptr)
        return;
    data->setHiddenVariable(list->currentItem()->text(), param->nameLabel->text(), param->valueBox->value());
}

void HiddenVarView::strParameterChanged(StrVarItem *param) {
    if (list->currentItem() == nullptr)
        return;
    data->setHiddenVariableStr(list->currentItem()->text(), param->nameLabel->text(), param->valueBox->text());
    if (param->nameLabel->text() == QString::fromStdString("File Name:"))
        list->currentItem()->setText(param->valueBox->text());
}

void HiddenVarView::saveHiddenVar() {
    strParameterChanged(filename);
    parameterChanged(param0);
    parameterChanged(param1);
    parameterChanged(param2);
    parameterChanged(param3);
    parameterChanged(param4);
    parameterChanged(param5);
    parameterChanged(param6);
    parameterChanged(param7);
}

void HiddenVarView::updateParameter(const QString &currentText) {
    auto i = data->hiddenVariable(currentText);
    filename->valueBox->setText(i.fileName);
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
    QString newFileName = "untitled" + QString::number(list->count());
    data->addHiddenVariable(newFileName);
    addItem(newFileName);
    list->setCurrentRow(list->count() - 1);
}

void HiddenVarView::removeButtonClicked() {
    if (list->count() == 0) return;
    QMessageBox msgBox;
    msgBox.setText("Remove operation detected.");
    msgBox.setInformativeText("Do you want to remove the current item from the list?");
    msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::NoButton);
    msgBox.setIcon(QMessageBox::Warning);
    
    if (msgBox.exec() == QMessageBox::Yes) {
        if (!data->removeHiddenVariable(list->currentItem()->text())) {
            log->write("Error: Fail to remove item, since it does not exist in the list");
            QMessageBox msg;
            msg.setText("Error: Fail to remove item, since it does not exist in the list");
            msgBox.setIcon(QMessageBox::Critical);
            msg.exec();
            return;
        }
        int row = list->currentRow();
        list->takeItem(row);
        if (list->count() == 0) return;
        if (row == list->count())
            return list->setCurrentRow(row - 1);
        list->setCurrentRow(row);
    }
}

void HiddenVarView::autoLoadClicked(int state) {
    data->setAutoLoad(autoLoadCheckBox->isChecked());
}

void HiddenVarView::showInFolderClicked() {
    showFileInFolder((QCoreApplication::applicationDirPath() + "/userData.json"));
}

void HiddenVarView::discardAllBTClicked() {
    data->clear();
    list->clear();
    
    data->loadJson();
    loadParameters();
    autoLoadCheckBox->setChecked(data->userPreference().autoLoadParameter);
}
