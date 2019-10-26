#ifndef CORE_HPP
#define CORE_HPP

#include <sstream>
#include <fstream>
#include <iostream>
#include <QProcess>
#include <QFileInfo>

#include "log_view.hpp"
#include "general_view.hpp"
#include "hidden_var_view.hpp"
#include "process_view.hpp"

class CoreMA: public QObject {
    Q_OBJECT
public:
    
    // Parameterized Constructor
    CoreMA(QWidget *parent, GeneralViewMA *gv, LogView *lv);

public slots:
    
    void runMatlab();
    
    void stopProcess();
    
private:
    
    // General Tab
    GeneralViewMA *general;
    
    // Log
    LogView *log;
    
    QProcess *process;
    
    ProcessView *proView;
    
    void finishedMatlab(int exitCode, QProcess::ExitStatus exitStatus);
    
    void errorOccurred(QProcess::ProcessError error);
};

class CorePy: public QObject {
    Q_OBJECT
public:
    
    // Parameterized Constructor
    CorePy(QWidget *parent, GeneralViewPy *gv, HiddenVarView *hv, LogView *lv);

public slots:
    
    void runPython();
    
    void stopProcess();
    
private:
    
    // General Tab
    GeneralViewPy *general;
    
    // Hidden Variable Tab
    HiddenVarView *hiddenVar;
    
    // Log
    LogView *log;
    
    QProcess *process;
    
    ProcessView *proView;
    
    void finishedPython(int exitCode, QProcess::ExitStatus exitStatus);
    
    void errorOccurred(QProcess::ProcessError error);
};

#endif
