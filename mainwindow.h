#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "numbers.h"
#include "listex.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    numbers numbers;
    Listex listex;
};

#endif // MAINWINDOW_H
