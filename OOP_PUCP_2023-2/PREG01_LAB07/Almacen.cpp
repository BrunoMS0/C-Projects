/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Almacen.cpp
 * Author: Luis Bruno Monzén Sullón
 * Código: 20213707
 * 
 * Created on 3 de noviembre de 2023, 07:59 AM
 */

#include "Almacen.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#define MAX 170
Almacen::Almacen() {
    cantidad_ordenes = 0;
}

Almacen::Almacen(const Almacen& orig) {
}

Almacen::~Almacen() {
}

void Almacen::SetCantidad_ordenes(int cantidad_ordenes) {
    this->cantidad_ordenes = cantidad_ordenes;
}

int Almacen::GetCantidad_ordenes() const {
    return cantidad_ordenes;
}

void Almacen::cargar_pedidos(){
    ifstream arch("Pedidos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: Pedidos.csv"<<endl;
        exit(1);
    }
    char tipo;
    cantidad_ordenes = 0;
    while(true){
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        switch(tipo){
            case 'A':
                ordenes[cantidad_ordenes].asignarAlta(arch);
                break;
            case 'M':
                ordenes[cantidad_ordenes].asignarMedia(arch);
                break;
            case 'B':   
                ordenes[cantidad_ordenes].asignarBaja(arch);
                break;
        }
        ordenes[cantidad_ordenes].lee(arch);
        cantidad_ordenes++;
    }
}

void Almacen::imprimirLinea(ofstream& arch,char c,int n)const{
    for(int i=0;i<n;i++)arch<<c;
    arch<<endl;
}

void Almacen::imprimir_ordenes_venta(){
    ofstream arch("Reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: Reporte.txt"<<endl;
        exit(1);
    }
    arch<<right<<setw(80)<<"REPORTE DE PEDIDOS"<<endl;
    imprimirLinea(arch,'=',MAX);
    arch<<left<<setw(20)<<"Codigo Pedido"<<setw(20)<<"DNI Cliente"<<setw(20)
            <<"Subtotal"<<setw(20)<<"Fecha"<<setw(20)<<"Estado"<<setw(20)<<
            "Total"<<setw(20)<<"Prioridad"<<"Recargo/Estado/Dias en espera"
            <<endl;
    imprimirLinea(arch,'=',MAX);
    for(int i=0;i<cantidad_ordenes;i++){
        ordenes[i].imprime(arch);
    }
}
