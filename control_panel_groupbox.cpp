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
    
    // Cell Size Widget
    QWidget * cellSizeWidget = new QWidget();
    auto csLayout = new QHBoxLayout();
    csLayout->addWidget(new QLabel("Cell Size:"));
    csLayout->addWidget(new QLabel("max"));
    csLayout->addWidget(maxCellSize);
    csLayout->addWidget(new QLabel("min"));
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
