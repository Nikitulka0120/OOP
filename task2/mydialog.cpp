#include "mydialog.h"
#include "QMessageBox"
#include "./ui_mydialog.h"
#include <QMainWindow>
#include <QtCharts/QChartView>
#include "math.h"



MyDialog::MyDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_pushButton_clicked()
{
    double start,end,step;
    double a = 0.5;
    double L,y;
    QString s1,s2,s3;
    QString str("");
    s1=ui->lineEdit->text();
    start=s1.toDouble();
    s2=ui->lineEdit_2->text();
    end=s2.toDouble();
    s3=ui->lineEdit_3->text();
    step=s3.toDouble();
    series = new QLineSeries;
    for(y=start;y<=end;y=y+step)
    {
        L=pow(cos(y),3)+pow(a,y);
        series->append(L,y);
        str=str+"L="+s1.number(L)+"\ty="+s1.number(y)+"\n";
    }
    QMessageBox::information(this,"Результат",str);
}



void MyDialog::on_graph_clicked()
{
    QChart *chart = new QChart(); // создание графика
    chart->setAnimationOptions(QChart::AllAnimations); // анимированное появление
    chart->legend()->hide(); // не показывать легенду
    chart->addSeries(series); // добавить набор данных
    chart->createDefaultAxes(); // создать основные оси
    chart->setTitle("График функции");
    QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing); // сглаживание
    chartView->setMinimumSize(640, 480);
    QMainWindow *window = new QMainWindow();
    window->setCentralWidget(chartView); // добавить график в окно
    window->show();

}

