#include "scene_delegate.hpp"

SceneDelegate::SceneDelegate() {
    
    conView = new MatlabWidget();
    
    // First scene shows up
    conView->show();
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
            conView = new MatlabWidget();
            QObject::connect(conView, &MatlabWidget::createView, this, &SceneDelegate::createView);
            conView->show();
            break;
            
        case 1:
            if (preView != nullptr) {
                preView->show();
                preView->activateWindow();
                preView->raise();
                break;
            }
            preView = new IntroWidget();
            QObject::connect(preView, &IntroWidget::setExeLoc, conView, &MatlabWidget::setExeLoc);
            preView->show();
            break;
            
        default:
            break;
    }
}

void SceneDelegate::pushFromPViewToCView(QString str) {
    conView->setExeLoc(str);
}
