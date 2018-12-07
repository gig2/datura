#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <memory>


namespace Ui
{
class MainWindow;
}


class MainWindow : public QMainWindow
{
public:
    explicit MainWindow( QWidget *parent = nullptr );

    virtual ~MainWindow();

private:
    std::unique_ptr<Ui::MainWindow> ui;
};

#endif // MAINWINDOW_H
