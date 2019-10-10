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
            if (introView != nullptr) {
                introView->show();
                introView->activateWindow();
                introView->raise();
                break;
            }
            introView = new IntroWidget();
            QObject::connect(introView, &IntroWidget::setExeLoc, conView, &MatlabWidget::setExeLoc);
            introView->show();
            break;
            
        default:
            break;
    }
}

void SceneDelegate::pushFromPViewToCView(QString str) {
    conView->setExeLoc(str);
}
