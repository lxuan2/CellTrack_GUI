#include "process_view.hpp"

ProcessView::ProcessView(QWidget *parent): QDialog(parent) {
    setWindowModality(Qt::WindowModal);
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
    
    cancel = new QPushButton("cancel");
    QObject::connect(cancel, &QPushButton::clicked, this, &ProcessView::cancelClicked);
    
    QLabel *description = new QLabel("Program is running, please wait ......");
    description->setAlignment(Qt::AlignCenter);
    
    QGridLayout *layout = new QGridLayout();
    layout->addItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding), 0, 0);
    layout->addWidget(radarLabel, 1, 0);
    layout->addWidget(sweepLabel, 1, 0);
    layout->addItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding), 2, 0);
    layout->addWidget(description, 3, 0);
    layout->addWidget(cancel, 4, 0);
    setLayout(layout);
    
    // set black background
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
    
    degree = 0.0;
    timer.start(17, this);
    setMinimumSize(50, 50);
}

void ProcessView::cancelClicked() {
    QMessageBox msgBox;
    msgBox.setText("Are you sure to cancel this process?");
    msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::NoButton);
    msgBox.setIcon(QMessageBox::Warning);
    if (msgBox.exec() == QMessageBox::Yes){
        emit stopProcess();
        close();
    }
}

void ProcessView::timerEvent(QTimerEvent *e)
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
