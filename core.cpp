#include "core.hpp"

Core::Core(VideoGroupBox *v, ControPannelGroupBox *c, LogWidget *l) {
    videoBox = v;
    controlBox = c;
    log = l;
}

void Core::compute() {
    log->write("\n- Start Analysis -");
    
    QString fileFullName = videoBox->currentFile();
    if (fileFullName.isEmpty())
        return log->write("- No video file to be analyzed -\n- Finish Analysis -\n");
        
    QFile file(fileFullName);
    if (!file.exists())
        return log->write("- File does not exist and cannot be analyzed -\n- Finish Analysis -\n");
    // TODO: get current path
    
    log->write("Cell Size setting:");
    std::string max = std::to_string(controlBox->maxSize());
    std::string min = std::to_string(controlBox->minSize());
    log->write(QString::fromStdString("max: " + max + ", min: " + min));
    
    // matlab code
    
    log->write("- Finish Analysis -\n");
}
