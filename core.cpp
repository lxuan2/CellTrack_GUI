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
	std::ofstream out((path + "/tempPort.txt"));
	out << videoPath << "\n" << videoName << "\n" << maxSize << "\n" << minSize << "\n" << areaBool << "\n" << eccentricityBool << "\n" << orientationBool;
	out.close();
    
    log->write("\n   Running MATLAB Code...\n");
    
    // Run matlab code
    //input: videoPath, videoName, maxSize, minSize, areaBool, eccentricityBool, orientationBool
    
    if (!matlabCode())
        return log->write("\n-- Finish Analysis --\n");
    
    /* Output: totalcells_GT, totalcells, stoppedcells_GT, stoppedcells, stoppedpercent_GT,
    stopped_percent,tracking_accuracy, stoppedcell_accuracy, output_filename
    */
    
	std::ifstream in((path + "/tempPort.txt"));
	std::string tmp[9];
	for (int i = 0; i < 9; i++) {
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

	emit loadResualt(tmp[8]);
    log->write("-- Finish Analysis --\n");
}

bool Core::matlabCode() {
    
#ifdef OS_Windows
    STARTUPINFO info = { sizeof(info) };
    PROCESS_INFORMATION processInfo;
    const char *exeChar = exeLoc.c_str();
    if (CreateProcess(exeChar, NULL, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
    {
        WaitForSingleObject(processInfo.hProcess, INFINITE);
        CloseHandle(processInfo.hProcess);
        CloseHandle(processInfo.hThread);
        return true;
    }
    log->write("Error: fail to run C# application.");
#else
    log->write("Error: To generate the video, Windows system is needed.");
#endif
    return false;
}

void Core::setExe(QString exeLoc) {
	Core::exeLoc = exeLoc.toStdString();
	QFileInfo info(exeLoc);
	path = info.path().toStdString();
}
