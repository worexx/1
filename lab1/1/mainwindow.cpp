#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmath.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (currentFunction == 0) {
        ui->label_2->setText("");
    }

    ui->lineEdit->setDisabled(true);

    toggleStateButtons(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    currentFunction = 1;
    ui->label_2->setText("Функция: y = cos2x - 5sin(x) - 3");
    ui->label_6->setText("");
    ui->lineEdit->setDisabled(false);
}

void MainWindow::on_pushButton_2_clicked()
{
    currentFunction = 2;
    ui->label_2->setText("Функция: y = 7^(1 + x^3) - 4^(1 - x^6)");
    ui->label_6->setText("");
    ui->lineEdit->setDisabled(false);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString inputValue = ui->lineEdit->text();
    double inputValueToDouble = inputValue.toDouble();
    double result = 0;

    if (currentFunction == 1) {
        result = cos(2*inputValueToDouble) - 5 * sin(inputValueToDouble) - 3;
        renderExecutedResult("y = cos2x - 5sinx - 3", inputValueToDouble, result);
    }
    if (currentFunction == 2) {
        result = qPow(7, 1 + qPow(inputValueToDouble, 3)) - qPow(4, 1 - qPow(inputValueToDouble, 6));
        renderExecutedResult("y = 7^(1 + x^3) - 4^(1 - x^6)", inputValueToDouble, result);
    }

}

void MainWindow::renderExecutedResult(const QString &str, double inputValue, double result) {
    ui->label_6
            ->setText(QString("Результат для функции [ %1 ] в точке [ %2 ] равен [ %3 ]")
                                                     .arg(str).arg(inputValue).arg(result));
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty() && currentFunction > 0) {
        toggleStateButtons(false);
    } else {
       toggleStateButtons(true);
       ui->label_6->setText("");
    }
}

void MainWindow::toggleStateButtons(bool flag) {
    ui->pushButton_3->setDisabled(flag);
}
