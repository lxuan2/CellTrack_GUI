#include "matlab_widget.hpp"

MatlabWidget::MatlabWidget(){
    
    // Initialize tab views
    log = new LogView();
    general = new GeneralView(log);
    hiddenVar = new HiddenVarView();
    
    QTabWidget *tabView = new QTabWidget();
    tabView->addTab(general, "General");
    tabView->addTab(hiddenVar, "Hidden Variables");
    tabView->addTab(log, "Log");
    
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(tabView);
    setLayout(layout);
    setWindowTitle("CellTrack_GUI");
    resize(800, 600);
}

void MatlabWidget::setExeLoc(QString exeLoc) {
	
}
