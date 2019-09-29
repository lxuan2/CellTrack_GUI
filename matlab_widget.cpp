#include "matlab_widget.hpp"

MatlabWidget::MatlabWidget(){
    
    // Initialize tab views
    log = new LogView();
    general = new GeneralView(log);
    hiddenVar = new HiddenVarView(log);
    
    QTabWidget *tabView = new QTabWidget();
    tabView->addTab(general, "General");
    tabView->addTab(hiddenVar, "Hidden Parameters");
    tabView->addTab(log, "Log History");
    
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(tabView);
    setLayout(layout);
    setWindowTitle("CellTrack_GUI");
    resize(800, 600);
}

void MatlabWidget::setExeLoc(QString exeLoc) {
	
}

void MatlabWidget::closeEvent(QCloseEvent *event) {
    hiddenVar->saveToFile();
    QWidget::closeEvent(event);
}
