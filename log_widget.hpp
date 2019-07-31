#ifndef LOG_WIDGET_HPP
#define LOG_WIDGET_HPP

#include <QString>
#include <QPlainTextEdit>

class LogWidget: public QPlainTextEdit {
    Q_OBJECT
public:
    
    // Default Constructor
    LogWidget();
    
    // Write the content to display
    void write(QString content);
    
    // Clear all the content
    void clear();
};

#endif
