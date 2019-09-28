#include "hidden_var_view.hpp"
HiddenVarView::HiddenVarView(LogView * l) {
    log = l;
    list = new QListWidget();
    //list->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    list->setMaximumWidth(150);
    saveButton = new QPushButton("Save");
    
    param0 = new HiddenVar("Parameter 0", 0.0);
    param1 = new HiddenVar("Parameter 1", 0.0);
    param2 = new HiddenVar("Parameter 2", 0.0);
    param3 = new HiddenVar("Parameter 3", 0.0);
    param4 = new HiddenVar("Parameter 4", 0.0);
    param5 = new HiddenVar("Parameter 5", 0.0);
    param6 = new HiddenVar("Parameter 6", 0.0);
    param7 = new HiddenVar("Parameter 7", 0.0);
    
    QGridLayout *lay = new QGridLayout();
    lay->addWidget(param0, 0, 0);
    lay->addWidget(param1, 1, 0);
    lay->addWidget(param2, 2, 0);
    lay->addWidget(param3, 3, 0);
    lay->addWidget(param4, 4, 0);
    lay->addWidget(param5, 5, 0);
    lay->addWidget(param6, 6, 0);
    lay->addWidget(param7, 7, 0);
    QWidget *group = new QWidget();
    group->setLayout(lay);
    
    addItem("first");
    addItem("second");
    
//    layout->addWidget(new QLabel(""), 0, 3);
//    layout->addWidget(new QLabel(""), 0, 7);
//    layout->addWidget(new QLabel(""), 0, 8);
//    layout->addWidget(new QLabel("Parameter 0:"), 1, 4, Qt::AlignRight);
//    layout->addWidget(new QLabel(""), 2, 4, Qt::AlignRight);
//    layout->addWidget(new QLabel("Parameter 1:"), 3, 4, Qt::AlignRight);
//    layout->addWidget(new QLabel(""), 4, 4, Qt::AlignRight);
//    layout->addWidget(new QLabel("Parameter 2:"), 5, 4, Qt::AlignRight);
//    layout->addWidget(new QLabel(""), 6, 4, Qt::AlignRight);
//    layout->addWidget(new QLabel("Parameter 3:"), 7, 4, Qt::AlignRight);
//
//    layout->addWidget(new QLabel("Parameter 4:"), 1, 6, Qt::AlignRight);
//    layout->addWidget(new QLabel(""), 2, 6, Qt::AlignRight);
//    layout->addWidget(new QLabel("Parameter 5:"), 3, 6, Qt::AlignRight);
//    layout->addWidget(new QLabel(""), 4, 6, Qt::AlignRight);
//    layout->addWidget(new QLabel("Parameter 6:"), 5, 6, Qt::AlignRight);
//    layout->addWidget(new QLabel(""), 6, 6, Qt::AlignRight);
//    layout->addWidget(new QLabel("Parameter 7:"), 7, 6, Qt::AlignRight);
//
//    layout->addWidget(param0, 1, 5);
//    layout->addWidget(param1, 3, 5);
//    layout->addWidget(param2, 5, 5);
//    layout->addWidget(param3, 7, 5);
//    layout->addWidget(param4, 1, 7);
//    layout->addWidget(param5, 3, 7);
//    layout->addWidget(param6, 5, 7);
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(new QLabel("Parameters:"), 0, 0, Qt::AlignLeft);
    layout->addWidget(group, 0, 3, 15, 2);
    layout->addWidget(list, 1, 0, 20, 2);
    layout->addWidget(saveButton, 20, 7);
    setLayout(layout);
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
