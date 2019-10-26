#include "process_view.hpp"
#include <QApplication>
ProcessView::ProcessView(QWidget *parent): QDialog(parent) {
    setWindowModality(Qt::WindowModal);
    radar = new Radar();
    
    cancel = new QPushButton("cancel");
    QObject::connect(cancel, &QPushButton::clicked, this, &ProcessView::cancelClicked);
    
    QLabel *description = new QLabel("Program is running, please wait ......");
    description->setAlignment(Qt::AlignCenter);
    
    timeLabel = new QLabel();
    timeLabel->setAlignment(Qt::AlignCenter);
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &ProcessView::updateTime);
    
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(radar);
    layout->addWidget(description);
    layout->addWidget(timeLabel);
    layout->addWidget(cancel);
    setLayout(layout);
    
    // set white background
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
    
    setMinimumSize(50, 50);
}

void ProcessView::start() {
    // Enable ask flag
    closeAskFlag = true;
    
    // Reset the timer
    time.setHMS(0,0,0);
    timeLabel->setText(time.toString());
    
    // Start timers
    radar->start();
    timer->start(1000);
    
    // Show this view
    show();
}

void ProcessView::stop() {
    
    // Stop timers
    radar->stop();
    timer->stop();
    
    // Close this view
    closeAskFlag = false;
    close();
}

QString ProcessView::timeCost() {
    return timeLabel->text();
}

void ProcessView::cancelClicked() {
    close();
}

void ProcessView::closeEvent(QCloseEvent *event) {
    if (!closeAskFlag){
        event->accept();
        return;
    }
        
    QMessageBox msgBox;
    msgBox.setText("Are you sure to cancel this process?");
    msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::NoButton);
    msgBox.setIcon(QMessageBox::Warning);
    if (msgBox.exec() == QMessageBox::Yes){
        emit stopProcess();
        radar->stop();
        timer->stop();
        event->accept();
    }
    else
        event->ignore();
}

void ProcessView::updateTime() {
    time = time.addSecs(1);
    timeLabel->setText(time.toString());
}
