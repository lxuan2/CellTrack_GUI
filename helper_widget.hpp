//
//  helper_widget_intro.hpp
//  CellTrack
//
//  Created by Xuan Li on 10/25/19.
//

#ifndef helper_widget_intro_hpp
#define helper_widget_intro_hpp

#include <QDialog>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QApplication>

class HelperWidget: public QDialog {
    Q_OBJECT
public:
    
    // Default Constructor
    HelperWidget(QString name);
    
private:
    
    QGroupBox *group;
    
    QPushButton *done;
    
    void createIntro();
    
    void createPyGeneral();
    
    void createPyHidden();
    
    void createMaGeneral();
    
    void createLog();
    
    void createError();
};

#endif /* helper_widget_intro_hpp */
