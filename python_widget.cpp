#include "python_widget.hpp"

PythonWidget::PythonWidget(QWidget *parent):QWidget(parent), data(){
    
    // Initialize tab views
    log = new LogView();
    proView = nullptr;
    
    if (!data.loadJson())
        log->write("Error: fail to load user data from json file.");
    
    general = new GeneralView("python", &data, log);
    hiddenVar = new HiddenVarView(&data, log);
    
    core = new Core(this, general, hiddenVar, log);
    QObject::connect(general, &GeneralView::run, core, &Core::runPython);
    
    switchButton = new QPushButton("Switch to Matlab Version");
    QObject::connect(switchButton, &QPushButton::clicked, this, &PythonWidget::closeWindow);
    
    infoButton = new QToolButton();
    infoButton->setIcon(style()->standardIcon(QStyle::SP_FileDialogInfoView));
    infoButton->setStyleSheet("border-radius: 13px");
    QObject::connect(infoButton, &QPushButton::clicked, this, &PythonWidget::infoClicked);
    
    tabView = new QTabWidget();
    tabView->addTab(general, "General");
    tabView->addTab(hiddenVar, "Hidden Parameters");
    tabView->addTab(log, "Log History");
    
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(tabView, 0, 0, 5, 5);
    layout->addWidget(infoButton, 5, 3, Qt::AlignRight);
    layout->addWidget(switchButton, 5, 4, Qt::AlignRight);
    setLayout(layout);
    setWindowTitle("CellTrack_GUI -- Python");
    resize(800, 650);
}

void PythonWidget::closeEvent(QCloseEvent *event) {
    data.setPysource(general->getVideoPath());
    data.setPyprogram(general->getAppPath());
    if(!data.saveJson())
        log->write("Error: Fail to save data into the json file.");
    QWidget::closeEvent(event);
}

void PythonWidget::closeWindow() {
    close();
    createView(1);
}

void PythonWidget::infoClicked() {
    QDialog *dialog;
    switch (tabView->currentIndex()) {
        case 0:
            dialog = new HelperWidget("py_general");
            break;
        case 1:
            dialog = new HelperWidget("py_hidden");
            break;
        case 2:
            dialog = new HelperWidget("log");
            break;
        default:
            dialog = new HelperWidget("");
            break;
    }
    dialog->exec();
}
