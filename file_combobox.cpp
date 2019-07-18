#include "file_combobox.hpp"

FileCombobox::FileCombobox(): QComboBox() {}

void FileCombobox::keyPressEvent(QKeyEvent *e) {
    
    if(e->key() == Qt::Key_Return){
        QComboBox::keyPressEvent(e);
        emit enterPressed();
        return;
    }
    return QComboBox::keyPressEvent(e);
}
