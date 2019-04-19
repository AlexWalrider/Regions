#include "listex.h"
#include "ui_listex.h"

Listex::Listex(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Listex)
{
    ui->setupUi(this);
    setFixedSize(size());
}

Listex::~Listex()
{
    delete ui;
}

void Listex::on_pushButton_3_clicked()
{
    QString path = "file:///" + qApp->applicationDirPath() + pathlist;
    QDesktopServices::openUrl(QUrl(path));
}
void Listex::on_pushButton_clicked()
{
    int rows = ui->listWidget->model()->rowCount();
    ui->listWidget->model()->removeRows(0,rows);
    QString path = qApp->applicationDirPath() + pathlist;
    QFile inputFile(path);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       int line_count=0;
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          ui->listWidget->insertItem(line_count,line);
          line_count++;
       }
       inputFile.close();
    }
    ////////////////////////////////
    int rowsreg = ui->listWidget_2->model()->rowCount();
    ui->listWidget_2->model()->removeRows(0,rowsreg);
    int rowsregcount = ui->listWidget_3->model()->rowCount();
    ui->listWidget_3->model()->removeRows(0,rowsregcount);
    int rowsregnonexe = ui->listWidget_4->model()->rowCount();
    ui->listWidget_4->model()->removeRows(0,rowsregnonexe);
    QString path2 = qApp->applicationDirPath() + pathreg;
    QFile inputFile2(path2);
    if (inputFile2.open(QIODevice::ReadOnly))
    {
       int line_count=0;
       QTextStream in(&inputFile2);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          ui->listWidget_2->insertItem(line_count,line);
          ui->listWidget_3->insertItem(line_count,"0");
          line_count++;
       }
       inputFile2.close();
    }


}
bool strconlex(QString str, QString find)
{
    if (str.contains(find,Qt::CaseInsensitive)) return true;
    else return false;
}
void Listex::on_pushButton_2_clicked()
{
    QElapsedTimer timer;
    timer.start();
    Listex::on_pushButton_clicked();
    int rows = ui->listWidget->model()->rowCount();
    int rowsreg = ui->listWidget_2->model()->rowCount();
    bool breaker = false;
    int notfound = 0;
    for (int i=0; i <rows; i++)
    {
        ui->listWidget->setCurrentRow(i);
        QModelIndex index = ui->listWidget->currentIndex();
        QString itemText = index.data(Qt::DisplayRole).toString();
        /////////////
        for (int ir =0; ir <rowsreg; ir++)
        {
            ui->listWidget_2->setCurrentRow(ir);
            QModelIndex indexer = ui->listWidget_2->currentIndex();
            QString itemTexter = indexer.data(Qt::DisplayRole).toString();
            if (strconlex(itemText,itemTexter))
            {
                ui->listWidget_3->setCurrentRow(ir);
                QModelIndex indexint = ui->listWidget_3->currentIndex();
                QString itemTexterz = indexint.data(Qt::DisplayRole).toString();
                int temper = itemTexterz.toInt();
                int iterator = temper+1;
                QString recorder = QString::number(iterator);
                //qDebug()<<temper<<iterator<<recorder<<ir;
                ui->listWidget_3->model()->removeRow(ir);
                ui->listWidget_3->insertItem(ir,recorder);
                breaker = true;
            }
            if (!strconlex(itemText,itemTexter))notfound++;
            if (breaker)
            {
                ir = rowsreg;
                breaker = false;
            }
            if(notfound == rowsreg)
            {
                ui->listWidget_4->insertItem(0,itemText);
                notfound = 0;
            }
        }
        notfound = 0;
  }
    QString tolabel = "Затраченное время: <b>" + QString::number(timer.elapsed()) + "</b> миллисекунд";
    ui->label->setText(tolabel);
    ui->listWidget->setCurrentRow(0);
    ui->listWidget_2->setCurrentRow(0);
    ui->listWidget_3->setCurrentRow(0);
    iteraforlist = 0;
}
void Listex::on_pushButton_4_clicked()
{
    QString path = "file:///" + qApp->applicationDirPath() + pathreg;
    QDesktopServices::openUrl(QUrl(path));
}
void Listex::on_pushButton_5_clicked()
{
    QString filename= qApp->applicationDirPath()+ saveregfile;
    QFile file(filename);
    file.remove();
    if (file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        int rowsreg = ui->listWidget_2->model()->rowCount();
        for (int ir=0; ir <rowsreg; ir++)
        {
            ui->listWidget_2->setCurrentRow(ir);
            ui->listWidget_3->setCurrentRow(ir);
            QModelIndex row1 = ui->listWidget_2->currentIndex();
            QString itemrow1 = row1.data(Qt::DisplayRole).toString();
            QModelIndex row2 = ui->listWidget_3->currentIndex();
            QString itemrow2 = row2.data(Qt::DisplayRole).toString();
            stream << itemrow1 <<" - "<< itemrow2 << "\n";
        }
    }
    QString path = "file:///" + qApp->applicationDirPath() + saveregfile;
    QDesktopServices::openUrl(QUrl(path));
}
void Listex::on_pushButton_6_clicked()
{
    if(iteraforlist!=0)iteraforlist=iteraforlist-listworker;
    if(iteraforlist<0)iteraforlist=0;
    ui->listWidget_2->setCurrentRow(iteraforlist);
    ui->listWidget_3->setCurrentRow(iteraforlist);
}
void Listex::on_pushButton_7_clicked()
{
    int rowsreg = ui->listWidget_2->model()->rowCount();
    if(iteraforlist!=rowsreg)iteraforlist=iteraforlist+listworker;
    if(iteraforlist>=rowsreg)iteraforlist=rowsreg-1;
    ui->listWidget_2->setCurrentRow(iteraforlist);
    ui->listWidget_3->setCurrentRow(iteraforlist);
}
