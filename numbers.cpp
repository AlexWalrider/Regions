#include "numbers.h"
#include "ui_numbers.h"

numbers::numbers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::numbers)
{
    ui->setupUi(this);
    setFixedSize(size());
}

numbers::~numbers()
{
    delete ui;
}

void numbers::on_pushButton_clicked()
{
    int rows = ui->listWidget->model()->rowCount();
    ui->listWidget->model()->removeRows(0,rows);
    QString path = qApp->applicationDirPath() + numfile;
    QFile inputFile(path);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       int line_count=0;
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          //itemText = itemText.replace(QString("+"), QString(""));
          line.remove('+');
          line.remove(0,1);
          line = "7" + line;
          ui->listWidget->insertItem(line_count,line);
          line_count++;
       }
       inputFile.close();
    }
}
bool strcon(QString str, QString find)
{
    if (str.contains(find)) return true;
    else return false;
}
void numbers::on_pushButton_2_clicked()
{
    QElapsedTimer timer;
    timer.start();
    int liner = 0;
    int rows = ui->listWidget->model()->rowCount();
    int allreg = 0;
    int kavkaz = 0;
    int centerural = 0;
    int centernomos = 0;
    int center = 0;
    int severoz = 0;
    int ural = 0;
    int sibir = 0;
    int dalvost = 0;
    int moskwa = 0;
    int novpiter = 0;
    int privol = 0;
    int allnodv = 0;
    int allnodvural = 0;
    int primorsk = 0;
    int allnosz = 0;
    int mix1 = 0;
    int mix2 = 0;
    int mix3 = 0;
    int mix4 = 0;
    int mix5 = 0;
    int mix6 = 0;
    for (int i =0; i <rows; i++)
    {
        ui->listWidget->setCurrentRow(liner);
        QModelIndex index = ui->listWidget->currentIndex();
        QString itemText = index.data(Qt::DisplayRole).toString();
        QString sS = itemText.mid(0,4);
        if (strcon(sS,"7989")||strcon(sS,"7903")||strcon(sS,"7909")||strcon(sS,"7963")||strcon(sS,"7964")||strcon(sS,"7965")||strcon(sS,"7966")||strcon(sS,"7967")||strcon(sS,"7968")||strcon(sS,"7929")||strcon(sS,"7900")||strcon(sS,"7901")||strcon(sS,"7902")||strcon(sS,"7904")||strcon(sS,"7908")||strcon(sS,"7950")||strcon(sS,"7951")||strcon(sS,"7952")||strcon(sS,"7953")||strcon(sS,"7958")) allreg++;
        if (strcon(sS,"7918")||strcon(sS,"7988")||strcon(sS,"7928"))kavkaz++;
        if (strcon(sS,"7919"))centerural++;
        if (strcon(sS,"7980"))centernomos++;
        if (strcon(sS,"7910")||strcon(sS,"7915")||strcon(sS,"7920"))center++;
        if (strcon(sS,"7981")||strcon(sS,"7911")||strcon(sS,"7921"))severoz++;
        if (strcon(sS,"7982")||strcon(sS,"7912")||strcon(sS,"7922"))ural++;
        if (strcon(sS,"7983")||strcon(sS,"7913")||strcon(sS,"7923"))sibir++;
        if (strcon(sS,"7984")||strcon(sS,"7914")||strcon(sS,"7924"))dalvost++;
        if (strcon(sS,"7985")||strcon(sS,"7916")||strcon(sS,"7925")||strcon(sS,"7926")||strcon(sS,"7977"))moskwa++;
        if (strcon(sS,"7991"))novpiter++;
        if (strcon(sS,"7987")||strcon(sS,"7917")||strcon(sS,"7927"))privol++;
        if (strcon(sS,"7905")||strcon(sS,"7906"))allnodv++;
        if (strcon(sS,"7960"))allnodvural++;
        if (strcon(sS,"7951")||strcon(sS,"7953"))primorsk++;
        if (strcon(sS,"7961")||strcon(sS,"7962"))allnosz++;
        if (strcon(sS,"7992"))mix1++;
        if (strcon(sS,"7993"))mix2++;
        if (strcon(sS,"7994"))mix3++;
        if (strcon(sS,"7995"))mix4++;
        if (strcon(sS,"7996"))mix5++;
        if (strcon(sS,"7999"))mix6++;
        liner++;
        //qDebug() << itemText << liner;
    }
    /////////////////
    int fuller = allreg + kavkaz + centerural + centernomos +center+severoz+ural+sibir+dalvost+moskwa+novpiter+privol+allnodv+allnodvural+primorsk+allnosz+mix1+mix2+mix3+mix4+mix5+mix6;
    int noner = rows-fuller;
    QString tolabel = "Все регионы: <b>" + QString::number(allreg);
    tolabel = tolabel + "</b><br>Все регионы, кроме Дальнего Востока: <b>" + QString::number(allnodv);
    tolabel = tolabel + "</b><br>Все регионы, кроме Урала и Дальнего Востока: <b>" + QString::number(allnodvural);
    tolabel = tolabel + "</b><br>Все регионы, кроме Северо-Запада: <b>" + QString::number(allnosz);
    tolabel = tolabel + "</b><br>Центр, Урал, юг, Северный Кавказ, Приволжье: <b>" + QString::number(centerural);
    tolabel = tolabel + "</b><br>Центральные регионы, кроме Москвы и Московской области: <b>" + QString::number(centernomos);
    tolabel = tolabel + "</b><br>Центральные регионы: <b>" + QString::number(center);
    tolabel = tolabel + "</b><br>Москва и мос.обл: <b>" + QString::number(moskwa);
    tolabel = tolabel + "</b><br>Новгородская область, Санкт-Петербург и обл.: <b>" + QString::number(novpiter);
    tolabel = tolabel + "</b><br>Северо-запад: <b>" + QString::number(severoz);
    tolabel = tolabel + "</b><br>Юг, Кавказ: <b>" + QString::number(kavkaz);
    tolabel = tolabel + "</b><br>Урал: <b>" + QString::number(ural);
    tolabel = tolabel + "</b><br>Сибирь: <b>" + QString::number(sibir);
    tolabel = tolabel + "</b><br>Дальний восток: <b>" + QString::number(dalvost);
    tolabel = tolabel + "</b><br>Приволжье: <b>" + QString::number(privol);
    tolabel = tolabel + "</b><br>Приморский край: <b>" + QString::number(primorsk);
    tolabel = tolabel + "</b><br>Курганская обл, Пермский край, Тюменская обл, <br>Ханты-Мансийский АО, Челябинская обл, Ямало-Ненецкий АО: <b>" + QString::number(mix1);
    tolabel = tolabel + "</b><br>Магаданская обл, Орловская обл, Республика Тыва, Тамбовская обл, Хакасия: <b>" + QString::number(mix2);
    tolabel = tolabel + "</b><br>Амурская обл, Камчатский край, Магаданская обл, Сахалинcкая обл: <b>" + QString::number(mix3);
    tolabel = tolabel + "</b><br>Калмыкия, Краснодарский край, Республика Адыгея: <b>" + QString::number(mix4);
    tolabel = tolabel + "</b><br>Марий Эл, Оренбургская обл, Ульяновская обл, Чувашская республика: <b>" + QString::number(mix5);
    tolabel = tolabel + "</b><br>Костромская обл, Москва и Московская обл, Тамбовская обл, Ярославская обл: <b>" + QString::number(mix6);
    tolabel = tolabel + "</b><br>Неизвестно: <b>" + QString::number(noner);
    tolabel = tolabel + "</b><br>---------------------";
    long long timesec = timer.elapsed();
    tolabel = tolabel + "<br>Всего: <b>" + QString::number(rows) + "</b>" + "<br>Затраченное время: <b>" + QString::number(timesec) + "</b> миллисекунд";
    ui->label->setText(tolabel);
    //qDebug() << allreg << kavkaz << centerural << centernomos <<center<<severoz<<ural<<sibir<<dalvost<<moskwa<<novpiter<<privol<<allnodv<<allnodvural<<primorsk<<allnosz<<mix1<<mix2<<mix3<<mix4<<mix5<<mix6;
    //qDebug ()<<fuller << noner;
}
void numbers::on_pushButton_3_clicked()
{
     QString path = "file:///" + qApp->applicationDirPath() + numfile;
     QDesktopServices::openUrl(QUrl(path));
}
