#include "log_widget.hpp"

LogWidget::LogWidget(QString appDirPath):QPlainTextEdit(), file((appDirPath + "/Log.txt")), stream(&file) {
    file.open(QIODevice::Append | QIODevice::Text);
    auto time = QDateTime::currentDateTime().toString();
    appendPlainText(time + "\nStart Logging...");
    stream << time << endl;
    setReadOnly(true);
}

void LogWidget::write(QString content) {
    // Log file existence check.
    if(!file.exists()){
        file.close();
        file.open(QIODevice::Append | QIODevice::Text);
        stream << QDateTime::currentDateTime().toString() << endl;
        stream << "Warning: lose log file when program is running. New log file is now created." << endl;
    }
    
    // Write to widget and file
    appendPlainText("  " + content);
    stream << "  " << content << endl;
}

void LogWidget::clear() {
    QPlainTextEdit::clear();
}

QString LogWidget::logPath() {
    QFileInfo info(file);
    return info.absoluteFilePath();
}
