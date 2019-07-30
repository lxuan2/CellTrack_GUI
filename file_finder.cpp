#include "file_finder.hpp"

FileFinder::FileFinder(std::string label): QWidget(nullptr) {
    
    browseButton = new QPushButton("Browse");
    QObject::connect(browseButton, &QPushButton::clicked, this, &FileFinder::browse);
    
    fileBox = new FileCombobox();
    fileBox->setEditable(true);
    fileBox->setFrame(true);
    QObject::connect(fileBox, &FileCombobox::enterPressed, this, &FileFinder::checkEmpty);
    
    auto *layout = new QGridLayout();
    layout->addWidget(new QLabel(QString::fromStdString(label + ":")), 0, 0);
    layout->addWidget(fileBox, 0, 1, 1, 5);
    layout->addWidget(browseButton, 0, 6);
    setLayout(layout);
}

QString FileFinder::currentText() {
    return fileBox->currentText();
}

void FileFinder::browse() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open Video File", QDir::homePath());
    if (!fileName.isEmpty()) {
        if (fileBox->findText(fileName) == -1)
            fileBox->addItem(fileName);
        fileBox->setCurrentIndex(fileBox->findText(fileName));
        emit contentChanged();
    }
}

void FileFinder::checkEmpty() {
    if(fileBox->currentText().isEmpty())
        return;
    emit contentChanged();
}
