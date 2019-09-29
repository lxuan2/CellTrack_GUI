#include "hidden_var_view.hpp"
#include <iostream>
HiddenVarView::HiddenVarView(LogView * l) {
    log = l;
    list = new QListWidget();
    QObject::connect(list, &QListWidget::currentTextChanged, this, &HiddenVarView::updateParameter);
    //list->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //list->setMaximumWidth(200);
    saveButton = new QPushButton("Save Data");
    QObject::connect(saveButton, &QPushButton::clicked, this, &HiddenVarView::saveToFile);
    addButton = new QPushButton("Add");
    QObject::connect(addButton, &QPushButton::clicked, this, &HiddenVarView::addButtonClicked);
    removeButton = new QPushButton("Remove");
    QObject::connect(removeButton, &QPushButton::clicked, this, &HiddenVarView::removeButtonClicked);
    saveButton->setDisabled(true);
    addButton->setDisabled(true);
    removeButton->setDisabled(true);
    
    param0 = new HiddenVar("Parameter 0", 0.0);
    param1 = new HiddenVar("Parameter 1", 0.0);
    param2 = new HiddenVar("Parameter 2", 0.0);
    param3 = new HiddenVar("Parameter 3", 0.0);
    param4 = new HiddenVar("Parameter 4", 0.0);
    param5 = new HiddenVar("Parameter 5", 0.0);
    param6 = new HiddenVar("Parameter 6", 0.0);
    param7 = new HiddenVar("Parameter 7", 0.0);
    
    QObject::connect(param0, &HiddenVar::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param1, &HiddenVar::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param2, &HiddenVar::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param3, &HiddenVar::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param4, &HiddenVar::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param5, &HiddenVar::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param6, &HiddenVar::valueChanged, this, &HiddenVarView::parameterChanged);
    QObject::connect(param7, &HiddenVar::valueChanged, this, &HiddenVarView::parameterChanged);
    
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
    QGroupBox *group = new QGroupBox();
    group->setTitle("Hidden Parameters");
    group->setLayout(lay);
    
    auto title = new QLabel("Video Name:");
    auto it = title->font();
    it.setPointSize(11);
    title->setFont(it);
    
    autoLoadCheckBox = new QCheckBox("Always load hidden parameters if the name matches");
    autoLoadCheckBox->setChecked(true);
    
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
    loadfromFile();
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

void HiddenVarView::loadfromFile() {
    addItem("first");
    addItem("second");
    // TODO:
}

void HiddenVarView::parameterChanged(QString name, double value) {
    // TODO: save to data in list
    saveButton->setEnabled(true);
    std::cout<<name.toStdString()<<" "<<value<<std::endl;
}

void HiddenVarView::saveToFile() {
    // TODO: if close, have to save to file. Optional
    saveButton->setEnabled(false);
}

void HiddenVarView::updateParameter(const QString &currentText) {
    // TODO: load last one
    std::cout<<currentText.toStdString()<<std::endl;
}

void HiddenVarView::addButtonClicked() {
    
}

void HiddenVarView::removeButtonClicked() {
    
}
