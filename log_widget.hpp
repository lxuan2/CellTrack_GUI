#ifndef LOG_WIDGET_HPP
#define LOG_WIDGET_HPP

#include <QPlainTextEdit>
#include <QString>

class LogWidget: public QPlainTextEdit {
    Q_OBJECT
public:
    
    // Default Constructor
    LogWidget();
    
private:
    
    void write(QString content, bool warn);
    
    void clear();
    
};

#endif
