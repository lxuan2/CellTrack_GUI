#ifndef FILE_COMBOBOX_HPP
#define FILE_COMBOBOX_HPP

#include <QComboBox>
#include <QKeyEvent>

class FileCombobox: public QComboBox {
    Q_OBJECT
public:
    
    // Default Constructor
    FileCombobox();
    
signals:
    
    void enterPressed();
    
private:
    
    // Overloaded Function
    void keyPressEvent(QKeyEvent *e);
    
};

#endif
