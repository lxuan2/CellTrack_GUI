#ifndef LOG_WIDGET_HPP
#define LOG_WIDGET_HPP

#include <QTextStream>
#include <QString>
#include <QFile>
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
    
private:
    
    QFile file;
    
    QTextStream stream;
};

#endif
