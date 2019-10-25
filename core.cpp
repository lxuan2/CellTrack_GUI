#include "core.hpp"

Core::Core(QWidget *parent, GeneralView *gv, HiddenVarView *hv, LogView *lv){
    general   = gv;
    hiddenVar = hv;
    log       = lv;
    proView   = new ProcessView(parent);
    process   = new QProcess();
    QObject::connect(process, &QProcess::errorOccurred, this, &Core::errorOccurred);
}

void Core::runMatlab() {
    log->write("\n-- Start Analysis --\n");
    
    QFileInfo file(general->getVideoPath());
    if (!file.exists())
        return log->write("Error: video file does not exist and cannot be analyzed\n\n-- Finish Analysis --\n");
    
    QFileInfo appfile(general->getAppPath());
    if (!appfile.exists())
        return log->write("Error: app does not exist\n\n-- Finish Analysis --\n");
    
    // Get parameters from General Tab
    std::string videoPath = file.path().toStdString();
    std::string videoName = file.fileName().toStdString();
    int maxSize           = general->getMaxSize();
    int minSize           = general->getMinSize();
    int areaBool          = general->isAreaChecked();
    int eccentricityBool  = general->isEccentricityChecked();
    int orientationBool   = general->isOrientationChecked();
    
    // Write parameters to Log
    log->write(QString::fromStdString("   File path: " + videoPath));
    log->write(QString::fromStdString("   File name: " + videoName));
    log->write(QString::fromStdString("   Cell size: max: " + std::to_string(maxSize) + ", min: " + std::to_string(minSize)));
    std::string areaString = areaBool? "Yes": "No";
    std::string eccentricityString = eccentricityBool? "Yes": "No";
    std::string orientationString = orientationBool? "Yes": "No";
    log->write(QString::fromStdString("   Area:         " + areaString));
    log->write(QString::fromStdString("   Eccentricity: " + eccentricityString));
    log->write(QString::fromStdString("   Orientation:  " + orientationString));
    
    // Pass parameters into exchange file
    std::ofstream out((appfile.path() + "/tempPort.txt").toStdString());
    out << videoPath << "\n" << videoName << "\n" << maxSize << "\n" << minSize << "\n" << areaBool << "\n" << eccentricityBool << "\n" << orientationBool;
    out.close();
    
    // Run matlab code
    //input: videoPath, videoName, maxSize, minSize, areaBool, eccentricityBool, orientationBool
    
    log->write("\n   Running MATLAB Code...\n");
    QObject::connect(process, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &Core::finishedMatlab);
    
    process->start(general->getAppPath());
    
    /* Output: totalcells_GT, totalcells, stoppedcells_GT, stoppedcells, stoppedpercent_GT,
    stopped_percent,tracking_accuracy, stoppedcell_accuracy, output_filename
    */
    proView->start();
}

void Core::finishedMatlab(int exitCode, QProcess::ExitStatus exitStatus) {
    // clear up everthing
    QObject::disconnect(process, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &Core::finishedMatlab);
    proView->stop();
    
    if (exitStatus == QProcess::CrashExit) {
        log->write("Error: the analysis process crashes for unknown reasons.\n\n-- Finish Analysis --\n");
        return;
    }
        
    QFileInfo info(general->getAppPath());
    std::ifstream in((info.path() + "/tempPort.txt").toStdString());
    std::string tmp[9];
    for (int i = 0; i < 9; i++) {
        if (in.fail())
            return log->write("Error: fail parsing the returned file.\n\n-- Finish Analysis --\n");
        in >> tmp[i];
    }

    log->write(QString::fromStdString("   Total number of cells present (Ground Truth):\n\t" + tmp[0] +
                "\n   Total number of cells detected by tracking:\n\t" + tmp[1] +
                "\n   Number of cells that stopped (Ground Truth):\n\t" + tmp[2] +
                "\n   Number of cells that stopped:\n\t" + tmp[3] +
                "\n   Percentage of cells that stopped (Ground Truth):\n\t" + tmp[4] +
                "\n   Percentage of cells that stopped:\n\t" + tmp[5] +
                "\n   Accuracy in tracking cells:\n\t" + tmp[6] +
                "\n   Accuracy in tracking stopped cells:\n\t" + tmp[7] +
                "\n   Output file name:\n\t" + tmp[8] + "\n"));
    
    log->write("   Using time: " + proView->timeCost());
    
    QFileInfo video(general->getVideoPath());
    general->setResultVideo(video.path() + QString::fromStdString("/" + tmp[8]));
    log->write("-- Finish Analysis --\n");
}


void Core::runPython() {
    log->write("\n-- Start Analysis --\n");
    
    // Check whether video file exists
    QFileInfo file(general->getVideoPath());
    if (!file.exists())
        return log->write("Error: video file does not exist and cannot be analyzed\n\n-- Finish Analysis --\n");
    
    QFileInfo appfile(general->getAppPath());
    if (!appfile.exists())
        return log->write("Error: python script does not exist\n\n-- Finish Analysis --\n");
    
    // Get parameters from General Tab
    QString videoPath = file.path();
    QString videoName = file.fileName();
    QString maxSize   = QString::number(general->getMaxSize());
    QString minSize   = QString::number(general->getMinSize());
    QString areaString          = general->isAreaChecked()? "Yes": "No";
    QString eccentricityString  = general->isEccentricityChecked()? "Yes": "No";
    QString orientationString   = general->isOrientationChecked()? "Yes": "No";
    
    // Write parameters to Log
    log->write("   File path: " + videoPath);
    log->write("   File name: " + videoName);
    log->write("   Cell size: max: " + maxSize + ", min: " + minSize);
    log->write("   Area:         " + areaString);
    log->write("   Eccentricity: " + eccentricityString);
    log->write("   Orientation:  " + orientationString);
    auto hvPrintArgument = hiddenVar->getPrintArguments(videoName);
    for (int i = 0; i < hvPrintArgument.size(); i++) {
        log->write(hvPrintArgument[i]);
    }
    
    // Pass parameters by arguments
    QStringList arguments;
    arguments << general->getAppPath() << videoPath << videoName << maxSize << minSize << areaString << eccentricityString << orientationString << hiddenVar->getArguments(videoName);
    
    // Run Python code
    //input: videoPath, videoName, maxSize, minSize, areaString, areaString, eccentricityString, orientationString, etc
    
    log->write("\n   Running Python Code...\n");
    QObject::connect(process, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &Core::finishedPython);
    process->start("python3", arguments);
    
    /* Output:
    */
    proView->start();
}

void Core::finishedPython(int exitCode, QProcess::ExitStatus exitStatus) {
    // clear up everthing
    QObject::disconnect(process, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &Core::finishedPython);
    proView->stop();
    
    if (exitStatus == QProcess::CrashExit) {
        log->write("Error: the analysis process crashes for unknown reasons.");
        return;
    }
    
    if (!process->canReadLine()) {
        log->write("Error: cannot read result from python script.");
    }
    log->write("   Printing out results from python console...");
    QByteArray result = process->readAll();
    std::string line = "";
    std::stringstream stream(result.toStdString());
    
    // Read output result
    std::string resVideo = "";
    std::getline(stream, resVideo);
    log->write("   " + QString::fromStdString(resVideo));
    
    while (std::getline(stream, line)) {
        log->write("   " + QString::fromStdString(line));
    }
    
    // Send result video to player
    QFileInfo video(QString::fromStdString(resVideo));
    if (video.exists())
        general->setResultVideo(QString::fromStdString(resVideo));
    else
        log->write("Error: The first return result is not video full path.");
    log->write("   Using time: " + proView->timeCost());
    log->write("-- Finish Analysis --\n");
}

void Core::errorOccurred(QProcess::ProcessError error) {
    QObject::disconnect(process, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &Core::finishedMatlab);
    QObject::disconnect(process, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &Core::finishedPython);
    log->write("  Error: the analysis process crashes for unknown reasons.\n\n-- Finish Analysis --\n");
    proView->stop();
}

void Core::stopProcess() {
    process->kill();
    QObject::disconnect(process, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &Core::finishedMatlab);
    QObject::disconnect(process, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &Core::finishedPython);
    log->write("Error: process canceled by user.\n\n-- Finish Analysis --\n");
}
