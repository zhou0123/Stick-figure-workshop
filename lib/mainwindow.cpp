#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->move(400, 400);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_CoastEntry_clicked()
{
    Coast temp;
    temp.exec();
}

void MainWindow::on_Country_clicked()
{
    Country temp;
    temp.exec();
}


void MainWindow::on_City_clicked()
{
    City temp;
    temp.exec();
}

