#include <QApplication>
#include <QWidget>

#include "cell_app.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    CellApp widget;
    
    widget.show();
    
    return app.exec();
}
