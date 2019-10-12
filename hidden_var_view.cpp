#include "hidden_var_view.hpp"

/*
**************************************
MARK: - Once changing parameters, update this function
**************************************
*/
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
    
    filename = new StrVarItem("fileName", "");
    param0 = new DoubleVarItem("parameter0", 0.0);
    param1 = new DoubleVarItem("parameter1", 0.0);
    param2 = new DoubleVarItem("parameter2", 0.0);
    param3 = new DoubleVarItem("parameter3", 0.0);
    param4 = new DoubleVarItem("parameter4", 0.0);
    param5 = new DoubleVarItem("parameter5", 0.0);
    param6 = new DoubleVarItem("parameter6", 0.0);
    param7 = new DoubleVarItem("parameter7", 0.0);
    
    QObject::connect(filename, &StrVarItem::valueChanged, this, &HiddenVarView::strParameterChanged);
    QObject::connect(param0, &DoubleVarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param1, &DoubleVarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param2, &DoubleVarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param3, &DoubleVarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param4, &DoubleVarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param5, &DoubleVarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param6, &DoubleVarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param7, &DoubleVarItem::valueChanged, this, &HiddenVarView::parameterChanged);
    
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
    QGroupBox *group = new QGroupBox();
    group->setTitle("Hidden Parameters");
    group->setLayout(lay);
    
    auto title = new QLabel("Video Name:");
    auto it = title->font();
    it.setPointSize(11);
    title->setFont(it);
    
    autoLoadCheckBox = new QCheckBox("Always apply hidden parameters if the name matches");
    QObject::connect(autoLoadCheckBox, &QCheckBox::stateChanged, this, &HiddenVarView::autoLoadClicked);
    
    rmWithoutAskCheckBox = new QCheckBox("Do not ask verification for remove operation");
    QObject::connect(rmWithoutAskCheckBox, &QCheckBox::stateChanged, this, &HiddenVarView::rmWithoutAskClicked);
    
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(title, 0, 0, Qt::AlignLeft);
    layout->addWidget(group, 1, 4, 15, 5);
    layout->addWidget(list, 1, 0, 18, 2);
    layout->addWidget(addButton, 19, 0);
    layout->addWidget(removeButton, 19, 1);
    layout->addWidget(rmWithoutAskCheckBox, 19, 4, 1, 4);
    layout->addWidget(discardAllBT, 20, 0, 1, 2);
    layout->addWidget(showInFolderBT, 20, 8);
    layout->addWidget(autoLoadCheckBox, 20, 4, 1, 4);
    setLayout(layout);
    
    // Load presetting parameters to the screen
    loadParameters();
}

/*
**************************************
MARK: - Once changing parameters, update this function
**************************************
*/
void HiddenVarView::updateParameter(const QString &currentText) {
    HVarSet i = data->hiddenVariable(currentText);
    filename->valueBox->setText(i.fileName);
    param0->valueBox->setText(QString::number(i.param0, 'g', 15));
    param1->valueBox->setText(QString::number(i.param1, 'g', 15));
    param2->valueBox->setText(QString::number(i.param2, 'g', 15));
    param3->valueBox->setText(QString::number(i.param3, 'g', 15));
    param4->valueBox->setText(QString::number(i.param4, 'g', 15));
    param5->valueBox->setText(QString::number(i.param5, 'g', 15));
    param6->valueBox->setText(QString::number(i.param6, 'g', 15));
    param7->valueBox->setText(QString::number(i.param7, 'g', 15));
}

void HiddenVarView::parameterChanged(DoubleVarItem *param) {
    if (list->currentItem() == nullptr)
        return;
    data->setHiddenVariable(list->currentItem()->text(), param->nameLabel->text(), param->valueBox->text().toDouble());
}

void HiddenVarView::strParameterChanged(StrVarItem *param) {
    if (list->currentItem() == nullptr)
        return;
    data->setHiddenVariableStr(list->currentItem()->text(), param->nameLabel->text(), param->valueBox->text());
    if (param->nameLabel->text() == QString::fromStdString("fileName:"))
        list->currentItem()->setText(param->valueBox->text());
}

/*###########################################
#           Event Handle Functions          #
###########################################*/

void HiddenVarView::addButtonClicked() {
    QString newFileName = "untitled" + QString::number(list->count());
    data->addHiddenVariable(newFileName);
    addItem(newFileName);
    list->setCurrentRow(list->count() - 1);
}

void HiddenVarView::removeButtonClicked() {
    if (list->count() == 0) return;
    int ret = QMessageBox::Yes;
    if (!rmWithoutAskCheckBox->isChecked()) {
        QMessageBox msgBox;
        msgBox.setText("Remove operation detected.");
        msgBox.setInformativeText("Do you want to remove the current item from the list?");
        msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Yes);
        msgBox.setDefaultButton(QMessageBox::NoButton);
        msgBox.setIcon(QMessageBox::Warning);
        ret = msgBox.exec();
    }
    if (ret == QMessageBox::Yes) {
        if (!data->removeHiddenVariable(list->currentItem()->text())) {
            log->write("Error: Fail to remove item, since it does not exist in the list");
            QMessageBox msg;
            msg.setText("Error: Fail to remove item, since it does not exist in the list");
            msg.setIcon(QMessageBox::Critical);
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

void HiddenVarView::showInFolderClicked() {
    showFileInFolder(QCoreApplication::applicationDirPath() + "/userData.json");
}

void HiddenVarView::discardAllBTClicked() {
    data->clear();
    list->clear();
    data->loadJson();
    loadParameters();
}

void HiddenVarView::autoLoadClicked(int state) {
    data->setAutoLoad(autoLoadCheckBox->isChecked());
}

void HiddenVarView::rmWithoutAskClicked(int state) {
    data->setRmWithoutAsk(rmWithoutAskCheckBox->isChecked());
}

/*###########################################
#           Helper Functions                #
###########################################*/

void HiddenVarView::addItem(QString name) {
    QListWidgetItem *newItem = new QListWidgetItem();
    newItem->setText(name);
    
    newItem->setTextAlignment(Qt::AlignCenter);

//    // Set font size
    auto it = newItem->font();
    #if defined(_WIN32) || defined(_WIN64)    //Code for Windows
        it.setPointSize(10);
    #elif defined(__APPLE__)                  //Code for Mac
        it.setPointSize(14);
    #endif
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
    autoLoadCheckBox->setChecked(data->userPreference().autoLoadParameter);
    rmWithoutAskCheckBox->setChecked(data->userPreference().rmWithoutAsk);
}
