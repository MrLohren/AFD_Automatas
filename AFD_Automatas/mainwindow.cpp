#include "mainwindow.h"
#include "ui_mainwindow.h"

// Inclusiones propias //
#include <iostream>
#include <sstream>
using namespace std;

// Estructuras //
struct transicion{
    int e_salida;
    string sim_transicion;
    int e_llegada;
}; typedef struct transicion transicion;

//Declaraciones //
stringstream ss;
int cant_estados = 1;
QString campotexto;

// Funciones //
//string funcion(string p);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label2->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->comboBox->currentText() != NULL && ui->comboBox_2->currentText() != NULL){
        if(ui->comboBox_2->currentText() == "Nuevo Estado"){
            cant_estados +=1;
            ss.str(string());
            ss<<"q"<<cant_estados-1;
            ui->comboBox->addItem(QString::fromStdString(ss.str()));
            ui->comboBox_2->addItem(QString::fromStdString(ss.str()));
            ui->listWidget->addItem(QString::fromStdString(ss.str()));
            ss.str(string());
            ss << "Transición Exitosa: "<< ui->comboBox->currentText().toStdString()<< "--("<< ui->lineEdit->text().toStdString()<< ")-->"<< "q"<<cant_estados-1;
            ui->label2->setText(QString::fromStdString(ss.str()));
            ui->label2->setVisible(true);
        }
    }
    else{
        ui->label2->setText("No ha rellenado todos los campos necesarios.");
        ui->label2->setVisible(true);
    }
}


void MainWindow::on_comboBox_activated(const QString &arg1)
{
    ui->label2->setVisible(false);
}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
    ui->label2->setVisible(false);
}
