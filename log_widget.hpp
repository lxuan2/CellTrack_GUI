#ifndef LOG_WIDGET_HPP
#define LOG_WIDGET_HPP

#include <QTextStream>
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QPlainTextEdit>

class LogWidget: public QPlainTextEdit {
    Q_OBJECT
public:
    
    // Default Constructor
    LogWidget(QString appDirPath);
    
    // Write the content to display
    void write(QString content);
    
    // Clear all the content
    void clear();
    
    // Give Log file path
    
    QString logPath();
    
private:
    
    QFile file;
    
    QTextStream stream;
};

#endif
