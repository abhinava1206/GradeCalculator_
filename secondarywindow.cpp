#include "secondarywindow.h"
#include "ui_secondarywindow.h"
#include <QString>
#include <string>

using namespace std;

SecondaryWindow::SecondaryWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondaryWindow)
{
    ui->setupUi(this);
    ui->Assignment1_scroll->setRange(0,100); ui->Assignment1_spin->setRange(0,100);
    ui->Assignment2_scroll->setRange(0,100); ui->Assignment2_spin->setRange(0,100);
    ui->Assignment3_scroll->setRange(0,100); ui->Assignment3_spin->setRange(0,100);
    ui->Midterm1_scroll->setRange(0,100); ui->Midterm1_spin->setRange(0,100);
    ui->Final_scroll->setRange(0,100); ui->Final_spin->setRange(0,100);
    ui->Project_scroll->setRange(0,100); ui->Project_spin->setRange(0,100);
    connect(ui->Assignment1_scroll,SIGNAL(valueChanged(int)), this, SLOT(score_changed_Assignment1(int)));
    connect(ui->Assignment2_scroll,SIGNAL(valueChanged(int)), this, SLOT(score_changed_Assignment2(int)));
    connect(ui->Assignment3_scroll,SIGNAL(valueChanged(int)), this, SLOT(score_changed_Assignment3(int)));
    connect(ui->Midterm1_scroll,SIGNAL(valueChanged(int)), this, SLOT(score_changed_midterm1(int)));
    connect(ui->Final_scroll,SIGNAL(valueChanged(int)), this, SLOT(score_changed_final(int)));
    connect(ui->Project_scroll,SIGNAL(valueChanged(int)), this, SLOT(score_changed_project(int)));
    connect(ui->Assignment1_spin, SIGNAL(valueChanged(int)), this, SLOT(score_changed_Assignment1(int)));
    connect(ui->Assignment2_spin, SIGNAL(valueChanged(int)), this, SLOT(score_changed_Assignment2(int)));
    connect(ui->Assignment3_spin, SIGNAL(valueChanged(int)), this, SLOT(score_changed_Assignment3(int)));
    connect(ui->Midterm1_spin, SIGNAL(valueChanged(int)), this, SLOT(score_changed_midterm1(int)));
    connect(ui->Final_spin, SIGNAL(valueChanged(int)), this, SLOT(score_changed_final(int)));
    connect(ui->Project_spin,SIGNAL(valueChanged(int)),this,SLOT(score_changed_project(int)));
}

SecondaryWindow::~SecondaryWindow()
{
    delete ui;
}

int assignment1, assignment2, assignment3, midterm, final_exam, project = 0;
void SecondaryWindow:: score_changed_Assignment1(int a)
{
    assignment1 = a;
}

void SecondaryWindow:: score_changed_Assignment2(int a)
{
    assignment2 = a;
}

void SecondaryWindow:: score_changed_Assignment3(int a)
{
    assignment3 = a;
}

void SecondaryWindow:: score_changed_midterm1(int a)
{
    midterm = a;
}

void SecondaryWindow:: score_changed_final(int a)
{
    final_exam = a;
}

void SecondaryWindow:: score_changed_project(int a)
{
    project = a;
}
void SecondaryWindow::on_Scheme_A_Selection_clicked()
{
    double final_class_score = (assignment1 + assignment2 + assignment3)*10/300.0 + (midterm*25)/100.0 + (final_exam*30)/100.0 + (project*35)/100;
    string q = std::to_string(final_class_score);
    QString qstr = QString::fromStdString(q);
    ui->Final_Score_Display->setText(qstr);
}


void SecondaryWindow::on_Scheme_B_Selection_clicked()
{
    double final_class_score = (assignment1 + assignment2 + assignment3)*15/300.0 + final_exam*50/100.0 + project*35/100;
    string q = std::to_string(final_class_score);
    QString qstr = QString::fromStdString(q);
    ui->Final_Score_Display->setText(qstr);
}

void SecondaryWindow::on_Course_Selection_currentIndexChanged(const QString &arg1)
{
    MainWindow * mw = new MainWindow();
    this->hide();
    mw->show();
}
