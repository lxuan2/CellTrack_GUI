#include <QApplication>
#include <QWidget>

#include "cell_app.hpp"
#include "setting_app.hpp"

int main(int argc, char *argv[])
{
    // Application creation
	QApplication app(argc, argv);
    
    // Widget initialization
    SettingApp popup;
    CellApp widget;
    
    // Connection: setting app -> cell app
    QObject::connect(&popup, &SettingApp::toMain, &widget, &CellApp::showWindow);
    
    // Pop up widget show
    popup.show();
    
    // Start the application
    return app.exec();
}
