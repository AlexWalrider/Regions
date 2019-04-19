#ifndef NUMBERS_H
#define NUMBERS_H

#include <QWidget>
#include <windows.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QLabel>
#include <QDesktopServices>
#include <QUrl>
#include <QElapsedTimer>

namespace Ui {
class numbers;
}

class numbers : public QWidget
{
    Q_OBJECT

public:
    explicit numbers(QWidget *parent = nullptr);
    ~numbers();
    QString numfile =  "/data/phone.txt";

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::numbers *ui;
};

#endif // NUMBERS_H
