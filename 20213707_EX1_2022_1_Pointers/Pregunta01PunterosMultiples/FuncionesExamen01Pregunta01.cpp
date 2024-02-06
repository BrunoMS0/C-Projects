/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * Author: Bruno Monzén Sullón
 * codigo: 20213707
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "ClientesPreg1.h"
#include "FuncionesExamen01Pregunta01.h"
using namespace std;
#define INCREMENTO 5

char* leerCadena(ifstream& arch){
    char buffer[100],*nombre;
    arch.getline(buffer,100,',');
    nombre = new char [strlen(buffer)+1];
    strcpy(nombre,buffer);
    return nombre;
}
void leerDatos(int &codigo,int &descuento,int &cantidad,int &precioUni,
                int &stock,int &dni,int &fecha,char *&descripcion,
                ifstream& arch){
    arch>>codigo;
    if(arch.eof())return;
    arch.get();
    descripcion = leerCadena(arch);
    int entero,decimal,numero;
    char c;
    arch>>entero>>c>>decimal;
    numero = entero*100 + decimal;
    if(arch.get()=='%'){
        descuento = numero;
        arch.get();
        arch>>entero>>c;
        if(c=='.'){
            arch>>decimal;
            numero = entero*100 + decimal;
            arch.get();
        }
        else{
            numero = entero;
        }
    }
    else descuento = -1;
    cantidad = numero;
    
    arch>>entero>>c;
        if(c=='.'){
            arch>>decimal;
            numero = entero*100 + decimal;
            arch.get();
        }
        else{
            numero = entero;
        }
    precioUni = numero;

    
    arch>>entero>>c;
        if(c=='.'){
            arch>>decimal;
            numero = entero*100 + decimal;
            arch.get();
        }
        else{
            numero = entero;
        }
    stock = numero;
    
    arch>>dni;
    arch.get();
    int aa,dd,mm;
    arch>>dd>>c>>mm>>c>>aa;
    fecha = aa*10000 + mm*100 + dd;
}
int buscarProducto(int codigo,int **buffer_Inf){
    int *aterrizaje2;
    for(int i=0;buffer_Inf[i];i++){
        aterrizaje2 = buffer_Inf[i];
        if(codigo==aterrizaje2[0])return i;
    }
    return -1;
}
void agregarPedidos(char **buffer_Desc,int **buffer_Inf,int codigo,
                    int descuento,int precioUni,int stock,char *descripcion,
                    int j){
    buffer_Desc[j] = descripcion;
    
    buffer_Inf[j] = new int [5]{};
    int *auxInf = buffer_Inf[j];
    auxInf[0] = codigo;
    if(descuento!=-1)auxInf[1] = descuento;
    auxInf[2] = precioUni;
    auxInf[3] = stock;
}
void pasarPedidos(char **buffer_Desc,int **buffer_Inf,int **buffer_Todo,
                  char **&pro_Descripcion,int **&pro_Informacion,
                  int **&ped_Todo,int i,int j){
    pro_Descripcion = new char *[j+1]{};
    pro_Informacion = new int *[j+1]{};
    ped_Todo = new int *[i+1]{};
    for(int p=0;p<j;p++){
        pro_Descripcion[p] = buffer_Desc[p];
        pro_Informacion[p] = buffer_Inf[p];
    }
    for(int p=0;p<i;p++){
        ped_Todo[p] = buffer_Todo[p];
    }
}
void agregarCliente(int **buffer_Todo,int dni,int fecha,int cantidad,
                    int codigo,int i){
    buffer_Todo[i] = new int [5]{};
    int *aux = buffer_Todo[i];
    
    aux[0] = dni;
    aux[1] = fecha;
    aux[2] = cantidad;
    aux[3] = codigo;
}
void CargarProductosPedido(int **&pro_Informacion,char **&pro_Descripcion,
                            int **&ped_Todo,const char *nombre_archivo){
    ifstream arch(nombre_archivo,ios::in);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: "<<nombre_archivo<<endl;
        exit(1);
    }
    int *buffer_Inf[200]{},*buffer_Todo[200]{};
    char *buffer_Desc[200]{};
    int codigo,descuento,cantidad,precioUni,stock,dni,fecha;
    char *descripcion;
    int i=0,j=0,pos;
    while(true){
        leerDatos(codigo,descuento,cantidad,precioUni,stock,dni,fecha,
                    descripcion,arch);
        if(arch.eof())break;
        pos = buscarProducto(codigo,buffer_Inf);
        if(pos==-1){
            agregarPedidos(buffer_Desc,buffer_Inf,codigo,descuento,
                            precioUni,stock,descripcion,j);
            j++;
        }
        agregarCliente(buffer_Todo,dni,fecha,cantidad,codigo,i);
        i++;
    }
    pasarPedidos(buffer_Desc,buffer_Inf,buffer_Todo,pro_Descripcion,
            pro_Informacion,ped_Todo,i,j);
}

void PruebaProductosPedido(int **pro_Informacion,char **pro_Descripcion,
                            int **ped_Todo,const char *nombre_archivo){
    ofstream arch(nombre_archivo,ios::out);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: "<<nombre_archivo<<endl;
        exit(1);
    }
    for(int i=0;pro_Informacion[i];i++){
        int *auxInf = pro_Informacion[i];
        char *auxDesc;
        arch<<setw(50)<<left<<pro_Descripcion[i]<<setw(10)<<auxInf[0]<<setw(10)
                <<auxInf[1]<<setw(10)<<auxInf[2]<<setw(10)<<auxInf[3]<<endl;
    }
    arch<<endl<<endl;
    for(int i=0;ped_Todo[i];i++){
        int *auxTodo = ped_Todo[i];
        arch<<setw(10)<<left<<auxTodo[0]<<setw(10)<<auxTodo[1]<<setw(10)
                <<auxTodo[2]<<setw(10)<<auxTodo[3]<<endl;
    }
}

int verifica(int **ped_Todo,int i,int izq){
    int *auxTodo_1 = ped_Todo[i];
    int *auxTodo_2 = ped_Todo[izq];
    
    if((auxTodo_1[1]<auxTodo_2[1]) || (auxTodo_1[1]==auxTodo_2[1] && 
            auxTodo_1[0]<auxTodo_2[0]))return 1;
    return 0;
}
void cambiar(int **ped_Todo,int i,int j){
    int *auxTodo = ped_Todo[i];
    ped_Todo[i] = ped_Todo[j];
    ped_Todo[j] = auxTodo;
}
void ordenamiento(int **ped_Todo,int izq,int der){
    int limite,pos;
    if(izq>=der)return;
    limite = izq;
    pos = (izq+der)/2;
    cambiar(ped_Todo,izq,pos);
    limite = izq;
    for(int i=izq+1;i<=der;i++){
        if(verifica(ped_Todo,i,izq)){
            limite++;
            cambiar(ped_Todo,limite,i);
        }
    }
    cambiar(ped_Todo,izq,limite);
    ordenamiento(ped_Todo,izq,limite-1);
    ordenamiento(ped_Todo,limite+1,der);
}
void ordenarPedidos(int **ped_Todo){
    int numDat=0;
    while(ped_Todo[numDat])numDat++;
    ordenamiento(ped_Todo,0,numDat-1);
}

void aumentarMemoriaPedido(int *&auxDni,int &i,int &capacidad){
    capacidad += INCREMENTO;
    if(auxDni == nullptr){
        auxDni = new int [capacidad*3]{};
        i++;
    }
    else{
        int *aux;
        aux = new int [capacidad*3]{};
        for(int p=0;p<i*3;p++)aux[p] = auxDni[p];
        delete auxDni;
        auxDni = aux;
    }
}
void agregarPedido(int *ped_Todo,int &i,int &capacidad,int **pro_Informacion,
                    int *&auxDni){
    int pos;
    int codProd = ped_Todo[3];
    int cantidadPedida = ped_Todo[2];
    int *aterrizaje1_Inf,stock,stockFinal;
    pos = buscarProducto(codProd,pro_Informacion);
    if(pos!=-1){
        aterrizaje1_Inf = pro_Informacion[pos];
        stock = aterrizaje1_Inf[3];
        stockFinal = stock - cantidadPedida;
        if(stockFinal>=0){
            aterrizaje1_Inf[3] = stockFinal;
            if(i == capacidad)aumentarMemoriaPedido(auxDni,i,capacidad);
            auxDni[3*(i-1)] = ped_Todo[1]; 
            auxDni[3*(i-1)+1] = ped_Todo[2]; 
            auxDni[3*(i-1)+2] = ped_Todo[3]; 
            i++;
        }
    }    
}
void asignarPedidos(int ***cli_DniTelPed,int** pro_Informacion,int **ped_Todo){
    int numDat[150]{},capacidad[150]{};
    int **auxDni,pos;
    for(int i=0;cli_DniTelPed[i];i++){
        auxDni = cli_DniTelPed[i];
        for(int j=0;ped_Todo[j];j++){
            int *dni = auxDni[0];
            int *pedDni = ped_Todo[j];
            if(dni[0] == pedDni[0]){
                agregarPedido(ped_Todo[j],numDat[i],capacidad[i],
                                pro_Informacion,auxDni[2]);
            }
        }
        cli_DniTelPed[i] = auxDni;
    }
}