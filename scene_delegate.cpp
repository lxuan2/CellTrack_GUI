#include "scene_delegate.hpp"

SceneDelegate::SceneDelegate() {
    
    introView = new IntroWidget();
    
    // Authorization to create a view
    QObject::connect(introView, &IntroWidget::createView, this, &SceneDelegate::createView);
    
    // First scene shows up
    introView->show();
}

void SceneDelegate::createView(int id) {
    switch (id) {
        case 0:
            if (introView != nullptr) {
                introView->show();
                introView->activateWindow();
                introView->raise();
                break;
            }
            introView = new IntroWidget();
            introView->show();
            break;
            
        case 1:
            if (M_ContentView != nullptr) {
                M_ContentView->show();
                M_ContentView->activateWindow();
                M_ContentView->raise();
                break;
            }
            M_ContentView = new MatlabWidget();
            QObject::connect(M_ContentView, &MatlabWidget::createView, this, &SceneDelegate::createView);
            M_ContentView->show();
            break;
        
        case 2:
            if (P_ContentView != nullptr) {
                P_ContentView->show();
                P_ContentView->activateWindow();
                P_ContentView->raise();
                break;
            }
            P_ContentView = new PythonWidget();
            QObject::connect(P_ContentView, &PythonWidget::createView, this, &SceneDelegate::createView);
            P_ContentView->show();
            break;
            
        default:
            break;
    }
}
