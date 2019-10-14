//
//  radar.cpp
//  CellTrack
//
//  Created by Xuan Li on 10/14/19.
//

#include "radar.hpp"

Radar::Radar() {
    QPixmap radarMap(QCoreApplication::applicationDirPath() + "/RadarBackground.png");
    radarMap.setDevicePixelRatio(4);
    radarLabel= new QLabel();
    radarLabel->setPixmap(radarMap);
    radarLabel->setAlignment(Qt::AlignCenter);
    
    sweepMap = new QPixmap(QCoreApplication::applicationDirPath() + "/RadarSweep.png");
    sweepMap->setDevicePixelRatio(4);
    sweepLabel= new QLabel();
    sweepLabel->setPixmap(*sweepMap);
    sweepLabel->setAlignment(Qt::AlignCenter);
    
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(radarLabel, 0, 0);
    layout->addWidget(sweepLabel, 0, 0);
    setLayout(layout);
    
    setMinimumSize(20, 20);
    degree = 0.0;
    
}

void Radar::start() {
    if (!timer.isActive())
        timer.start(17, this);
    else {
        timer.stop();
        timer.start(17, this);
    }
}

void Radar::stop() {
    if (timer.isActive())
        timer.stop();
}

void Radar::timerEvent(QTimerEvent *e)
{
    if (degree >= 360)
        degree = 0.0;
    else {
        degree+=1.0;
        QMatrix m;
        m.rotate(degree);
        auto newMap = sweepMap->transformed(m);
        auto newSize = newMap.size();
        auto size = sweepMap->size();
        int h = (newSize.height() - size.height()) / 2;
        int w = (newSize.width() - size.width()) / 2;
        sweepLabel->setPixmap(newMap.copy(w, h, size.width(), size.height()));
    }
}
