#include "matlab_widget.hpp"

MatlabWidget::MatlabWidget(QWidget *parent):QDialog(parent){
    
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
    
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(tabView);
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
        proView->close();
        proView = nullptr;
        return;
    }
    if (value) {
        if (proView != nullptr)
            return;
        proView = new ProcessView(this);
        QObject::connect(proView, &ProcessView::stopProcess, core, &Core::stopProcess);
        proView->exec();
    }
}
