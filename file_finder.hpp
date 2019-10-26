#ifndef FILE_FINDER_HPP
#define FILE_FINDER_HPP

#include <string>
#include <QLabel>
#include <QLayout>
#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QFileDialog>

#include "file_combobox.hpp"

class FileFinder: public QWidget {
    Q_OBJECT
public:
    
    // Default constructor
    FileFinder(std::string label = "File Location");
    
    // Read Content
    QString currentText();
    
    void setText(QString text);
    
private slots:
    
    // Browse button function
    void browse();
    
    // Check combobox is empty
    void checkEmpty();
    
signals:
    
    // Content in the combobox is changed
    void contentChanged();
    
private:
    
    // Combobox
    FileCombobox *fileBox;
    
    // Browse button
    QPushButton *browseButton;
};

#endif
