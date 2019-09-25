#include "scene_delegate.hpp"

SceneDelegate::SceneDelegate(QString appDirPath) {
    
    // Set application directory path
    applicationDirPath = appDirPath;
    
    preView = new IntroWidget();
    
    // Authorization to create a view
    
    QObject::connect(preView, &IntroWidget::createView, this, &SceneDelegate::createView);
    
    // View communication
    QObject::connect(preView, &IntroWidget::setExeLoc, this, &SceneDelegate::pushFromPViewToCView);
    
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
            conView = new MatlabWidget(nullptr, applicationDirPath);
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
