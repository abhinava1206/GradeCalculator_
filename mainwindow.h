#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void score_changed_hw1(int a);
    void score_changed_hw2(int a);
    void score_changed_hw3(int a);
    void score_changed_hw4(int a);
    void score_changed_hw5(int a);
    void score_changed_hw6(int a);
    void score_changed_hw7(int a);
    void score_changed_hw8(int a);
    void score_changed_midterm1(int a);
    void score_changed_midterm2(int a);
    void score_changed_final(int a);
    void on_Course_Selection_currentIndexChanged(const QString &arg1);

    void on_Scheme_A_Selection_clicked();

    void on_Scheme_B_Selection_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
