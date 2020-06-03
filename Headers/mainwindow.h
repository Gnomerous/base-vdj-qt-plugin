#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "plugin.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Plugin;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent, Plugin *vdjPlugin);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Plugin *plugin;
};
#endif // MAINWINDOW_H
