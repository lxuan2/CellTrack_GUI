#include <QApplication>

#include "scene_delegate.hpp"

int main(int argc, char *argv[])
{
    // Application creation
	QApplication app(argc, argv);
    
    // Delegate sence to view controller
    SceneDelegate scene(app.applicationDirPath());
    
    // Start the application
    return app.exec();
}
