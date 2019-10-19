#include "python_widget.hpp"

PythonWidget::PythonWidget(QWidget *parent):QWidget(parent), data(){
    
    // Initialize tab views
    log = new LogView();
    
    if (!data.loadJson())
        log->write("Error: fail to load user data from json file.");
    
    general = new GeneralView(log);
    hiddenVar = new HiddenVarView(&data, log);
    
    core = new Core(general, nullptr, log);
    QObject::connect(general, &GeneralView::run, core, &Core::runPython);
    QObject::connect(core, &Core::showProcessView, this, &PythonWidget::showProcessView);
    
    switchButton = new QPushButton("Switch to Matlab Version");
    QObject::connect(switchButton, &QPushButton::clicked, this, &PythonWidget::closeWindow);
    
    QTabWidget *tabView = new QTabWidget();
    tabView->addTab(general, "General");
    tabView->addTab(hiddenVar, "Hidden Parameters");
    tabView->addTab(log, "Log History");
    
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(tabView, 0, 0, 5, 5);
    layout->addWidget(switchButton, 5, 4, Qt::AlignRight);
    setLayout(layout);
    setWindowTitle("CellTrack_GUI -- Python");
    resize(800, 600);
}

void PythonWidget::closeEvent(QCloseEvent *event) {
    if(!data.saveJson())
        log->write("Error: Fail to save data into the json file.");
    core->stopProcess();
    QWidget::closeEvent(event);
}

void PythonWidget::showProcessView(bool value) {
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

void PythonWidget::closeWindow() {
    createView(1);
    close();
}
