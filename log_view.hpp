#ifndef LOG_VIEW_HPP
#define LOG_VIEW_HPP

#include <QTextStream>
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QPlainTextEdit>
#include <QLayout>
#include <QPushButton>

#include "log_preview.hpp"

class LogView: public QWidget{
    Q_OBJECT
public:
    
    // Default Constructor
    LogView();
    
    // Write the content to display
    void write(QString content);
    
    // Clear all the content
    void clear();
    
private slots:
    
    // View Log button clicked recieving block
    void logButtonClicked();
    
private:
    
    QFile file;
    
    QTextStream stream;
    
    QPushButton *logButton;
    
    QPlainTextEdit *textView;
};

#endif
