/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * Author: Luis Bruno Monzén Sullón
 * Codigo: 20213707
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "MuestraPunteros.h"
#include "PunterosGenericos.h"
using namespace std;
#define MAX 100
char* leerCadena(ifstream& arch){
    char buffer[100],*nombre;
    arch.getline(buffer,100,',');
    nombre = new char [strlen(buffer)+1];
    strcpy(nombre,buffer);
    return nombre;
}
void* registroProd(ifstream& arch){
    char *codigo;
    char *nombre;
    double *precio = new double;
    char *tipo = new char;
    void **registro;
    registro = new void *[5]{};
    codigo = leerCadena(arch);
    if(arch.eof())return nullptr;
    nombre = leerCadena(arch);
    arch>>*precio;
    arch.get();
    arch>>*tipo;
    arch.get();
    registro[0] = codigo;
    registro[1] = nombre;
    registro[2] = precio;
    registro[3] = tipo;
    return registro;
}
void cargaproductos(void *&productos){
    ifstream arch("Productos2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: Productos2.csv"<<endl;
        exit(1);
    }
    void *buffer[200]{},**auxProductos;
    int i=0;
    while(true){
        buffer[i] = registroProd(arch);
        if(arch.eof())break;
        i++;
    }
    i++;
    auxProductos = new void *[i];
    for(int p=0;p<i;p++)auxProductos[p] = buffer[p];
    productos = auxProductos;
}

void *registroCli(ifstream& arch){
    int *dni = new int;
    char *nombre;
    double *linea = new double;
    arch>>*dni;
    if(arch.eof())return nullptr;
    arch.get();
    nombre = leerCadena(arch);
    while(arch.get()!=',');
    arch>>*linea;
    
    void **registro = new void *[5]{};
    registro[0] = dni;
    registro[1] = nombre;
    registro[3] = linea;
    return registro;
}
void cargaclientes(void *&clientes){
    ifstream arch("Clientes2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: Clientes2.csv"<<endl;
        exit(1);
    }    
    void *buffer[200]{},**auxClientes;
    int i=0;
    while(true){
        buffer[i] = registroCli(arch);
        if(arch.eof())break;
        i++;
    }
    i++;
    auxClientes = new void *[i];
    for(int p=0;p<i;p++)auxClientes[p] = buffer[p];
    clientes = auxClientes;
}

void leerRegistros(char *&codProd,int *&dni,int *&cantidad,ifstream& arch){
    codProd = leerCadena(arch);
    dni = new int;
    cantidad = new int;
    arch>>*dni;
    if(arch.eof())return;
    arch.get();
    arch>>*cantidad;
    arch.get();
}
int buscarCliente(void *clientes,int dni){
    void **aterrizaje1 = (void**)clientes;
    for(int i=0;aterrizaje1[i];i++){
        void **aterrizaje2 = (void**)aterrizaje1[i];
        int *dniCli = (int*)aterrizaje2[0];
        if(dni == *dniCli)return i;
    }
    return -1;
}
int buscarProducto(void *productos,char *codProd){
    void **aterrizaje1 = (void**)productos;
    for(int i=0;aterrizaje1[i];i++){
        void **aterrizaje2 = (void**)aterrizaje1[i];
        char *codigo = (char*)aterrizaje2[0];
        if(strcmp(codProd,codigo)==0)return i;
    }
    return -1;
}
void* registroPedido(char *codProd,int *cantidad,double *precio){
    double *totalPedido = new double;
    *totalPedido = (*cantidad)*(*precio);
    void **registro = new void *[4]{};
    registro[0] = codProd;
    registro[1] = cantidad;
    registro[2] = totalPedido;
    return registro;
}
void asignarProducto(void **aterrizaje2,void *productos,int posCli,char *codProd,
                        int *cantidad,int posProd,int &numDat){
    void **aterrizaje3;
    if(numDat==0){
        void **aux;
        aux = new void *[100]{};
        aterrizaje2[2] = aux;
    }
    aterrizaje3 = (void**)aterrizaje2[2];
    
    void **aterrizajeProd1 = (void**)productos;
    void **aterrizajeProd2 = (void**)aterrizajeProd1[posProd];
    char *c;
    c = (char*)aterrizajeProd2[3];
    
    double *lineaCli = new double;
    double *precio = new double;
    double lineaTotalProd;
    precio = (double*)aterrizajeProd2[2];
    
    if(*c=='N'){
        aterrizaje3[numDat] = registroPedido(codProd,cantidad,precio);
        numDat++;
    }
    else{
        lineaCli = (double*)aterrizaje2[3];
        lineaTotalProd = (*precio)*(*cantidad);
        if(*lineaCli-lineaTotalProd>0){
            aterrizaje3[numDat] = registroPedido(codProd,cantidad,precio);
            numDat++;
            *(double*)aterrizaje2[3] -= lineaTotalProd;
        }
        
    }
    
}
void agregarPedido(void *clientes,void *productos,int pos,char *codProd,
                    int *dni,int *cantidad,int *numDat){
    void **aterrizaje1 = (void**)clientes;
    void **aterrizaje2 = (void**)aterrizaje1[pos];
    int posProd = buscarProducto(productos,codProd);
    if(posProd!=-1){
        asignarProducto(aterrizaje2,productos,pos,codProd,cantidad,posProd,
                        numDat[pos]);
    }
}
void liberar(void *&aterrizaje2,int numDat){
    void **aterrizaje3 = (void**)aterrizaje2;
    numDat++;
    void **aux = new void *[numDat]{};
    for(int p=0;p<numDat;p++)aux[p] = aterrizaje3[p];
    delete aterrizaje3;
    aterrizaje2 = aux;
}
void liberarEspacios(void *clientes,int *numDat){
    void **aterrizaje1 = (void**)clientes;
    for(int i=0;aterrizaje1[i];i++){
        void **aterrizaje2 = (void**)aterrizaje1[i];
        if(numDat[i]!=0)liberar(aterrizaje2[2],numDat[i]);
    }
}
void cargapedidos(void *productos,void *clientes){
    ifstream arch("Pedidos2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: Pedidos2.csv"<<endl;
        exit(1);
    }   
    int pos;
    int numDat[200]{};
    char *codProd;
    int *dni;
    int *cantidad;
    while(true){
        leerRegistros(codProd,dni,cantidad,arch);
        if(arch.eof())break;
        pos = buscarCliente(clientes,*dni);
        if(pos!=-1){
            agregarPedido(clientes,productos,pos,codProd,dni,cantidad,
                            numDat);
        }
    }
    liberarEspacios(clientes,numDat);
    imprimerepfinal(clientes);
}

void imprimirProd(void *aterrizaje2,ofstream& arch){
    void **aterrizaje3 = (void**)aterrizaje2;
    for(int i=0;aterrizaje3[i];i++){
        void **aterrizaje4 = (void**)aterrizaje3[i];
        char *codigo = (char*)aterrizaje4[0];
        int *cantidad = (int*)aterrizaje4[1];
        double *total = (double*)aterrizaje4[2];
        arch<<left<<setw(15)<<codigo<<setw(15)<<*cantidad<<*total<<endl;
    }
}
void imprimereporte(void *clientes){
    ofstream arch("ReporteFinal.txt",ios::out);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: ReporteFinal.txt"<<endl;
        exit(1);
    }      
    void **aterrizaje1 = (void**)clientes;
    
    for(int i=0;aterrizaje1[i];i++){
        void **aterrizaje2 = (void**)aterrizaje1[i];
        if(aterrizaje2[2]!=nullptr){
            imprimeLinea(arch,'=',MAX);
            arch<<left<<setw(20)<<"DNI"<<setw(40)<<"Nombre"<<"Credito"<<endl;
        
            char *nombre = (char*)aterrizaje2[1];
            int *dni = (int*)aterrizaje2[0];
            double *credito = (double*)aterrizaje2[3];
        
            arch<<left<<setw(20)<<*dni<<setw(40)<<nombre<<*credito<<endl;
        
            imprimeLinea(arch,'-',MAX);
            arch<<"Pedidos atendidos"<<endl;
            imprimeLinea(arch,'-',MAX);
            arch<<left<<setw(15)<<"Codigo"<<setw(15)<<"Cantidad"<<"Total"<<endl;
            imprimeLinea(arch,'-',MAX);
            imprimirProd(aterrizaje2[2],arch);
        
            arch<<endl;
        }
    }
}
void imprimeLinea(ofstream& arch,char c,int n){
    for(int i=0;i<n;i++){
        arch<<c;
    }
    arch<<endl;
}