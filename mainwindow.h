#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QMainWindow>
#include <QtWidgets/QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digit_pressed();
    void on_pBtn_decimal_released();
    void unary_operation_pressed();
    void on_pBut_Clear_released();
    void on_pBtn_equals_released();
    void binary_operation_pressed();
};

#endif // MAINWINDOW_H
