#include "parameter_groupbox.hpp"

ParameterMABox::ParameterMABox(LogView *l) {
    log = l;
    setTitle("Parameters");
    maxCellSize = new QSpinBox();
    minCellSize = new QSpinBox();
    maxCellSize->setMaximum(9999999);
    minCellSize->setMaximum(9999999);
    maxCellSize->setFixedWidth(70);
    minCellSize->setFixedWidth(70);
    
    areaCheckbox = new QCheckBox("Area");
    eccentricityChecbox = new QCheckBox("Eccentricity");
    orientationCheckbox = new QCheckBox("Orientation");
    
    // QLabels
    QLabel *csLabel = new QLabel("Cell Size:");
    QLabel *maxLabel = new QLabel("max");
    QLabel *minLabel = new QLabel("min");
    csLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    maxLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    minLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    
    // Seperator Line
    QWidget *lineA = new QWidget;
    lineA->setFixedHeight(2);
    lineA->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    lineA->setStyleSheet(QString("background-color: #c0c0c0;"));
    
    // Cell Size Widget
    QWidget * cellSizeWidget = new QWidget();
    auto csLayout = new QHBoxLayout();
    csLayout->addWidget(csLabel);
    csLayout->addWidget(maxLabel);
    csLayout->addWidget(maxCellSize);
    csLayout->addWidget(minLabel);
    csLayout->addWidget(minCellSize);
    cellSizeWidget->setLayout(csLayout);
    
    // Checkbox Widget
    QWidget * checkboxWidget = new QWidget();
    auto cLayout = new QHBoxLayout();
    cLayout->addWidget(areaCheckbox);
    cLayout->addWidget(eccentricityChecbox);
    cLayout->addWidget(orientationCheckbox);
    checkboxWidget->setLayout(cLayout);
    
    auto *layout = new QGridLayout();
    layout->addWidget(cellSizeWidget, 1, 0, 1, 6);
    layout->addWidget(new QLabel(""), 2, 0);
    layout->addWidget(checkboxWidget, 3, 0, 1, 6);
    layout->addWidget(lineA, 6, 0, 1, 6);
    layout->addWidget(new QLabel("Note: If max and min is zero, default max and min\nis applied based on video name."), 7, 0, 1, 6);
    setLayout(layout);
}

int ParameterMABox::maxSize() {
    return maxCellSize->value();
}

int ParameterMABox::minSize() {
    return minCellSize->value();
}

bool ParameterMABox::isAreaChecked() {
    return areaCheckbox->isChecked();
}

bool ParameterMABox::isEccentricityChecked() {
    return eccentricityChecbox->isChecked();
}

bool ParameterMABox::isOrientationChecked() {
    return orientationCheckbox->isChecked();
}

ParameterPyBox::ParameterPyBox(HiddenVarView *hidden, LogView *l) {
    this->hidden = hidden;
    log = l;
    setTitle("Parameters");
    widget = new QStackedWidget();
    widget->setContentsMargins(0, 0, 0, 0);
    
    QLabel *description = new QLabel("The matched hidden parameters show here,\nwhen the source video is loaded. ");
    description->setAlignment(Qt::AlignCenter);
    
    QLabel *noMatch = new QLabel("There are no matched parameters with given video name.");
    noMatch->setAlignment(Qt::AlignCenter);
    
    QLabel *fileNoExist = new QLabel("The source video file does not exist in the folder.");
    fileNoExist->setAlignment(Qt::AlignCenter);
    
    list = new QList<QLabel*>();
    QGridLayout * lay = new QGridLayout();
    QLabel *parameter;
    for (int i = 0; i < hidden->getParameterNum(); i++) {
        parameter = new QLabel("");
        parameter->setAlignment(Qt::AlignCenter);
        lay->addWidget(parameter, i % 10, i / 10, Qt::AlignCenter);
        list->append(parameter);
    }
    QWidget *view = new QWidget();
    view->setLayout(lay);
    
    widget->addWidget(description);
    widget->addWidget(view);
    widget->addWidget(noMatch);
    widget->addWidget(fileNoExist);
    auto *layout = new QVBoxLayout();
    layout->addWidget(widget);
    setLayout(layout);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
}

void ParameterPyBox::updateSrc(QString str) {
    if (str.isEmpty())
        return widget->setCurrentIndex(0);
    
    QFileInfo file(str);
    if (!file.exists())
        return widget->setCurrentIndex(3);
    
    QString name = file.fileName();
    if (hidden->isMatched(name)) {
        QStringList paramList = hidden->getPrintArguments(name);
        //qDebug() << paramList.count() << "   " << list->count();
        list->at(0)->setText("filename: " + name);
        for (int i = 1; i < list->count(); i++) {
            list->at(i)->setText(paramList.at(i - 1));
        }
        return widget->setCurrentIndex(1);
    }
    widget->setCurrentIndex(2);
}
