//
//  radar.hpp
//  CellTrack
//
//  Created by Xuan Li on 10/14/19.
//

#ifndef radar_hpp
#define radar_hpp

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QBasicTimer>
#include <QCoreApplication>

class Radar: public QWidget {
    Q_OBJECT
public:
    
    // Default Constructor
    Radar();
    
    void start();
    
    void stop();
    
protected:
    
    void timerEvent(QTimerEvent *e);
    
private:
    
    QLabel *radarLabel;
    
    QLabel *sweepLabel;
    
    QPixmap *sweepMap;
    
    QBasicTimer timer;
    
    double degree;
};
#endif /* radar_hpp */
