/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <memory>
#include "PunterosGenericos.h"
#include "MuestraPunteros.h"
using namespace std;
#define INCREMENTO 5

char* leerCadena(ifstream& arch){
    char buffer[100],*nombre;
    arch.getline(buffer,100,',');
    nombre = new char [strlen(buffer)+1];
    strcpy(nombre,buffer);
    return nombre;
}
void aumentarMemoria(void **&ptr,int &i,int &capacidad){
    capacidad += INCREMENTO;
    if(ptr == nullptr){
        ptr = new void *[capacidad]{};
        i++;
    }
    else{
        void **aux = new void *[capacidad]{};
        for(int p=0;p<i;p++)aux[p] = ptr[p];
        delete ptr;
        ptr = aux;
    }
}
void* registroProd(ifstream& arch){
    int *codigo = new int,*cantidad = new int;
    char *descripcion;
    double *precio = new double;
    void **registro = new void *[5]{};
    arch>>*codigo;
    if(arch.eof())return nullptr;
    arch.get();
    descripcion = leerCadena(arch);
    arch>>*precio;
    arch.get();
    arch>>*cantidad;
    
    registro[0] = codigo;
    registro[1] = descripcion;
    registro[2] = precio;
    registro[3] = cantidad;
    return registro;
}
void cargaProductos(void *&productos){
    ifstream arch("productos2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: productos2.csv"<<endl;
        exit(1);
    }
    void **auxProductos,*registro;
    int i=0,capacidad=0;
    auxProductos = nullptr;
    
    while(true){
        registro = registroProd(arch);
        if(arch.eof())break;
        if(i == capacidad)aumentarMemoria(auxProductos,i,capacidad);
        auxProductos[i-1] = registro;
        i++;
    }
    productos = auxProductos;
    imprimeproductos(productos);
}

void* registroPed(ifstream& arch){
    int *codigo = new int,*cantidad = new int,*fecha = new int,*dni = new int;
    int dd,mm,aa;
    char *descripcion,c,*estado = new char[2]{};
    void **registro = new void *[7]{};
    
    arch>>*codigo>>c;
    if(arch.eof())return nullptr;
    descripcion = leerCadena(arch);
    arch>>*cantidad>>c;
    arch>>*dni>>c;
    arch>>dd>>c>>mm>>c>>aa;
    *fecha = aa*10000 + mm*100 + dd;
    *estado = 'N';
    
    registro[0] = codigo;
    registro[1] = descripcion;
    registro[2] = cantidad;
    registro[3] = dni;
    registro[4] = fecha;
    registro[5] = estado;
//    cout<<estado<<" "<<*estado<<" "<<estado[0]<<endl;
    return registro;
}
void cargaPedidos(void *&pedidos){
    ifstream arch("pedidos2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: pedidos2.csv"<<endl;
        exit(1);
    }    
    void **auxPedidos,*registro;
    int i=0,capacidad=0;
    auxPedidos = nullptr;
    while(true){
        registro = registroPed(arch);
        if(arch.eof())break;
        if(i == capacidad)aumentarMemoria(auxPedidos,i,capacidad);
        auxPedidos[i-1] = registro;
        i++;
    }
    pedidos = auxPedidos;
    imprimepedidos(pedidos);
    ofstream archRep("ReportePrueba.txt",ios::out);
    void **aterrizaje1 = (void**)pedidos;
    for(int i=0;aterrizaje1[i];i++){
        void **aterrizaje2 = (void**)aterrizaje1[i];
        int *codigo = (int*)aterrizaje2[0];
        char *descripcion = (char*)aterrizaje2[1];
        int *cantidad = (int*)aterrizaje2[2];
        int *dni = (int*)aterrizaje2[3];
        int *fecha = (int*)aterrizaje2[4];
        char *tipo = (char*)aterrizaje2[5];
        archRep<<setw(15)<<left<<*codigo<<setw(40)<<descripcion<<right<<setw(20)
                <<*cantidad<<left<<setw(7)<<' '<<setw(15)<<*dni<<setw(10)
                <<*fecha<<*tipo<<endl;
    }
}

int buscarProducto(void *aterrizaje2_ped,void **aterrizaje1_prod){
    int *codigo = (int*)aterrizaje2_ped;
    for(int i=0;aterrizaje1_prod[i];i++){
        void **aterrizaje2_prod = (void**)aterrizaje1_prod[i];
        int *codVerifica = (int*)aterrizaje2_prod[0];
        if(*codigo == *codVerifica)return i;
    }
    return -1;
}
void actualizarEstadosPed(void *productos,void *pedidos){
    void **aterrizaje1_ped = (void**)pedidos;
    void **aterrizaje1_prod = (void**)productos;
    int pos;
    
    for(int i=0;aterrizaje1_ped[i];i++){
        void **aterrizaje2_ped = (void**)aterrizaje1_ped[i];
        pos = buscarProducto(aterrizaje2_ped[0],aterrizaje1_prod);
        if(pos!=-1){
            void **aterrizaje2_prod = (void**)aterrizaje1_prod[pos];
            int *cantidadPedida = (int*)aterrizaje2_ped[2];
            int *cantidaTtotal = (int*)aterrizaje2_prod[3];
            if(*cantidaTtotal-*cantidadPedida>=0){
                *((char*)aterrizaje2_ped[5]) = 'A';
                *((int*)aterrizaje2_prod[3]) -= *cantidadPedida; 
            }
        } 
    }
}
char *leerNombre(ifstream& arch){
    char buffer[100],*nombre;
    arch.getline(buffer,100,'\n');
    nombre = new char [strlen(buffer)+1];
    strcpy(nombre,buffer);
    return nombre;    
}
void *registroCli(ifstream& arch){
    int *codigo = new int;
    char *nombre;
    void **registro = new void *[4]{};
    
    arch>>*codigo;
    if(arch.eof())return nullptr;
    arch.get();
    nombre = leerNombre(arch);
    
    registro[0] = codigo;
    registro[1] = nombre;
    return registro;
}
void *registroClixPed(void **aterrizaje2_ped){
    int *fecha = (int*)aterrizaje2_ped[4];
    int *codigo = (int*)aterrizaje2_ped[0];
    int *cantidad = (int*)aterrizaje2_ped[2];
    char *descripcion = (char*)aterrizaje2_ped[1];
    void **registro = new void *[5]{};
    
    registro[0] = fecha;
    registro[1] = codigo;
    registro[2] = descripcion;
    registro[3] = cantidad;
    return registro;
}
void guardarPedido(void **&aterrizaje3_cli,void **aterrizaje2_ped,int &i,
                    int &capacidad){
    void *reg;
    reg = registroClixPed(aterrizaje2_ped);
    if(i == capacidad)aumentarMemoria(aterrizaje3_cli,i,capacidad);
    aterrizaje3_cli[i-1] = reg;
    i++;
}
void registrarPedidos(void *auxClientes,void *pedidos,int &i,int &capacidad){
    void **aterrizaje2_cli = (void**)auxClientes;
    void **aterrizaje3_cli = (void**)aterrizaje2_cli[2];
    void **aterrizaje1_ped = (void**)pedidos;
    
    for(int j=0;aterrizaje1_ped[j];j++){
        void **aterrizaje2_ped = (void**)aterrizaje1_ped[j];
        int *dniCli = (int*)aterrizaje2_cli[0];
        int *dniPed = (int*)aterrizaje2_ped[3];
        char *estado = (char*)aterrizaje2_ped[5];
        if(*dniCli == *dniPed){
            if(*estado == 'A')guardarPedido(aterrizaje3_cli,
                                    aterrizaje2_ped,i,capacidad);
        } 
    }
    aterrizaje2_cli[2] = aterrizaje3_cli;
}
void procesaClientes(void *productos,void *pedidos,void *&clientes){
    actualizarEstadosPed(productos,pedidos);
    ifstream arch("clientes2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: clientes2.csv"<<endl;
        exit(1);
    }
    int numDat[100]{},cap[100]{};
    int i=0,capacidad=0;
    void *reg,**auxClientes;
    while(true){
        reg = registroCli(arch);
        if(arch.eof())break;
        if(i == capacidad)aumentarMemoria(auxClientes,i,capacidad);
        auxClientes[i-1] = reg;
        registrarPedidos(auxClientes[i-1],pedidos,numDat[i-1],cap[i-1]);
        i++;
    }
    clientes = auxClientes;
}

void imprimirPedidos(void **aterrizaje2,ofstream& arch){
    void **aterrizaje3 = (void**)aterrizaje2[2];
    for(int i=0;aterrizaje3[i];i++){
        void **aterrizaje4 = (void**)aterrizaje3[i];
        int *fecha = (int*)aterrizaje4[0];
        int *codigo = (int*)aterrizaje4[1];
        char *descripcion = (char*)aterrizaje4[2];
        int *cantidad = (int*)aterrizaje4[3];
        arch<<setw(20)<<left<<*fecha<<setw(20)<<*codigo<<setw(40)<<
                descripcion<<right<<setw(20)<<*cantidad<<endl;
    }
}
void imprimeReporte(void *clientes){
    ofstream arch("ReporteDePedidos.txt",ios::out);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: ReporteDePedidos.txt"<<endl;
        exit(1);
    }
    void **aterrizaje1 = (void**)clientes;
    for(int i=0;aterrizaje1[i];i++){
        void **aterrizaje2 = (void**)aterrizaje1[i];
        if(aterrizaje2[2]!=nullptr){
            imprimeLinea('=',100,arch);
            arch<<"PEDIDOS ATENDIDOS POR CLIENTE: "<<endl;
            imprimeLinea('=',100,arch);
            arch<<setw(20)<<left<<"DNI"<<"Nombre"<<endl;
            int *dni = (int*)aterrizaje2[0];
            char *nombre = (char*)aterrizaje2[1];
            arch<<setw(20)<<left<<*dni<<nombre<<endl;
            imprimeLinea('-',100,arch);
            arch<<"Pedidos atendidos: "<<endl;
            imprimeLinea('-',100,arch);
            arch<<setw(20)<<left<<"Fecha"<<setw(20)<<"Codigo"<<setw(40)<<
                "Descripcion del Producto"<<right<<setw(20)<<"Cantidad"<<endl;
            imprimirPedidos(aterrizaje2,arch);
            arch<<endl;
        }
    }
}
void imprimeLinea(char c,int n,ofstream& arch){
    for(int i=0;i<n;i++)arch<<c;
    arch<<endl;
}