#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QMainWindow>
#include <QDialog>
#include <QSystemTrayIcon>

class QWidget;
class QLabel;
class QTimer;
class QPushButton;
class QAction;
class QMovie;
class QSystemTrayIcon;
class QMenu;
class QToolBar;

class FileDownloader;

class XMRStak;

class MainWindow : public QDialog
{
    Q_OBJECT
public:
    MainWindow(bool firstRun, QWidget *parent = 0);
    ~MainWindow();
private slots: 
    void onQuitButtonClicked();
    void onInfoButtonClicked();
    void onPauseButtonClicked();
    void onResumeButtonClicked();
    void onSettingsButtonClicked();
    void onUpdateStats();
    void onIconActivated(QSystemTrayIcon::ActivationReason reason);
    void onIconMessageClicked();
protected:
    void closeEvent(QCloseEvent* e) override;
private: 
    XMRStak* xmrstak = nullptr;
    double loadFraction = 0.2;
    bool autoStart = false;

    QMenu* menu;
    QTimer *updateTimer;
    QLabel* backgroundImageLabel, *statsLabel;
    QAction *pauseAction, *resumeAction; 
    QSystemTrayIcon* systemTrayIcon;
    QWidget  *toolBarWidget;

    FileDownloader *latestVersionFD, *updaterFD;

    QAction* addAction(QAction* a);
    QAction* addAction(const QString& action);
    void updateButtonState();
    void setAutoStart(bool autostart);
    bool getAutoStart();
};

#endif // MAINWINDOW_H
