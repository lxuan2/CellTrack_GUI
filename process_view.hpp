#ifndef process_view_hpp
#define process_view_hpp

#include <QDialog>
#include <QLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QSizePolicy>
#include <QMessageBox>
#include <QCloseEvent>

#include "radar.hpp"

class ProcessView: public QDialog{
    Q_OBJECT
public:
    
    // Default constructor
    ProcessView(QWidget *parent = nullptr);
    
signals:
    
    void stopProcess();
    
public slots:
    
    void cancelClicked();
    
private:
    
    Radar *radar;
    
    QPushButton *cancel;
    
    void closeEvent(QCloseEvent *event);
};

#endif
