#include "hidden_var_view.hpp"

HiddenVarView::HiddenVarView(UserData *d, LogView * l): strList(), doubleList(){
    data = d;
    log = l;
    list = new QListWidget();
    QObject::connect(list, &QListWidget::currentRowChanged, this, &HiddenVarView::updateParameter);
    
    addButton = new QPushButton("Add");
    QObject::connect(addButton, &QPushButton::clicked, this, &HiddenVarView::addButtonClicked);
    removeButton = new QPushButton("Remove");
    QObject::connect(removeButton, &QPushButton::clicked, this, &HiddenVarView::removeButtonClicked);
    showInFolderBT = new QPushButton("Show in Folder");
    QObject::connect(showInFolderBT, &QPushButton::clicked, this, &HiddenVarView::showInFolderClicked);
    discardAllBT = new QPushButton("Discard All Changes");
    QObject::connect(discardAllBT, &QPushButton::clicked, this, &HiddenVarView::discardAllBTClicked);
    
    // add hidden variable to widget
    int xCoordinate = 0;
    HidVarModel model = data->hidenVarModel();
    QGridLayout *lay = new QGridLayout();
    StrVarItem *itt;
    DoubleVarItem *ittt;
    for(auto i : model.model){
        switch (i.second) {
            case DataType::StringType:
                itt = new StrVarItem(i.first, "");
                strList.push_back(itt);
                QObject::connect(itt, &StrVarItem::valueChanged, this, &HiddenVarView::strParameterChanged);
                lay->addWidget(itt->nameLabel, xCoordinate, 0, Qt::AlignRight);
                lay->addWidget(itt->valueBox, xCoordinate, 1, 1, 2, Qt::AlignLeft);
                xCoordinate++;
                break;

            case DataType::DoubleType:
                ittt = new DoubleVarItem(i.first, 0.0);
                doubleList.push_back(ittt);
                QObject::connect(doubleList.last(), &DoubleVarItem::valueChanged, this, &HiddenVarView::doubleParameterChanged);
                lay->addWidget(doubleList.last()->nameLabel, xCoordinate, 0, Qt::AlignRight);
                lay->addWidget(doubleList.last()->valueBox, xCoordinate, 1, 1, 2, Qt::AlignLeft);
                xCoordinate++;
                break;

            default:
                log->write("Error: DataType does not exist.");
                break;
        }
    }
    
    group = new QGroupBox();
    group->setTitle("Hidden Parameters");
    group->setLayout(lay);
    
    auto title = new QLabel("Video Name:");
    auto it = title->font();
    it.setPointSize(11);
    title->setFont(it);
    
    rmWithoutAskCheckBox = new QCheckBox("Do not ask verification for remove operation");
    QObject::connect(rmWithoutAskCheckBox, &QCheckBox::stateChanged, this, &HiddenVarView::rmWithoutAskClicked);
    
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(title, 0, 0, Qt::AlignLeft);
    layout->addWidget(group, 1, 4, 15, 5);
    layout->addWidget(list, 1, 0, 18, 2);
    layout->addWidget(addButton, 19, 0);
    layout->addWidget(removeButton, 19, 1);
    layout->addWidget(discardAllBT, 20, 0, 1, 2);
    layout->addWidget(showInFolderBT, 20, 8);
    layout->addWidget(rmWithoutAskCheckBox, 20, 4, 1, 4);
    setLayout(layout);
    
    // Load presetting parameters to the screen
    loadParameters();
}

QStringList HiddenVarView::getArguments(QString &filename) {
    QStringList arguments;
    int row = -1;
    for (int i = 0; i < list->count(); i++) {
        if (list->item(i)->text() == filename)
            row = i;
    }
    
    if (row == -1) {
        for (int i = 1; i < strList.size(); i++) {
            arguments << "";
        }
        
        for (int i = 0; i < doubleList.size(); i++) {
            arguments << "0";
        }
        return arguments;
    }
    HVarSet set = data->hiddenVariable(row);
    
    for (int i = 1; i < strList.size(); i++) {
        arguments << set.strList.at(i);
    }
    
    for (int i = 0; i < doubleList.size(); i++) {
        arguments << QString::number(set.doubleList.at(i), 'g', 15);
    }
    return arguments;
}

QStringList HiddenVarView::getPrintArguments(QString &filename) {
    QStringList arguments;
    int row = -1;
    for (int i = 0; i < list->count(); i++) {
        if (list->item(i)->text() == filename)
            row = i;
    }
    
    if (row == -1) {
        for (int i = 1; i < strList.size(); i++) {
            arguments << "   " + strList.at(i)->nameLabel->text();
        }
        
        for (int i = 0; i < doubleList.size(); i++) {
            arguments << "   " + doubleList.at(i)->nameLabel->text() + " 0";
        }
        return arguments;
    }
    HVarSet set = data->hiddenVariable(row);
    
    for (int i = 1; i < strList.size(); i++) {
        arguments << "   " + strList.at(i)->nameLabel->text() + " " + set.strList.at(i);
    }
    
    for (int i = 0; i < doubleList.size(); i++) {
        arguments << "   " + doubleList.at(i)->nameLabel->text() + " " + QString::number(set.doubleList.at(i), 'g', 15);
    }
    return arguments;
}

void HiddenVarView::updateParameter(int currentRow) {
    group->setDisabled(false);
    HVarSet set = data->hiddenVariable(currentRow);

    for (int i = 0; i < strList.size(); i++) {
        strList.at(i)->valueBox->setText(set.strList.at(i));
    }
    
    for (int i = 0; i < doubleList.size(); i++) {
        doubleList.at(i)->valueBox->setText(QString::number(set.doubleList.at(i), 'g', 15));
    }
}

void HiddenVarView::doubleParameterChanged(DoubleVarItem *param) {
    if (list->currentItem() == nullptr)
        return;
    data->setHiddenVariable(list->currentRow(), doubleList.indexOf(param), param->valueBox->text().toDouble());
}

void HiddenVarView::strParameterChanged(StrVarItem *param) {
    if (list->currentItem() == nullptr)
        return;
    data->setHiddenVariableStr(list->currentRow(), strList.indexOf(param), param->valueBox->text());
    
    // If file name is changed, update name in the list
    if (strList.indexOf(param) == 0)
        list->currentItem()->setText(param->valueBox->text());
}

/*###########################################
#           Event Handle Functions          #
###########################################*/

void HiddenVarView::addButtonClicked() {
    QString newFileName = "untitled_" + QString::number(list->count());
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
        if (!data->removeHiddenVariable(list->currentRow())) {
            log->write("Error: Fail to remove item, since it does not exist in the list");
            QMessageBox msg;
            msg.setText("Error: Fail to remove item, since it does not exist in the list");
            msg.setIcon(QMessageBox::Critical);
            msg.exec();
            return;
        }
        QObject::disconnect(list, &QListWidget::currentRowChanged, this, &HiddenVarView::updateParameter);
        int row = list->currentRow();
        list->takeItem(row);
        if (list->count() == 0) {
            group->setDisabled(true);
            for (auto i : strList) {
                QObject::disconnect(i, &StrVarItem::valueChanged, this, &HiddenVarView::strParameterChanged);
                i->valueBox->setText("");
                QObject::connect(i, &StrVarItem::valueChanged, this, &HiddenVarView::strParameterChanged);
            }
            for (auto i : doubleList) {
                QObject::disconnect(i, &DoubleVarItem::valueChanged, this, &HiddenVarView::doubleParameterChanged);
                i->valueBox->setText("");
                QObject::connect(i, &DoubleVarItem::valueChanged, this, &HiddenVarView::doubleParameterChanged);
            }
            QObject::connect(list, &QListWidget::currentRowChanged, this, &HiddenVarView::updateParameter);
            return;
        }
        if (row == list->count())
            list->setCurrentRow(row - 1);
        updateParameter(list->currentRow());
        QObject::connect(list, &QListWidget::currentRowChanged, this, &HiddenVarView::updateParameter);
    }
}

void HiddenVarView::showInFolderClicked() {
    showFileInFolder(QCoreApplication::applicationDirPath() + "/userData.json");
}

void HiddenVarView::discardAllBTClicked() {
    data->clear();
    QObject::disconnect(list, &QListWidget::currentRowChanged, this, &HiddenVarView::updateParameter);
    list->clear();
    data->loadJson();
    loadParameters();
    if (list->count() == 0) {
        group->setDisabled(true);
        for (auto i : strList) {
            QObject::disconnect(i, &StrVarItem::valueChanged, this, &HiddenVarView::strParameterChanged);
            i->valueBox->setText("");
            QObject::connect(i, &StrVarItem::valueChanged, this, &HiddenVarView::strParameterChanged);
        }
        for (auto i : doubleList) {
            QObject::disconnect(i, &DoubleVarItem::valueChanged, this, &HiddenVarView::doubleParameterChanged);
            i->valueBox->setText("");
            QObject::connect(i, &DoubleVarItem::valueChanged, this, &HiddenVarView::doubleParameterChanged);
        }
        QObject::connect(list, &QListWidget::currentRowChanged, this, &HiddenVarView::updateParameter);
    }
    QObject::connect(list, &QListWidget::currentRowChanged, this, &HiddenVarView::updateParameter);
    if (list->count() != 0)
        updateParameter(0);
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

    // Set font size
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
    rmWithoutAskCheckBox->setChecked(data->userPreference().rmWithoutAsk);
    if (data->hiddenVarList().size() == 0)
        return group->setDisabled(true);
    for (HVarSet i : data->hiddenVarList()){
        addItem(i.strList.at(0));
    }
    list->setCurrentRow(0);
}
