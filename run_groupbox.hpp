#ifndef run_groupbox_hpp
#define run_groupbox_hpp

#include <QGroupBox>
#include <QToolButton>

#include "log_view.hpp"
#include "log_preview.hpp"
#include "file_finder.hpp"
#include "user_data.hpp"

class RunGroupBox: public QGroupBox
{
    Q_OBJECT
public:
    
    // Default constructor
    RunGroupBox(QString app, UserData *data, LogView *l);
    
    QString getAppPath();

signals:
    
    // Call C# app and generate video
    void run();
    
public slots:
    
    void updateSrc(QString fp);
    void updateRes(QString fp);
    
private slots:
    
    void loadCsharp();
    
    void analyzeButtonClicked();
    
    void revealOrgClicked();
    
    void revealResClicked();
    
private:
    
    FileFinder *finder;
    
    // Button
    QPushButton *analyzeButton;
    QToolButton *revealOrgButton;
    QToolButton *revealResButton;
    
    QPixmap applyPixmap;
    QPixmap cancelPixmap;
    
    QLabel *sourceApply;
    QLabel *appApply;
    
    QLabel *sourceName;
    QLabel *appName;
    QLabel *resultName;
    
    QString srcPath;
    QString appPath;
    QString resPath;
    
    // Log widget
    LogView *log;
};

#endif
