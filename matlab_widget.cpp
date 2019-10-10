#include "matlab_widget.hpp"

MatlabWidget::MatlabWidget(QWidget *parent):QDialog(parent), data(){
    
    // Initialize tab views
    log = new LogView();
    
    if (!data.loadJson())
        log->write("Error: fail to load user data from json file.");
    
    general = new GeneralView(log);
    hiddenVar = new HiddenVarView(&data, log);
    
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
    if(!data.saveJson())
        log->write("Error: Fail to save data into the json file.");
    QWidget::closeEvent(event);
}
