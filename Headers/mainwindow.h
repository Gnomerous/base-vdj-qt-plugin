// This is a fairly straightforward MainWindow header file for a new project
// within Qt

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "plugin.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Because we will be including the plugin.h file, need to state this to prevent
// the circular dependency issue
class Plugin;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent, Plugin *vdjPlugin);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // Adding a pointer to our VDJ Plugin so we can continue to interact with VDJ
    Plugin *plugin;
};
#endif // MAINWINDOW_H
