#ifndef process_view_hpp
#define process_view_hpp

#include <QDialog>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QBasicTimer>
#include <QSpacerItem>
#include <QSizePolicy>
#include <QMessageBox>

class ProcessView: public QDialog{
    Q_OBJECT
public:
    
    // Default constructor
    ProcessView(QDialog *parent = nullptr);
    
signals:
    
    void stopProcess();
    
public slots:
    
    void cancelClicked();
    
protected:
    
    void timerEvent(QTimerEvent *e);
    
private:
    
    QLabel *radarLabel;
    
    QLabel *sweepLabel;
    
    QPixmap *sweepMap;
    
    QPushButton *cancel;
    
    QBasicTimer timer;
    
    double degree;
};

#endif
