#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include <QDebug>

double firstNum;
bool userIsTypingSecondNumber = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pBtn_0, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pBtn_1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pBtn_2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pBtn_3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pBtn_4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pBtn_5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pBtn_6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pBtn_7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pBtn_8, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pBtn_9, SIGNAL(released()), this, SLOT(digit_pressed()));

    connect(ui->pBtn_plusMinus, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
    connect(ui->pBtn_percent, SIGNAL(released()), this, SLOT(unary_operation_pressed()));

    connect(ui->pBtn_plus, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pBtn_minus, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pBtn_multiply, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pBtn_divide, SIGNAL(released()), this, SLOT(binary_operation_pressed()));

    ui->pBtn_plus->setCheckable(true);
    ui->pBtn_minus->setCheckable(true);
    ui->pBtn_multiply->setCheckable(true);
    ui->pBtn_divide->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::digit_pressed()
{

//    qDebug() << "test";
    QPushButton * button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    if ((ui->pBtn_plus->isChecked() || ui->pBtn_minus->isChecked() ||
         ui->pBtn_multiply->isChecked() || ui->pBtn_divide->isChecked()) &&
            (!userIsTypingSecondNumber))
    {
        labelNumber = button->text().toDouble();
        userIsTypingSecondNumber = true;
        newLabel = QString::number(labelNumber, 'g', 15);
    }
    else
    {
        if (ui->label->text().contains('.') && button->text() == "0")
        {
            newLabel = ui->label->text() + button->text();
        }
        else
        {
            labelNumber = (ui->label->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber, 'g', 15);
        }

    }


    ui->label->setText(newLabel);

}

void MainWindow::on_pBtn_decimal_released()
{
    // If already has decimal, don't add
    ui->label->setText(ui->label->text() + '.');
}

void MainWindow::unary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;

    if (button->text() == "+/-")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
    else if (button->text() == "%")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::on_pBut_Clear_released()
{
    ui->label->setText("0");

    ui->pBtn_plus->setChecked(false);
    ui->pBtn_minus->setChecked(false);
    ui->pBtn_multiply->setChecked(false);
    ui->pBtn_divide->setChecked(false);

    userIsTypingSecondNumber = false;
}

void MainWindow::on_pBtn_equals_released()
{
    double labelNumber, secondNum;
    QString newLabel;

    secondNum = ui->label->text().toDouble();

    if (ui->pBtn_plus->isChecked())
    {
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);

        ui->label->setText(newLabel);
        ui->pBtn_plus->setChecked(false);
    }
    else if (ui->pBtn_minus->isChecked())
    {
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);

        ui->label->setText(newLabel);
        ui->pBtn_minus->setChecked(false);
    }
    else if (ui->pBtn_multiply->isChecked())
    {
        labelNumber = firstNum * secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);

        ui->label->setText(newLabel);
        ui->pBtn_multiply->setChecked(false);
    }
    else if (ui->pBtn_divide->isChecked())
    {
        labelNumber = firstNum / secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);

        ui->label->setText(newLabel);
        ui->pBtn_divide->setChecked(false);
    }

    userIsTypingSecondNumber = false;
}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    firstNum = ui->label->text().toDouble();


    button->setChecked(true);

}
