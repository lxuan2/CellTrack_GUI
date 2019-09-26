#include "log_view.hpp"

LogView::LogView():file((QCoreApplication::applicationDirPath() + "/Log.txt")), stream(&file) {
    
    // Initialize text View and file
    textView = new QPlainTextEdit();
    textView->setReadOnly(true);
    file.open(QIODevice::Append | QIODevice::Text);
    
    logButton = new QPushButton("View All Log");
    QObject::connect(logButton, &QPushButton::clicked, this, &LogView::logButtonClicked);
    
    // Record section time
    auto time = QDateTime::currentDateTime().toString();
    textView->appendPlainText(time + "\nStart Logging...");
    stream << time << endl;
    
    // Layout
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(textView, 0, 0, 10, 10);
    layout->addWidget(logButton, 11, 9);
    setLayout(layout);
}

void LogView::write(QString content) {
    // Log file existence check.
    if(!file.exists()){
        file.close();
        file.open(QIODevice::Append | QIODevice::Text);
        stream << QDateTime::currentDateTime().toString() << endl;
        stream << "Warning: lose log file when program is running. New log file is now created." << endl;
    }
    
    // Write to widget and file
    textView->appendPlainText("  " + content);
    stream << "  " << content << endl;
}

void LogView::clear() {
    textView->clear();
}

void LogView::logButtonClicked() {
    QFileInfo info(file);
    LogPreview msgbox(info.absoluteFilePath());
    msgbox.exec();
}
