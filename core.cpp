#include "core.hpp"

Core::Core(VideoGroupBox *v, ControPannelGroupBox *c, LogWidget *l) {
    videoBox = v;
    controlBox = c;
    log = l;
}

void Core::compute() {
    log->write("\n-- Start Analysis --\n");
    
    QString fileFullName = videoBox->currentFile();
    if (fileFullName.isEmpty())
        return log->write("Error: No video file to be analyzed\n\n-- Finish Analysis --\n");
        
    QFileInfo file(fileFullName);
    if (!file.exists())
        return log->write("Error: File does not exist and cannot be analyzed\n\n-- Finish Analysis --\n");
    
    // TODO: get videoPath
    std::string videoPath = file.path().toStdString();
    std::string videoName = file.fileName().toStdString();
    int maxSize = controlBox->maxSize();
    int minSize = controlBox->minSize();
    int areaBool = controlBox->isAreaChecked();
    int eccentricityBool = controlBox->isEccentricityChecked();
    int orientationBool = controlBox->isOrientationChecked();
    
    // Print out settings
    log->write(QString::fromStdString("   File path: " + videoPath));
    log->write(QString::fromStdString("   File name: " + videoName));
    log->write(QString::fromStdString("   Cell size: max: " + std::to_string(maxSize) + ", min: " + std::to_string(minSize)));
    std::string areaString = areaBool? "Yes": "No";
    std::string eccentricityString = eccentricityBool? "Yes": "No";
    std::string orientationString = orientationBool? "Yes": "No";
    log->write(QString::fromStdString("   Area:         " + areaString));
    log->write(QString::fromStdString("   Eccentricity: " + eccentricityString));
    log->write(QString::fromStdString("   Orientation:  " + orientationString));
	std::ofstream out("tempPort.txt");
	out << videoPath << "\n" << videoName << "\n" << maxSize << "\n" << minSize << "\n" << areaBool << "\n" << eccentricityBool << "\n" << orientationBool;
	out.close();
    
    // input: videoPath, videoName, maxSize, minSize, areaBool, eccentricityBool, orientationBool
    
    log->write("\n   Running MATLAB Code...\n");

    //run matlab code
	matlabCode();
    // output:
    
    log->write("-- Finish Analysis --\n");
}

void Core::matlabCode() {
    
#ifdef OS_Windows
    STARTUPINFO info = { sizeof(info) };
    PROCESS_INFORMATION processInfo;
    //const char x[50] = "C:/Users/Xuan/Desktop/Release/CombinedCodeApp.exe";
    const char *exeChar = exeLoc.c_str();
    if (CreateProcess(exeChar, NULL, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
    {
        WaitForSingleObject(processInfo.hProcess, INFINITE);
        CloseHandle(processInfo.hProcess);
        CloseHandle(processInfo.hThread);
    }
#endif
    
}

void Core::setExe(QString exeLoc) {
    Core::exeLoc = exeLoc.toStdString();
}
