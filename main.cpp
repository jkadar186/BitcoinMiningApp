#include "MainWindow.h"

#include <vector>
#include <string>
#include <iostream>

#include <QApplication>
#include <QDesktopWidget>
#include <QSize>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setQuitOnLastWindowClosed(false);

    std::vector<std::string> args;
    for (int q = 1; q < argc; ++q) args.push_back(argv[q]);

    bool silent = false, firstRun = false;
    std::cout << "Args = ";
    for (size_t q = 0; q < args.size(); ++q) { std::cout << "'" << args[q] << "', ";
        if (args[q] == std::string("/silent")) silent = true;
        if (args[q] == std::string("/firstRun")) firstRun = true;
    }
    std::cout << std::endl;

    firstRun = firstRun || !QFile::exists(QFileInfo(QCoreApplication::applicationFilePath()).absoluteDir().absolutePath().append("/pools.txt"));

    std::cout << "Silent = " << silent << " firstRun = " << firstRun << std::endl;

    MainWindow w(firstRun);
    QSize s = QApplication::desktop()->geometry().size(), wSize = w.size();
    w.setGeometry((s.width() - wSize.width())/2, (s.height() - wSize.height())/2, wSize.width(), wSize.height());
    if (!silent) w.show();

    return a.exec();
}
