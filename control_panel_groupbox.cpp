#include "control_panel_groupbox.hpp"

ControPannelGroupBox::ControPannelGroupBox(LogWidget *l) {
    log = l;
    setTitle("Control Panel");
    maxCellSize = new QSpinBox();
    minCellSize = new QSpinBox();
    maxCellSize->setMaximum(99999);
    minCellSize->setMaximum(99999);
    
    analyzeButton = new QPushButton("Analyze");
    QObject::connect(analyzeButton, &QPushButton::clicked, this, &ControPannelGroupBox::anaButtonClicked);
    
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
    layout->addWidget(cellSizeWidget, 0, 0, 1, 6);
    layout->addWidget(checkboxWidget, 1, 0, 1, 6);
    layout->addWidget(analyzeButton, 2, 5);
    layout->addWidget(lineA, 3, 0, 1, 6);
    
    setLayout(layout);
}

void ControPannelGroupBox::anaButtonClicked() {
    emit compute();
}

int ControPannelGroupBox::maxSize() {
    return maxCellSize->value();
}

int ControPannelGroupBox::minSize() {
    return minCellSize->value();
}

bool ControPannelGroupBox::isAreaChecked() {
    return areaCheckbox->isChecked();
}

bool ControPannelGroupBox::isEccentricityChecked() {
    return eccentricityChecbox->isChecked();
}

bool ControPannelGroupBox::isOrientationChecked() {
    return orientationCheckbox->isChecked();
}
