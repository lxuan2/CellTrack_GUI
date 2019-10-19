#include "matlab_widget.hpp"

MatlabWidget::MatlabWidget(QWidget *parent):QWidget(parent){
    
    // Initialize tab views
    proView = nullptr;
    log = new LogView();
    general = new GeneralView(log);
    
    core = new Core(general, nullptr, log);
    QObject::connect(general, &GeneralView::run, core, &Core::runMatlab);
    QObject::connect(core, &Core::showProcessView, this, &MatlabWidget::showProcessView);
    
    QTabWidget *tabView = new QTabWidget();
    tabView->addTab(general, "General");
    tabView->addTab(log, "Log History");
    
    switchButton = new QPushButton("Switch to Python Version");
    QObject::connect(switchButton, &QPushButton::clicked, this, &MatlabWidget::closeWindow);
    
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(tabView, 0, 0, 5, 5);
    layout->addWidget(switchButton, 5, 4, Qt::AlignRight);
    setLayout(layout);
    setWindowTitle("CellTrack_GUI -- Matlab");
    resize(800, 600);
}

void MatlabWidget::closeEvent(QCloseEvent *event) {
    core->stopProcess();
    QWidget::closeEvent(event);
}

void MatlabWidget::showProcessView(bool value) {
    if (!value && proView != nullptr) {
        proView->setCloseAskFlag(false);
        proView->close();
        proView = nullptr;
        return;
    }
    if (value) {
        proView = new ProcessView(this);
        QObject::connect(proView, &ProcessView::stopProcess, core, &Core::stopProcess);
        proView->exec();
    }
}

void MatlabWidget::closeWindow() {
    createView(2);
    close();
}
