#include "run_groupbox.hpp"
#include <iostream>
RunGroupBox::RunGroupBox(QString app, LogView *l): srcPath("N/A"), appPath("N/A"), resPath("N/A"){
    log = l;
    setTitle("Run");
    
    if (app == "matlab")
        finder = new FileFinder("C#");
    else
        finder = new FileFinder("Script");
    QObject::connect(finder, &FileFinder::contentChanged, this, &RunGroupBox::loadCsharp);
    
    analyzeButton = new QPushButton("Start Analysis");
    QObject::connect(analyzeButton, &QPushButton::clicked, this, &RunGroupBox::analyzeButtonClicked);
    
    QIcon icon = style()->standardIcon(QStyle::SP_DialogApplyButton);
    QIcon icon1 = style()->standardIcon(QStyle::SP_DialogCancelButton);
    applyPixmap = icon.pixmap(QSize(16, 16));
    cancelPixmap = icon1.pixmap(QSize(16, 16));
    
    sourceApply = new QLabel();
    appApply = new QLabel();
    sourceApply->setPixmap(cancelPixmap);
    appApply->setPixmap(cancelPixmap);
    
    QLabel *videoLabel = new QLabel("Source File:");
    QLabel *cSharpLabel;
    if (app == "matlab")
        cSharpLabel = new QLabel("C# Application:");
    else
        cSharpLabel = new QLabel("Python Script:");
    QLabel *resultLabel = new QLabel("Result:");
    
    sourceName = new QLabel(srcPath);
    appName = new QLabel(appPath);
    resultName = new QLabel(resPath);
    
    revealOrgButton = new QToolButton();
    revealOrgButton->setIcon(style()->standardIcon(QStyle::SP_DirIcon));
    revealOrgButton->setDisabled(true);
    QObject::connect(revealOrgButton, &QToolButton::clicked, this, &RunGroupBox::revealOrgClicked);
    
    revealResButton = new QToolButton();
    revealResButton->setIcon(style()->standardIcon(QStyle::SP_DirIcon));
    revealResButton->setDisabled(true);
    QObject::connect(revealResButton, &QToolButton::clicked, this, &RunGroupBox::revealResClicked);
    
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(finder, 0, 0, 1, 4);
    layout->addWidget(sourceApply, 1, 0, Qt::AlignRight);
    layout->addWidget(appApply, 2, 0, Qt::AlignRight);
    layout->addWidget(videoLabel, 1, 1);
    layout->addWidget(cSharpLabel, 2, 1);
    layout->addWidget(resultLabel, 3, 1);
    layout->addWidget(sourceName, 1, 2, 1, 2, Qt::AlignLeft);
    layout->addWidget(appName, 2, 2, 1, 2, Qt::AlignLeft);
    layout->addWidget(resultName, 3, 2, 1, 2, Qt::AlignLeft);
    layout->addWidget(revealOrgButton, 1, 3, Qt::AlignRight);
    layout->addWidget(revealResButton, 3, 3, Qt::AlignRight);
    layout->addWidget(analyzeButton, 4, 3, Qt::AlignLeft);
    setLayout(layout);
}

void RunGroupBox::loadCsharp() {
    if (finder->currentText() == appPath)
        return;
    updateRes("N/A");
    QFileInfo file(finder->currentText());
    if (!file.exists()) {
        appPath = QString::fromStdString("N/A");
        appName->setText(appPath);
        appApply->setPixmap(cancelPixmap);
        return log->write("Error: Cannot load C# application, since it not exist.");
    }
    appPath = finder->currentText();
    appName->setText(file.fileName());
    appApply->setPixmap(applyPixmap);
}

void RunGroupBox::analyzeButtonClicked() {
    emit run();
}

void RunGroupBox::revealOrgClicked() {
    if(sourceName->text() != QString::fromStdString("N/A"))
        showFileInFolder(srcPath);
}

void RunGroupBox::revealResClicked() {
    if(resultName->text() != QString::fromStdString("N/A"))
        showFileInFolder(resPath);
}

void RunGroupBox::updateSrc(QString fp) {
    if (fp == srcPath)
        return;
    updateRes("N/A");
    QFileInfo file(fp);
    if (!file.exists()) {
        srcPath = QString::fromStdString("N/A");
        sourceName->setText(srcPath);
        sourceApply->setPixmap(cancelPixmap);
        revealOrgButton->setDisabled(true);
        return;
    }
    srcPath = fp;
    sourceName->setText(file.fileName());
    sourceApply->setPixmap(applyPixmap);
    revealOrgButton->setDisabled(false);
}

void RunGroupBox::updateRes(QString fp) {
    QFileInfo file(fp);
    if (!file.exists()) {
        resPath = QString::fromStdString("N/A");
        resultName->setText(resPath);
        revealResButton->setDisabled(true);
        return;
    }
    resPath = fp;
    resultName->setText(file.fileName());
    revealResButton->setDisabled(false);
}

QString RunGroupBox::getAppPath() {
    return finder->currentText();
}
