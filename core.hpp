#ifndef CORE_HPP
#define CORE_HPP

#include <thread>
#include <sstream>
#include <fstream>
#include <iostream>
#include <QProcess>
#include <QFileInfo>
#include <QTimer>
#include <QTime>

#include "log_view.hpp"
#include "general_view.hpp"
#include "hidden_var_view.hpp"

class Core: public QObject {
    Q_OBJECT
public:
    
    // Parameterized Constructor
    Core(GeneralView *gv, HiddenVarView *hv, LogView *lv);
    
signals:
    
    void showProcessView(bool value);

public slots:
    
    void runMatlab();
    
    void runPython();
    
    void stopProcess();
    
    
private slots:
    
    void updateTime();
    
private:
    
    // General Tab
    GeneralView *general;
    
    // Hidden Variable Tab
    HiddenVarView *hiddenVar;
    
    // Log
    LogView *log;
    
    QTime time;
    
    QTimer *timer;
    
    QProcess *process;
    
    void finishedMatlab(int exitCode, QProcess::ExitStatus exitStatus);
    
    void finishedPython(int exitCode, QProcess::ExitStatus exitStatus);
    
    void errorOccurred(QProcess::ProcessError error);
};

#endif
