#include "matlab_widget.hpp"

MatlabWidget::MatlabWidget(QWidget *parent):QDialog(parent){
    
    // Initialize tab views
    log = new LogView();
    
    general = new GeneralView(log);
    
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
    QWidget::closeEvent(event);
}
