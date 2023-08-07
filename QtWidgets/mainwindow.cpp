#include "mainwindow.h"
#include "switchslider.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    SwitchSlider* slider = new SwitchSlider(this);
    setCentralWidget(slider);
}

MainWindow::~MainWindow()
{
}

