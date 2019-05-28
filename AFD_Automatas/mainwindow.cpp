#include "mainwindow.h"
#include "ui_mainwindow.h"

// Inclusiones propias //
#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

// Estructuras //
//Lista enlazada de Estados
struct estadoList{
    int val;
    bool e_inicial;
    bool e_final;
    estadoList* next;
};
typedef struct estadoList estado;
//Lista enlazada de Transiciones
struct transicionList{
    int e_salida;
    string sim_transicion;
    int e_llegada;
    transicionList* next;
}; typedef struct transicionList nodo;

//Declaraciones //
stringstream ss;
int cant_estados = 1;
int i, j, e_salida,e_llegada;
QString campotexto;
stringstream estado_final;
stringstream estado_inicial;
estado *listaEstado = NULL; //Lista de Estados vacía
nodo *lista = NULL; //Lista de Transiciones vacía
// Funciones //
void appendToListEstado(estado **l, bool e_inicial, bool e_final, int val);  //Función utilizada para añadir nodos a una lista de Estados
void appendToList(nodo **l, int num1, string a, int num2); //Función utilizada para añadir nodos a una lista de Transiciones
int valorComboBox(string a);  //Retorna el valor que hay seleccionado en un combobox con el texto "q" seguido de un número

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label2->setVisible(false);
    ui->frame_2->setVisible(false);
    ui->frame_3->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Creación de Estados y Transiciones
void MainWindow::on_pushButton_clicked(){
    if(ui->comboBox->currentText() != NULL && ui->comboBox_2->currentText() != NULL && !(ui->lineEdit->text().isEmpty())){
        //Si en el combobox derecho se selecciona nuevo estado
        if(ui->comboBox_2->currentText() == "Nuevo Estado"){
            cant_estados +=1;
            ss.str(string());
            ss<<"q"<<cant_estados-1;
            ui->comboBox->addItem(QString::fromStdString(ss.str()));
            ui->comboBox_2->addItem(QString::fromStdString(ss.str()));
            ui->listWidget->addItem(QString::fromStdString(ss.str()));
            e_llegada = cant_estados-1;  //No es necesario obtener el valor desde el combobox derecho ya que es un estado nuevo
        }
        //Si en el combobox derecho se selecciona un estado existente
        else{
            e_llegada=valorComboBox(ui->comboBox_2->currentText().toStdString());
        }
        //Aplica para ambos tipos de transición
        e_salida=valorComboBox(ui->comboBox->currentText().toStdString()); //Valor del combobox izquierdo
        ss.str(string());
        ss << "Transición Exitosa: q"<<e_salida<<"--("<<ui->lineEdit->text().toStdString()<<")-->q"<<e_llegada;
        ui->label2->setText(QString::fromStdString(ss.str()));
        ui->label2->setVisible(true);
        ui->listWidget_2->addItem(QString::fromStdString(ss.str()));
        appendToList(&lista,e_salida,ui->lineEdit->text().toStdString(),e_llegada); //Añade un nodo a la lista
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

void appendToList(nodo **l, int num1, string a, int num2){
    nodo *nuevo = new nodo;
    nuevo->e_salida = num1;
    nuevo->sim_transicion = a;
    nuevo->e_llegada = num2;
    nuevo->next = NULL;
    if (*l == nullptr)
        *l = nuevo;
    else{
        nodo *p = *l;
        while (p->next != nullptr)
            p = p->next;

        p->next = nuevo;
    }
}

void appendToListEstado(estado **l, bool e_inicial, bool e_final, int val){
    estado *nuevo = new estado;
    nuevo->e_final = false;
    nuevo->e_inicial = false;
    nuevo->val = val;
    nuevo->next = NULL;
    if (*l == nullptr)
        *l = nuevo;
    else{
        estado *p = *l;
        while (p->next != nullptr)
            p = p->next;

        p->next = nuevo;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->frame->setDisabled(1);
    ui->pushButton->setDisabled(1);
    ui->frame_2->setVisible(true);
    for(i=0;i<cant_estados;i++){
        ss.str(string());
        ss<<"q"<<i;
        ui->comboBoxEInicial->addItem(QString::fromStdString(ss.str()));
        ui->comboBoxEFinal->addItem(QString::fromStdString(ss.str()));
    }
   for(i = 0; i< cant_estados; i++){
       appendToListEstado(&listaEstado, false, false, i);
   }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->frame_2->setDisabled(1);
    ui->frame_3->setVisible(true);
    estado_inicial<<ui->comboBoxEInicial->currentText().toStdString();
    ui->listWidgetEIniciales->addItem(QString::fromStdString(estado_inicial.str()));
    j=valorComboBox(ui->comboBoxEInicial->currentText().toStdString());
    estado *p = listaEstado;
    for(i =0; i<j; i++){
        p = p->next;
    }
    p->e_inicial= true;

}

void MainWindow::on_pushButtonEFinales_clicked()
{
    estado_final <<ui->comboBoxEFinal->currentText().toStdString();
    ui->listWidgetEFinales->addItem(QString::fromStdString(estado_final.str()));
    stringstream().swap(estado_final);
    j=valorComboBox(ui->comboBoxEFinal->currentText().toStdString());
    estado *p = listaEstado;
    for(i =0; i<j; i++){
        p = p->next;
    }
    p->e_final = true;

}

int valorComboBox(string a){
    ss.str(string());
    for(i=1;i<a.length();i++){
        ss<<a[i];
    }
    return stoi(ss.str());
}
