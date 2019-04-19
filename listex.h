#ifndef LISTEX_H
#define LISTEX_H

#include <QWidget>
#include <windows.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QLabel>
#include <QDesktopServices>
#include <QUrl>
#include <string>
#include <QElapsedTimer>
namespace Ui {
class Listex;
}

class Listex : public QWidget
{
    Q_OBJECT

public:
    explicit Listex(QWidget *parent = nullptr);
    ~Listex();
    int iteraforlist = 0;
    int listworker = 12;
    QString pathlist = "/data/list.txt";
    QString pathreg = "/data/regions.txt";
    QString saveregfile = "/data/savereg.txt";

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Listex *ui;
};

#endif // LISTEX_H
