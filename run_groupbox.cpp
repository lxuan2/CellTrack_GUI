#include "run_groupbox.hpp"
RunGroupBox::RunGroupBox(LogView *l) {
    log = l;
    setTitle("Run");
    
    finder = new FileFinder("C#");
    QObject::connect(finder, &FileFinder::contentChanged, this, &RunGroupBox::loadCsharp);
    
    analyzeButton = new QPushButton("Start Analysis");
    QObject::connect(analyzeButton, &QPushButton::clicked, this, &RunGroupBox::analyzeButtonClicked);
    
    QLabel *videoLabel = new QLabel("Source File");
    QLabel *cSharpLabel = new QLabel("C# Application");
    QLabel *resultLabel = new QLabel("Result");
    
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(finder, 0, 0, 1, 5);
    layout->addWidget(videoLabel, 1, 2);
    layout->addWidget(cSharpLabel, 2, 2);
    layout->addWidget(resultLabel, 3, 2);
    layout->addWidget( analyzeButton, 4, 3, 1, 2);
    setLayout(layout);
}

void RunGroupBox::loadCsharp() {
    
}

void RunGroupBox::analyzeButtonClicked() {
    emit compute(false);
}
