#ifndef SCENE_DELEGATE_HPP
#define SCENE_DELEGATE_HPP

#include "intro_widget.hpp"
#include "matlab_widget.hpp"
#include "python_widget.hpp"

class SceneDelegate: public QObject {
    Q_OBJECT
public:
    
    // Default Constructor
    SceneDelegate();
    
public slots:
    
    void createView(int id);
    
private:
    
    // Setting view for locating C# application
    IntroWidget *introView;
    
    // Main Matlab content view
    MatlabWidget *M_ContentView;
    
    // Main Python content view
    PythonWidget *P_ContentView;
    
};

#endif
