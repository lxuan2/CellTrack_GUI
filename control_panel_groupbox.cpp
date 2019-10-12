#include "control_panel_groupbox.hpp"

ControlPannel::ControlPannel(LogView *l) {
    log = l;
    setTitle("Parameters");
    maxCellSize = new QSpinBox();
    minCellSize = new QSpinBox();
    maxCellSize->setMaximum(99999);
    minCellSize->setMaximum(99999);
	maxCellSize->setMinimumWidth(1);
	minCellSize->setMinimumWidth(1);
    
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
    setLayout(layout);
}

int ControlPannel::maxSize() {
    return maxCellSize->value();
}

int ControlPannel::minSize() {
    return minCellSize->value();
}

bool ControlPannel::isAreaChecked() {
    return areaCheckbox->isChecked();
}

bool ControlPannel::isEccentricityChecked() {
    return eccentricityChecbox->isChecked();
}

bool ControlPannel::isOrientationChecked() {
    return orientationCheckbox->isChecked();
}
