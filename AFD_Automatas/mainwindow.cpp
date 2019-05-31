#include "mainwindow.h"
#include "ui_mainwindow.h"

//Inclusiones propias
#include <iostream> //cout y utilidades usadas para debug
#include <sstream>  //uso de stringstream
#include <cstdlib>  //no la hemos usado, probablemente la borremos antes de entregar el trabajo
using namespace std;

//Estructuras
//Lista enlazada de Estados
struct estadoList{
    int val;
    bool e_inicial;
    bool e_final;
    estadoList* next;
}; typedef struct estadoList estado;
//Lista enlazada de Transiciones
struct transicionList{
    int e_salida;
    string sim_transicion;
    int e_llegada;
    transicionList* next;
}; typedef struct transicionList nodo;

//Declaraciones
stringstream ss,ss2,estado_final,estado_inicial;
int cant_estados = 1;
int i, j, e_salida,e_llegada;
estado *listaEstado = nullptr; //Lista de Estados vacía
nodo *listaTransiciones = nullptr; //Lista de Transiciones vacía

//Funciones
void appendToListEstado(estado **l, int val);  //Función utilizada para añadir nodos a una lista de Estados
void appendToList(nodo **l, int num1, string a, int num2); //Función utilizada para añadir nodos a una lista de Transiciones
int valorComboBox(string a);  //Retorna el valor que hay seleccionado en un combobox con el texto "q" seguido de un número
bool transicionExistente(nodo *l,int e_salida,string sim);  //Retorna true si la transición ya existe o false si no existe en la lista de transiciones
bool comprobarPalabra(string s,int pos);
bool stringEntero(string s);  //Comprueba que un string está sólo compuesto de valores enteros
void printListEstado(estado *l);  //DEBUG
void printListTransiciones(nodo *l); //DEBUG

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->label2->setVisible(false);
    ui->frame_2->setVisible(false);
    ui->frame_3->setVisible(false);
    ui->frame_4->setVisible(false);
    appendToListEstado(&listaEstado, 0);
}

MainWindow::~MainWindow(){
    delete ui;
}

//Creación de Estados y Transiciones
void MainWindow::on_pushButton_clicked(){  //Botón ingresar transición
    if(ui->comboBox->currentText() != NULL  //Combobox izquierdo no nulo
            && ui->comboBox_2->currentText() != NULL  //Combobox derecho no nulo
            && !(ui->lineEdit->text().isEmpty())  //Campo de texto no vacío
            && ui->lineEdit->text().toStdString().length() == 1  //Sólo un símbolo en el campo de texto
            && !(transicionExistente(listaTransiciones,valorComboBox(ui->comboBox->currentText().toStdString()),ui->lineEdit->text().toStdString()))){
        e_llegada=valorComboBox(ui->comboBox_2->currentText().toStdString());
        e_salida=valorComboBox(ui->comboBox->currentText().toStdString());
        ss.str(string());
        ss << "(q"<<e_salida<<")--"<<ui->lineEdit->text().toStdString()<<"-->(q"<<e_llegada<<")";
        ui->label2->setText(QString::fromStdString(ss.str()));
        ui->listWidget_2->addItem(QString::fromStdString(ss.str()));
        appendToList(&listaTransiciones,e_salida,ui->lineEdit->text().toStdString(),e_llegada); //Añade una transición a la lista
    }
    else{
        ui->label2->setText("Transición no válida.");
    }
    printListTransiciones(listaTransiciones);  //DEBUG
    printListEstado(listaEstado);  //DEBUG
    ui->label2->setVisible(true);
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
    nuevo->next = nullptr;
    if (*l == nullptr){
        *l = nuevo;
    }
    else{
        nodo *p = *l;
        while (p->next != nullptr)
            p = p->next;

        p->next = nuevo;
    }
}

void appendToListEstado(estado **l, int val){
    estado *nuevo = new estado;
    nuevo->e_final = false;
    nuevo->e_inicial = false;
    nuevo->val = val;
    nuevo->next = nullptr;
    if (*l == nullptr)
        *l = nuevo;
    else{
        estado *p = *l;
        while (p->next != nullptr)
            p = p->next;

        p->next = nuevo;
    }
}

void MainWindow::on_pushButton_2_clicked()  //Boton terminar de ingresar transiciones
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
}

void MainWindow::on_pushButton_3_clicked()  //Boton terminar de ingresar estados finales/iniciales
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

void MainWindow::on_pushButton_4_clicked(){  //Boton comprobar palabra
    ss.str(string());
    ss<<"Palabra rechazada";
    if(ui->lineEdit_3->text() != NULL){
        if(comprobarPalabra(ui->lineEdit_3->text().toStdString(),j)){
            ss.str(string());
            ss << "Palabra aceptada";
        }
        else{
            ss<<"Palabra rechazada";
        }
    }
    else{
        //No ingresó nada
        estado *p = listaEstado;
        for(i =0; i<j; i++){
            p = p->next;
        }
        if(p->e_inicial&&p->e_final){
            ss.str(string());
            ss<<"Palabra aceptada";
        }
    }
    ui->label_15->setText(QString::fromStdString(ss.str()));
}

void MainWindow::on_pushButtonEFinales_clicked(){  //Boton ingresar estados finales
    estado *p=listaEstado;
    while(p!= nullptr && p->val!=valorComboBox(ui->comboBoxEFinal->currentText().toStdString())){
        p=p->next;
    }
    if(p!=nullptr && !(p->e_final)){
        ss.str(string());
        ss<<"q"<<p->val;
        p->e_final=true;
        ui->listWidgetEFinales->addItem(QString::fromStdString(ss.str()));
    }
}

int valorComboBox(string a){
    ss.str(string());
    for(i=1;i<a.length();i++){
        ss<<a[i];
    }
    return stoi(ss.str());
}

void printListEstado(estado *l){  //DEBUG
    estado *p = l;
    cout << "Q = ";
    while(p != nullptr){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

void printListTransiciones(nodo *l){  //DEBUG
    nodo *p = l;
    cout << "Transiciones = ";
    while(p != nullptr){
        cout << p->e_salida <<p->sim_transicion<<p->e_llegada<< " |";
        p = p->next;
    }
    cout << endl;
}

bool transicionExistente(nodo *l,int e_salida,string sim){
    nodo *p = l;
    bool b = false;
    while(p != nullptr){
        if(e_salida==p->e_salida && sim==p->sim_transicion){
            b=true;
        }
        p = p->next;
    }
    return b;
}

bool comprobarPalabra(string s,int pos){
    cout<<"Revisando la palabra: "<<s<<" estado actual: "<<pos<<endl;  //DEBUG
    bool b = false;
    nodo *p = listaTransiciones;
    ss.str(string());
    ss2.str(string());
    ss2<<s[0];
    if(p!=nullptr){
        ss<<p->sim_transicion;
    cout<<"ss.str="<<ss.str()<<"  ss2.str="<<ss2.str()<<" pos="<<pos<<" p->e_salida="<<p->e_salida<<endl;  //DEBUG
    }
    while(p!=nullptr && s.length()>0 && !(p->e_salida==pos && ss.str()==ss2.str())){  //Hacemos que p apunte a la transición que deseamos analizar
        p=p->next;
        ss.str(string());
        if(p!=nullptr){
            ss<<p->sim_transicion;
        }
    }
    if(p!=nullptr){  //Si es que hayamos la transición
        ss.str(string());
        for(i=1;i<s.length();i++){ //Quita el primer símbolo de la palabra
            ss<<s[i];
        }
        if(s.length()>0){
            cout<<"Existe la transición "<<p->e_salida<<p->sim_transicion<<p->e_llegada<<endl;  //DEBUG
            b=comprobarPalabra(ss.str(),p->e_llegada);
        }
        else{  //Comprobar si el estado de llegada al leer este símbolo es estado final
            cout<<"Comprobando si "<<p->e_llegada<<" es estado final"<<endl;  //DEBUG
            estado *q = listaEstado;
            for(i=0;i<pos;i++){
                q=q->next;
            }
            if(q->e_final){
                b=true;
            }
        }
    }
    return b;
}

void MainWindow::on_pushButton_5_clicked(){  //Botón aceptar en estado nuevo
    if(!(ui->lineEdit_2->text().isEmpty())  //Valor de int no vacío
            &&stringEntero(ui->lineEdit_2->text().toStdString())  //Sólo numeros en el numero de estado
            && !(ui->lineEdit->text().isEmpty())  //Campo de texto no vacío
            && ui->lineEdit->text().toStdString().length() == 1  //Sólo un símbolo en el campo de texto
            && !(transicionExistente(listaTransiciones,valorComboBox(ui->comboBox->currentText().toStdString()),ui->lineEdit->text().toStdString()))
            && ui->comboBox->currentText() != NULL  //Combobox izquierdo no nulo
            && cant_estados<=stoi(ui->lineEdit_2->text().toStdString())  //Estado no existente previamente
            ){
        e_llegada=stoi(ui->lineEdit_2->text().toStdString());
        for(i=cant_estados;i<e_llegada+1;i++){  //Crea estados hasta el que se indica
            ss.str(string());
            ss<<"q"<<(i);
            appendToListEstado(&listaEstado,i);
            ui->comboBox->addItem(QString::fromStdString(ss.str()));
            ui->comboBox_2->addItem(QString::fromStdString(ss.str()));
            ui->listWidget->addItem(QString::fromStdString(ss.str()));
        }
        cant_estados=e_llegada+1;
        e_salida=valorComboBox(ui->comboBox->currentText().toStdString());
        ss.str(string());
        ss << "(q"<<e_salida<<")--"<<ui->lineEdit->text().toStdString()<<"-->(q"<<e_llegada<<")";
        ui->label2->setText(QString::fromStdString(ss.str()));
        ui->listWidget_2->addItem(QString::fromStdString(ss.str()));
        appendToList(&listaTransiciones,e_salida,ui->lineEdit->text().toStdString(),e_llegada); //Añade una transición a la lista
        ui->pushButton->setDisabled(false);
        ui->comboBox_2->setDisabled(false);
        ui->comboBox_2->setCurrentIndex(0);
        ui->frame_4->setVisible(false);
    }
    else{
        ui->label2->setText("Transición no válida.");
    }
    printListTransiciones(listaTransiciones);  //DEBUG
    printListEstado(listaEstado);  //DEBUG
    ui->label2->setVisible(true);
}

void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1){ //Selecciona nuevo estado en combobox derecho
    if(ui->comboBox_2->currentText() == "Nuevo Estado"){
        ui->comboBox_2->setDisabled(true);
        ui->pushButton->setDisabled(true);
        ui->frame_4->setVisible(true);
    }
}

bool stringEntero(string s){
    bool b = true;
    i=0;
    while(i<s.length() && b){
        if(s[i]<48||s[i]>57){  //el caracter NO está entre 0 y 9
            b=false;
        }
        i+=1;
    }
    return b;
}
