#ifndef SECONDARYWINDOW_H
#define SECONDARYWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class SecondaryWindow;
}

class SecondaryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondaryWindow(QWidget *parent = 0);
    ~SecondaryWindow();

private slots:
    void score_changed_Assignment1(int a);
    void score_changed_Assignment2(int a);
    void score_changed_Assignment3(int a);
    void score_changed_midterm1(int a);
    void score_changed_final(int a);
    void score_changed_project(int a);

    void on_Scheme_A_Selection_clicked();

    void on_Scheme_B_Selection_clicked();

    void on_Course_Selection_currentIndexChanged(const QString &arg1);

private:
    Ui::SecondaryWindow *ui;
};

#endif // SECONDARYWINDOW_H
