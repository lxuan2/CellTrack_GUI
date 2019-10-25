#ifndef process_view_hpp
#define process_view_hpp

#include <QDialog>
#include <QLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QSizePolicy>
#include <QMessageBox>
#include <QCloseEvent>
#include <QTime>
#include <Qtimer>

#include "radar.hpp"

class ProcessView: public QDialog{
    Q_OBJECT
public:
    
    // Default constructor
    ProcessView(QWidget *parent);
    
    void start();
    
    void stop();
    
    QString timeCost();
    
signals:
    
    void stopProcess();
    
private slots:
    
    void updateTime();
    void cancelClicked();
    
private:
    
    Radar *radar;
    
    QPushButton *cancel;
    
    QTime time;
    
    QTimer *timer;
    
    QLabel *timeLabel;
    
    bool closeAskFlag;
    
    void closeEvent(QCloseEvent *event);
};

#endif
