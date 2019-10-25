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
#include <QApplication>

class HelperWidget_Intro: public QDialog {
    Q_OBJECT
public:
    
    // Default Constructor
    HelperWidget_Intro();
};

class HelperWidget_Log: public QDialog {
    Q_OBJECT
public:
    
    // Default Constructor
    HelperWidget_Log();
};

class HelperWidget_Hidden: public QDialog {
    Q_OBJECT
public:
    
    // Default Constructor
    HelperWidget_Hidden();
};

class HelperWidget_General_Py: public QDialog {
    Q_OBJECT
public:
    
    // Default Constructor
    HelperWidget_General_Py();
};

#endif /* helper_widget_intro_hpp */
