#include "cell_app.hpp"

CellApp::CellApp() {
    
    // Widget initialize
    videoWidget = new DisplayWidget();
    
    // Button initialize and connection
    browseButton = new QPushButton("Browse");
    QObject::connect(browseButton, &QPushButton::clicked, this, &CellApp::browse);
    loadOrgButton = new QPushButton("Original Video");
    loadResButton = new QPushButton("Analyzed Video");
    analyzeButton = new QPushButton("Analyze");
    
    // Line-Edit initialize
    fileCombobox = new QComboBox();
    fileCombobox->setEditable(true);
    fileCombobox->setFrame(true);
    maxCellSize = new QSpinBox();
    minCellSize = new QSpinBox();
    
    // Group box initialize
    videoBox = new QGroupBox("Load Video");
    auto *tempLayout = new QGridLayout();
    tempLayout->addWidget(loadOrgButton, 0, 0);
    tempLayout->addWidget(loadResButton, 0, 1);
    videoBox->setLayout(tempLayout);
    
    controlBox = new QGroupBox("Control Panel");
    auto *temp1Layout = new QGridLayout();
    temp1Layout->addWidget(new QLabel("Cell Size:"), 0, 0);
    temp1Layout->addWidget(new QLabel("max:"), 1, 1);
    temp1Layout->addWidget(maxCellSize, 1, 2, 1, 4);
    temp1Layout->addWidget(new QLabel("min:"), 1, 6);
    temp1Layout->addWidget(minCellSize, 1, 7, 1, 4);
    temp1Layout->addWidget(analyzeButton, 2, 15);
    controlBox->setLayout(temp1Layout);
    
    // Widget layout initialize
    auto layout = new QGridLayout();
    layout->addWidget(new QLabel("File Location:"), 0, 0);
    layout->addWidget(fileCombobox, 0, 1, 1, 14);
    layout->addWidget(browseButton, 0, 15);
    layout->addWidget(videoWidget, 1, 0, 9, 16);
    layout->addWidget(videoBox, 10, 0, 1, 16);
    layout->addWidget(controlBox, 16, 0, 1, 16);
    setLayout(layout);
    //resize(500, 600);
}

void CellApp::browse() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::homePath());
    if (!fileName.isEmpty()) {
        if (fileCombobox->findText(fileName) == -1)
            fileCombobox->addItem(fileName);
        fileCombobox->setCurrentIndex(fileCombobox->findText(fileName));
    }
}

void CellApp::loadOrgVideo(int index) {
    QString fileName = fileCombobox->currentText();
    std::cout << fileName.toStdString() << endl;
}
