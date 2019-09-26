#ifndef SCENE_DELEGATE_HPP
#define SCENE_DELEGATE_HPP

#include "matlab_widget.hpp"
#include "intro_widget.hpp"

class SceneDelegate: public QObject {
    Q_OBJECT
public:
    
    // Default Constructor
    SceneDelegate();
    
public slots:
    
    void createView(int id);
    
    void pushFromPViewToCView(QString str);
    
private:
    
    // Main content view
    MatlabWidget *conView;
    
    // Setting view for locating C# application
    IntroWidget *preView;
};

#endif
