#include "process_view.hpp"

ProcessView::ProcessView(QWidget *parent): QDialog(parent) {
    setWindowModality(Qt::WindowModal);
    radar = new Radar();
    
    cancel = new QPushButton("cancel");
    QObject::connect(cancel, &QPushButton::clicked, this, &ProcessView::cancelClicked);
    
    QLabel *description = new QLabel("Program is running, please wait ......");
    description->setAlignment(Qt::AlignCenter);
    
    QGridLayout *layout = new QGridLayout();
    layout->addItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding), 0, 0);
    layout->addWidget(radar, 1, 0);
    layout->addItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding), 2, 0);
    layout->addWidget(description, 3, 0);
    layout->addWidget(cancel, 4, 0);
    setLayout(layout);
    
    // set black background
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
    
    radar->start();
    setMinimumSize(50, 50);
}

void ProcessView::cancelClicked() {
    close();
}

void ProcessView::closeEvent(QCloseEvent *event) {
    QMessageBox msgBox;
    msgBox.setText("Are you sure to cancel this process?");
    msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::NoButton);
    msgBox.setIcon(QMessageBox::Warning);
    if (msgBox.exec() == QMessageBox::Yes){
        emit stopProcess();
        radar->stop();
        event->accept();
    }
    else
        event->ignore();
}
