#include "matlab_widget.hpp"

MatlabWidget::MatlabWidget(QWidget *parent):QWidget(parent){
    
    // Initialize tab views
    proView = nullptr;
    log = new LogView();
    general = new GeneralView("matlab", nullptr, log);
    
    core = new Core(this, general, nullptr, log);
    QObject::connect(general, &GeneralView::run, core, &Core::runMatlab);
    
    tabView = new QTabWidget();
    tabView->addTab(general, "General");
    tabView->addTab(log, "Log History");
    
    switchButton = new QPushButton("Switch to Python Version");
    QObject::connect(switchButton, &QPushButton::clicked, this, &MatlabWidget::closeWindow);
    
    infoButton = new QToolButton();
    infoButton->setIcon(style()->standardIcon(QStyle::SP_FileDialogInfoView));
    infoButton->setStyleSheet("border-radius: 13px");
    QObject::connect(infoButton, &QPushButton::clicked, this, &MatlabWidget::infoClicked);
    
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(tabView, 0, 0, 5, 5);
    layout->addWidget(infoButton, 5, 3, Qt::AlignRight);
    layout->addWidget(switchButton, 5, 4, Qt::AlignRight);
    setLayout(layout);
    setWindowTitle("CellTrack_GUI -- Matlab");
    resize(800, 650);
}

void MatlabWidget::closeEvent(QCloseEvent *event) {
    QWidget::closeEvent(event);
}

void MatlabWidget::closeWindow() {
    createView(2);
    close();
}

void MatlabWidget::infoClicked() {
    QDialog *dialog;
    switch (tabView->currentIndex()) {
        case 0:
            dialog = new HelperWidget("ma_general");
            break;
        case 1:
            dialog = new HelperWidget("log");
            break;
        default:
            dialog = new HelperWidget("");
            break;
    }
    dialog->exec();
}
