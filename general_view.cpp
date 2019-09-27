#include "general_view.hpp"
GeneralView::GeneralView(LogView *log){
    
    // Widget initialize
    videoView = new VideoView();
    
    // Groupbox initialize
    runBox     = new RunGroupBox(log);
    videoBox   = new VideoGroupBox(videoView, runBox, log);
    controlBox = new ControlPannel(log);
    
    // Compuation Core initialize
    core = new Core(videoBox, controlBox, log);
    
    QObject::connect(runBox, &RunGroupBox::compute, core, &Core::compute);
    QObject::connect(runBox, &RunGroupBox::compute, videoBox, &VideoGroupBox::play);
    QObject::connect(core, &Core::loadResualt, videoBox, &VideoGroupBox::setResultPath);
    QObject::connect(core, &Core::loadResualt, runBox, &RunGroupBox::updateRes);
    
    // Widget layout initialize
    auto layout = new QGridLayout();
    layout->addWidget(videoView, 0, 0);
    layout->addWidget(videoBox, 1, 0);
    layout->addWidget(controlBox, 0, 1);
    layout->addWidget(runBox, 1, 1);
    setLayout(layout);
}

void GeneralView::setExeLoc(QString exeLoc) {
    core->setExe(exeLoc);
}
