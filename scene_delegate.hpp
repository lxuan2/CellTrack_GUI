#ifndef SCENE_DELEGATE_HPP
#define SCENE_DELEGATE_HPP

#include "content_view.hpp"
#include "pre_setting_view.hpp"

class SceneDelegate: public QObject {
    Q_OBJECT
public:
    
    // Default Constructor
    SceneDelegate(QString appDirPath);
    
public slots:
    
    void createView(int id);
    
    void pushFromPViewToCView(QString str);
    
private:
    
    QString applicationDirPath;
    
    // Main content view
    ContentView *conView;
    
    // Setting view for locating C# application
    PreSettingView *preView;
};

#endif