#ifndef CELL_APP_HPP
#define CELL_APP_HPP

#include <iostream>
#include <QDebug>
#include <QLabel>
#include <QWidget>
#include <QLayout>
#include <QSpinBox>
#include <QGroupBox>
#include <QComboBox>
#include <QPushButton>
#include <QFileDialog>

#include "display_widget.hpp"

class CellApp: public QWidget{
    Q_OBJECT
public:
    
    // Default constructor
    CellApp();
    
private:
    
    // Video widget pointer
    DisplayWidget *videoWidget;
    
    // Buttons
    QPushButton *browseButton;
    QPushButton *loadOrgButton;
    QPushButton *loadResButton;
    QPushButton *analyzeButton;
    
    // Line-Edit
    QComboBox *fileCombobox;
    QSpinBox *maxCellSize;
    QSpinBox *minCellSize;
    
    // Group boxes
    QGroupBox *videoBox;
    QGroupBox *controlBox;

    // Functions
    void browse();
    void loadOrgVideo(int index);
};

#endif
