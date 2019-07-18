#include "control_panel_groupbox.hpp"

ControPannelGroupBox::ControPannelGroupBox(LogWidget *l) {
    log = l;
    setTitle("Control Panel");
    maxCellSize = new QSpinBox();
    minCellSize = new QSpinBox();
    analyzeButton = new QPushButton("Analyze");
    
    auto *layout = new QGridLayout();
    layout->addWidget(new QLabel("Cell Size:"), 0, 0);
    layout->addWidget(new QLabel("max:"), 1, 1);
    layout->addWidget(maxCellSize, 1, 2, 1, 4);
    layout->addWidget(new QLabel("min:"), 1, 6);
    layout->addWidget(minCellSize, 1, 7, 1, 4);
    layout->addWidget(analyzeButton, 2, 15);
    setLayout(layout);
}
