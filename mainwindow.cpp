#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "secondarywindow.h"
#include <cstring>
#include <QString>
#include <vector>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->HW1_scroll,SIGNAL(valueChanged(int)), this, SLOT(score_changed_hw1(int)));
    connect(ui->HW2_scroll,SIGNAL(valueChanged(int)), this, SLOT(score_changed_hw2(int)));
    connect(ui->HW3_scroll,SIGNAL(valueChanged(int)), this, SLOT(score_changed_hw3(int)));
    connect(ui->HW4_scroll,SIGNAL(valueChanged(int)), this, SLOT(score_changed_hw4(int)));
    connect(ui->HW5_scroll,SIGNAL(valueChanged(int)), this, SLOT(score_changed_hw5(int)));
    connect(ui->HW6_scroll,SIGNAL(valueChanged(int)), this, SLOT(score_changed_hw6(int)));
    connect(ui->HW7_scroll,SIGNAL(valueChanged(int)), this, SLOT(score_changed_hw7(int)));
    connect(ui->HW8_scroll,SIGNAL(valueChanged(int)), this, SLOT(score_changed_hw8(int)));
    connect(ui->Midterm1_scroll,SIGNAL(valueChanged(int)), this, SLOT(score_changed_midterm1(int)));
    connect(ui->Midterm2_scroll,SIGNAL(valueChanged(int)), this, SLOT(score_changed_midterm2(int)));
    connect(ui->Final_scroll,SIGNAL(valueChanged(int)), this, SLOT(score_changed_final(int)));
    connect(ui->HW1_spin, SIGNAL(valueChanged(int)), this, SLOT(score_changed_hw1(int)));
    connect(ui->HW2_spin, SIGNAL(valueChanged(int)), this, SLOT(score_changed_hw2(int)));
    connect(ui->HW3_spin, SIGNAL(valueChanged(int)), this, SLOT(score_changed_hw3(int)));
    connect(ui->HW4_spin, SIGNAL(valueChanged(int)), this, SLOT(score_changed_hw4(int)));
    connect(ui->HW5_spin, SIGNAL(valueChanged(int)), this, SLOT(score_changed_hw5(int)));
    connect(ui->HW6_spin, SIGNAL(valueChanged(int)), this, SLOT(score_changed_hw6(int)));
    connect(ui->HW7_spin, SIGNAL(valueChanged(int)), this, SLOT(score_changed_hw7(int)));
    connect(ui->HW8_spin, SIGNAL(valueChanged(int)), this, SLOT(score_changed_hw8(int)));
    connect(ui->Midterm1_spin, SIGNAL(valueChanged(int)), this, SLOT(score_changed_midterm1(int)));
    connect(ui->Midterm2_spin, SIGNAL(valueChanged(int)), this, SLOT(score_changed_midterm2(int)));
    connect(ui->Final_spin, SIGNAL(valueChanged(int)), this, SLOT(score_changed_final(int)));
    ui->HW1_scroll->setRange(0,100); ui->HW1_spin->setRange(0,100);
    ui->HW2_scroll->setRange(0,100); ui->HW2_spin->setRange(0,100);
    ui->HW3_scroll->setRange(0,100); ui->HW3_spin->setRange(0,100);
    ui->HW4_scroll->setRange(0,100); ui->HW4_spin->setRange(0,100);
    ui->HW5_scroll->setRange(0,100); ui->HW5_spin->setRange(0,100);
    ui->HW6_scroll->setRange(0,100); ui->HW6_spin->setRange(0,100);
    ui->HW7_scroll->setRange(0,100); ui->HW7_spin->setRange(0,100);
    ui->HW8_scroll->setRange(0,100); ui->HW8_spin->setRange(0,100);
    ui->Midterm1_scroll->setRange(0,100); ui->Midterm1_spin->setRange(0,100);
    ui->Midterm2_scroll->setRange(0,100); ui->Midterm2_spin->setRange(0,100);
    ui->Final_scroll->setRange(0,100); ui->Final_spin->setRange(0,100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int hw1, hw2, hw3, hw4, hw5, hw6, hw7, hw8, midterm1, midterm2, final_exam_score = 0;
void MainWindow::score_changed_hw1(int a)
{
    hw1 = a;
}

void MainWindow::score_changed_hw2(int a)
{
    hw2 = a;
}

void MainWindow::score_changed_hw3(int a)
{
    hw3 = a;
}

void MainWindow::score_changed_hw4(int a)
{
    hw4 = a;
}

void MainWindow::score_changed_hw5(int a)
{
    hw5 = a;
}

void MainWindow::score_changed_hw6(int a)
{
    hw6 = a;
}

void MainWindow::score_changed_hw7(int a)
{
    hw7 = a;
}

void MainWindow::score_changed_hw8(int a)
{
    hw8 = a;
}

void MainWindow::score_changed_midterm1(int a)
{
    midterm1 = a;
}

void MainWindow::score_changed_midterm2(int a)
{
    midterm2 = a;
}

void MainWindow::score_changed_final(int a)
{
    final_exam_score = a;
}


void MainWindow::on_Course_Selection_currentIndexChanged(const QString &arg1)
{
    SecondaryWindow * sw = new SecondaryWindow();
    this->hide();
    sw->show();
}

void MainWindow::on_Scheme_A_Selection_clicked()
{
    vector<int> v;
    v.push_back(hw1); v.push_back(hw2); v.push_back(hw3); v.push_back(hw4); v.push_back(hw5); v.push_back(hw6); v.push_back(hw7); v.push_back(hw8);
    std::cout << std::endl;
    int min = v[0];
    int k = 0; int min_index = 0;
    while (k!=2) { // so the loop runs twice
        for (int i =  0; i < v.size(); i++)
        {
            if (v[i] < min)
            {
                min = v[i];
                min_index = i;
            }
        }
        v.erase(v.begin() + min_index); // gets rid of the lowest score
        k++;
    }
    int total_hw = 0;
    for (int i = 0; i < v.size(); i++)
    {
        total_hw += v[i];
    }
    double hw_score = (total_hw/600)*25;
    double final_class_score = hw_score + (midterm1*20)/100.0 + (midterm2*20)/100.0 + (final_exam_score*35)/100;
    string q = std::to_string(final_class_score);
    QString qstr = QString::fromStdString(q);
    ui->Final_Score_Display->setText(qstr);
}

int max_midterm = 0;

void MainWindow::on_Scheme_B_Selection_clicked()
{ // getting rid of the 2 lowest hw scores
    vector<int> v;
    v.push_back(hw1); v.push_back(hw2); v.push_back(hw3); v.push_back(hw4); v.push_back(hw5); v.push_back(hw6); v.push_back(hw7); v.push_back(hw8);
    std::cout << std::endl;
    int min = v[0];
    int k = 0; int min_index = 0;
    while (k!=2) { // so the loop runs twice
        for (int i =  0; i < v.size(); i++)
        {
            if (v[i] < min)
            {
                min = v[i];
                min_index = i;
            }
        }
        v.erase(v.begin() + min_index); // gets rid of the lowest score
        k++;
    }
    int total_hw = 0;
    for (int i = 0; i < v.size(); i++)
    {
        total_hw += v[i];
    }
    double hw_score = (total_hw/600)*25;
    max_midterm = midterm1;
    if (midterm2 > midterm1)
    {
        max_midterm = midterm2;
    }
    double final_class_score = hw_score + (max_midterm*30)/100 + (final_exam_score*44)/100;
    string q = std::to_string(final_class_score);
    QString qstr = QString::fromStdString(q);
    ui->Final_Score_Display->setText(qstr);
}
