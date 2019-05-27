#include <iostream>
#include <cstdlib>
using namespace std;

struct estado{
    int val;
    bool e_inicial;
    bool e_final;
};
typedef struct estado estado;
int i,j,cant_estados,cant_simbolos,e_inicial;
bool e_inicial_unico;
string palabra;

void funcion(int estado_actual,int cant_estados,int cant_simbolos,string palabra,estado Q[],int *transiciones);

int main(int argc, char **argv){
    cant_estados=5;
    cant_simbolos=4;
    string E[cant_simbolos];
    estado Q[cant_estados];
    int transiciones[cant_estados][cant_simbolos];
    //Inicia estados
    for (i=0;i<cant_estados;i++){
        Q[i].val=i;
        Q[i].e_inicial=false;
        Q[i].e_final=false;
    }
    //Inicia alfabeto
    for(i=0;i<cant_simbolos;i++){
        E[i]=97+i;
    }
    //Inicia transiciones
    for(i=0;i<cant_estados;i++){
        for(j=0;j<cant_simbolos;j++){
            transiciones[i][j]=-1;
        }
    }
    //Imprime estados
    for(i=0;i<cant_estados;i++){
        if(i==0){
            cout<<"Q = {";
        }
        cout<<" q"<<Q[i].val;
        if(i==cant_estados-1){
            cout<<" }"<<endl;
        }
    }
    //Imprime alfabeto
    for(i=0;i<cant_simbolos;i++){
        if(i==0){
            cout<<"E = {";
        }
        cout<<" "<<E[i];
        if(i==cant_simbolos-1){
            cout<<" }"<<endl;
        }
    }
    transiciones[0][0]=0;
    //Imprime función de transición transiciones
    for(i=0;i<cant_estados;i++){
        if(i==0){
            cout<<"Fúnción de transición:"<<endl;
            cout<<"    ";
            for(j=0;j<cant_simbolos;j++){
                cout<<E[j]<<"  ";
            }
            cout<<endl;
        }
        cout<<"q"<<Q[i].val<<" ";
        for(j=0;j<cant_simbolos;j++){
            cout<<transiciones[i][j]<<" ";
        }
        cout<<endl;
    }    

    e_inicial=0;
    Q[e_inicial].e_inicial=true;
    Q[e_inicial].e_final=true;
    palabra="abcdef";
    cout<<"La palabra es: "<<palabra<<" de largo "<<palabra.length()<<endl;
    funcion(Q[e_inicial].val,cant_estados,cant_simbolos,palabra,Q,*transiciones);
}

void funcion(int estado_actual,int cant_estados,int cant_simbolos,string palabra,estado Q[],int *transiciones){
    int i;
    if(palabra.length()==0){
        if(Q[estado_actual].e_final){
            cout<<"La palabra es aceptada por el AFD"<<endl;
        }
        else{
            cout<<"La palabra NO es aceptada por el AFD"<<endl;
        }
    }
    else{
        i=palabra[0]-97;
        if(transiciones[cant_estados*estado_actual + i]!=-1){
            funcion(transiciones[cant_estados*estado_actual + i],cant_estados,cant_simbolos,palabra.substr(1,palabra.length()),Q,transiciones);
        }
        else{
            cout<<"La palabra NO es aceptada por el AFD"<<endl;
        }
    }
}