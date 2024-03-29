#include "file_finder.hpp"

FileFinder::FileFinder(std::string label): QWidget(nullptr) {
    
    browseButton = new QPushButton("Browse");
    QObject::connect(browseButton, &QPushButton::clicked, this, &FileFinder::browse);
    
    fileBox = new FileCombobox();
    fileBox->setEditable(true);
    fileBox->setFrame(true);
    //fileBox->setSizeAdjustPolicy(FileCombobox::AdjustToContents);
    fileBox->setMinimumWidth(150);
    QObject::connect(fileBox, &FileCombobox::enterPressed, this, &FileFinder::checkEmpty);
    
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(new QLabel(QString::fromStdString(label + ":")));
    layout->addWidget(fileBox, Qt::AlignLeft);
    layout->addWidget(browseButton);
    setLayout(layout);
}

QString FileFinder::currentText() {
    return fileBox->currentText();
}

void FileFinder::browse() {
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open File", QDir::homePath());
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

void FileFinder::setText(QString text) {
    fileBox->setEditText(text);
}
