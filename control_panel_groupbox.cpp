#include "control_panel_groupbox.hpp"

ControPannelGroupBox::ControPannelGroupBox(LogWidget *l) {
    log = l;
    setTitle("Control Panel");
    maxCellSize = new QSpinBox();
    minCellSize = new QSpinBox();
    
    analyzeButton = new QPushButton("Analyze");
    QObject::connect(analyzeButton, &QPushButton::clicked, this, &ControPannelGroupBox::anaButtonClicked);
    
    areaCheckbox = new QCheckBox("Area");
    eccentricityChecbox = new QCheckBox("Eccentricity");
    orientationCheckbox = new QCheckBox("Orientation");
    
    auto *layout = new QGridLayout();
    layout->addWidget(new QLabel("Cell Size:"), 0, 0);
    layout->addWidget(new QLabel("max"), 0, 1);
    layout->addWidget(maxCellSize, 0, 2, 1, 4);
    layout->addWidget(new QLabel("min"), 0, 6);
    layout->addWidget(minCellSize, 0, 7, 1, 4);
    // TODO:
    layout->addWidget(areaCheckbox, 0, 7, 1, 4);
    
    layout->addWidget(analyzeButton, 2, 11);
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
