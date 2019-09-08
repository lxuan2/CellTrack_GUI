#include "scene_delegate.hpp"

SceneDelegate::SceneDelegate() {
    
    preView = new PreSettingView();
    
    // Authorization to create a view
    
    QObject::connect(preView, &PreSettingView::createView, this, &SceneDelegate::createView);
    
    // View communication
    QObject::connect(preView, &PreSettingView::setExeLoc, this, &SceneDelegate::pushFromPViewToCView);
    
    // First scene shows up
    preView->show();
}

void SceneDelegate::createView(int id) {
    switch (id) {
        case 0:
            if (conView != nullptr) {
                conView->show();
                conView->activateWindow();
                conView->raise();
                break;
            }
            conView = new ContentView();
            QObject::connect(conView, &ContentView::createView, this, &SceneDelegate::createView);
            conView->show();
            break;
            
        case 1:
            if (preView != nullptr) {
                preView->show();
                preView->activateWindow();
                preView->raise();
                break;
            }
            preView = new PreSettingView();
            QObject::connect(preView, &PreSettingView::setExeLoc, conView, &ContentView::setExeLoc);
            preView->show();
            break;
            
        default:
            break;
    }
}

void SceneDelegate::pushFromPViewToCView(QString str) {
    conView->setExeLoc(str);
}
