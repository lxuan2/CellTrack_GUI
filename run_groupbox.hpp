#ifndef run_groupbox_hpp
#define run_groupbox_hpp

#include <QGroupBox>

#include "log_view.hpp"
#include "file_finder.hpp"

class RunGroupBox: public QGroupBox
{
    Q_OBJECT
public:
    
    // Default constructor
    RunGroupBox(LogView *l);

signals:
    
    // Call C# app and generate video
    void compute(bool ans);
    
private slots:
    
    void loadCsharp();
    
    void analyzeButtonClicked();
    
private:
    
    FileFinder *finder;
    
    // Button
    QPushButton *analyzeButton;
    
    // Log widget
    LogView *log;
};

#endif
