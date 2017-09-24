#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <qfiledialog.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qmessagebox.h>
#include <qdebug.h>
#include <vector>
#include <QString>

QVector<struct touchdata *> Tdata;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setdata(200);
    ui->horizontalSlider->setMaximum(1);
    ui->horizontalSlider->setMinimum(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    //ui->textEdit->setText(QString::number(value,10));
    if(Tdata.size() == 0)
        return;
    setdata(value);
}
/**
void MainWindow::setdata(int value)
{
    QStandardItemModel *model = new QStandardItemModel();
     model->setColumnCount(8);
     for(int i = 0; i < 10; i++)
      {
         for (int j = 0; j < 8; j++)
         {
            // model->setItem(i,j,new QStandardItem(QString::number(value,10)));
             model->setItem(i,j,new QStandardItem(Tdata.at(value)->data[i][j]));
                //设置字符颜色
             model->item(i,j)->setForeground(QBrush(QColor(255, 0, 0)));
                //设置字符位置
             model->item(i,j)->setTextAlignment(Qt::AlignCenter);
             //model->setItem(i,1,new QStandardItem(QString::fromLocal8Bit("哈哈")));
         }
      }
     ui->tableView->setModel(model);
}
**/
void MainWindow::setdata(int value)
{

    QStandardItemModel *model = new QStandardItemModel();
    struct touchdata* rdata  = Tdata.at(value);
     model->setColumnCount(8);
     for(int i = 0; i < 10; i++)
      {
         for (int j = 0; j < 8; j++)
         {
            // model->setItem(i,j,new QStandardItem(QString::number(value,10)));
             model->setItem(i,j,new QStandardItem(rdata->data[i][j]));
                //设置字符颜色
             model->item(i,j)->setForeground(QBrush(QColor(255, 0, 0)));
                //设置字符位置
             model->item(i,j)->setTextAlignment(Qt::AlignCenter);
             //model->setItem(i,1,new QStandardItem(QString::fromLocal8Bit("哈哈")));
         }
      }
     ui->tableView->setModel(model);
}


void MainWindow::process_data(QString str)
{
    static struct touchdata* oridata = NULL;
    static int index = 0;
    QStringList sections = str.split(" ");
    //qDebug("Output debug infomation %d", 1);
    if(sections.size() < 8){
        if(oridata != NULL)
            Tdata.push_back(oridata);
        oridata = new (struct touchdata);
        qDebug("Sections size : %s",sections.at(0));
        oridata->times =sections.at(0);
        index = 0;
        return;
    }

    for(int i = 0; i< sections.size(); i++){
        //ui->textEdit->append(sections.at(i));
        oridata->data[index][i] = sections.at(i);
    }
    index++;
}

void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,NULL,NULL,"*");
    QFile file(filename);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
        QTextStream textStream(&file);
        ui->textEdit->clear();
        while(!textStream.atEnd()){
            process_data(textStream.readLine());
            //qDebug.(textStream.readLine());
            //ui->textEdit->append(textStream.readLine());
        }
        ui->horizontalSlider->setMaximum(Tdata.size()-1);
        ui->horizontalSlider->setMinimum(0);

    }else{
        QMessageBox::information(NULL,NULL,"open file error");
    }
}
