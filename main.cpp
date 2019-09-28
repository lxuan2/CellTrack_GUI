#include <QApplication>

#include "scene_delegate.hpp"

int main(int argc, char *argv[])
{
    // Application creation
	QApplication app(argc, argv);
    
    // Use high resolution pixmaps
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    
    // Delegate sence to view controller
    SceneDelegate scene;
    
    // Start the application
    return app.exec();
}
