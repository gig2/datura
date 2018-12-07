
#include "modelvisu.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDebug>
#include <QFileDialog>
#include <QMainWindow>

#include <memory>

MainWindow::MainWindow( QWidget *parent )
    : QMainWindow{parent}
    , ui{std::make_unique<Ui::MainWindow>()}
{
    ui->setupUi( this );
}

MainWindow::~MainWindow()
{
    //
}
