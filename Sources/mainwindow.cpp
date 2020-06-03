#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Plugin *vdjPlugin)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , plugin(vdjPlugin)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete plugin;
}
