#ifndef FILE_FINDER_HPP
#define FILE_FINDER_HPP

#include <QPushButton>
#include <QFileDialog>
#include <QLabel>
#include <QLayout>
#include <QString>
#include <QWidget>
#include <string>

#include "file_combobox.hpp"

class FileFinder: public QWidget {
    Q_OBJECT
public:
    
    // Default constructor
    FileFinder(std::string label = "File Location");
    
    // Read Content
    QString currentText();
    
private slots:
    
    void browse();
    
signals:
    
    void contentChanged();
    
private:
    
    // Combobox
    FileCombobox *fileBox;
    
    // Browse button
    QPushButton *browseButton;
};

#endif
