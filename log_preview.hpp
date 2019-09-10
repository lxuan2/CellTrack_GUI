#ifndef LOG_PREVIEW_HPP
#define LOG_PREVIEW_HPP

#include <QFile>
#include <QString>
#include <QDialog>
#include <QLayout>
#include <QClipboard>
#include <QTextStream>
#include <QPushButton>
#include <QApplication>
#include <QPlainTextEdit>
#include <QFileDialog>
#include <QProcess>

class LogPreview: public QDialog {
    Q_OBJECT
public:
    
    // Default Constructor
    LogPreview(QString logPath);
    
private slots:
    
    void copyAll();
    
    void saveAs();
    
    void openInFolder();
    
private:
    
    QPlainTextEdit *content;
    
    QString logPath;
    
    QPushButton *doneButton;
    QPushButton *copyAllButton;
    QPushButton *openButton;
    QPushButton *saveButton;
};

void showFileInFolder(const QString &path);

#endif
