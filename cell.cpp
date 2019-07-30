#include <QApplication>
#include <QWidget>

#include "cell_app.hpp"
#include "setting_app.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
    
    SettingApp popup;
    
    CellApp widget;
    
    QObject::connect(&popup, &SettingApp::toMain, &widget, &CellApp::showWindow);
    
    popup.show();
     
    return app.exec();
}
