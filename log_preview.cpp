#include "log_preview.hpp"

LogPreview::LogPreview(QString logPath){
    this->logPath = logPath;
    QFile file(logPath);
    QString text;
    if (!file.exists()) {
        text = "Warning: There is no log file in current directory.";
    } else {
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            text = stream.readAll();
        } else
            text = "Warning: Current log file cannot be opened.";
    }
    
    content = new QPlainTextEdit();
    content->setPlainText(text);
    content->setReadOnly(true);
    // Move cursor to the end
    auto cursor = content->textCursor();
    cursor.movePosition(QTextCursor::End);
    content->setTextCursor(cursor);
    
    copyAllButton = new QPushButton("Copy All");
    QObject::connect(copyAllButton, &QPushButton::clicked, this, &LogPreview::copyAll);
    
    saveButton = new QPushButton("Save as");
    QObject::connect(saveButton, &QPushButton::clicked, this, &LogPreview::saveAs);
    
    openButton = new QPushButton("Open in Folder");
    QObject::connect(openButton, &QPushButton::clicked, this, &LogPreview::openInFolder);
    
    doneButton = new QPushButton("Done");
    QObject::connect(doneButton, &QPushButton::clicked, this, &LogPreview::done);
    doneButton->setDefault(true);
    
    auto layout = new QGridLayout();
    layout->addWidget(content, 0, 0, 4, 6);
    layout->addWidget(copyAllButton, 5, 0);
    layout->addWidget(saveButton, 5, 1);
    layout->addWidget(openButton, 5, 2);
    layout->addWidget(doneButton, 5, 5);
    setLayout(layout);
    setMinimumSize(700, 400);
}

void LogPreview::copyAll() {
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(content->toPlainText());
}

void LogPreview::saveAs() {
    QFileDialog dialog(this);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    if (dialog.exec() == QDialog::Accepted){
        QFile file(dialog.selectedFiles().first());
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream stream(&file);
        stream << content->toPlainText();
    }
}

void LogPreview::openInFolder() {
    showFileInFolder(logPath);
}

void showFileInFolder(const QString &path){
    #if defined(_WIN32) || defined(_WIN64)    //Code for Windows
        QProcess::startDetached("explorer.exe", {"/select,", QDir::toNativeSeparators(path)});
    #elif defined(__APPLE__)    //Code for Mac
        QProcess::execute("/usr/bin/osascript", {"-e", "tell application \"Finder\" to reveal POSIX file \"" + path + "\""});
        QProcess::execute("/usr/bin/osascript", {"-e", "tell application \"Finder\" to activate"});
    #endif
}
