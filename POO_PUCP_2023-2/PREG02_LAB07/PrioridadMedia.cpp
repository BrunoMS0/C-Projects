/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrioridadMedia.cpp
 * Author: Luis Bruno Monzén Sullón
 * Código: 20213707
 * Created on 3 de noviembre de 2023, 07:59 AM
 */

#include "PrioridadMedia.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
PrioridadMedia::PrioridadMedia() {
    descripcion = nullptr;
    nueva_fecha_entrega = 0;
}

PrioridadMedia::PrioridadMedia(const PrioridadMedia& orig) {
}

PrioridadMedia::~PrioridadMedia() {
    if(this->descripcion!=nullptr)delete this->descripcion;
}

void PrioridadMedia::SetNueva_fecha_entrega(int nueva_fecha_entrega) {
    this->nueva_fecha_entrega = nueva_fecha_entrega;
}

int PrioridadMedia::GetNueva_fecha_entrega() const {
    return nueva_fecha_entrega;
}

void PrioridadMedia::SetDescripcion(char* cadena) {
    if(this->descripcion!=nullptr)delete this->descripcion;
    this->descripcion = new char [strlen(cadena)+1];
    strcpy(this->descripcion,cadena);
}

void PrioridadMedia::GetDescripcion(char *cadena) const {
    if(this->descripcion==nullptr)cadena[0]=0;
    else strcpy(cadena,this->descripcion);
}

void PrioridadMedia::leerDatos(ifstream& arch){
    Pedido::leerDatos(arch);
    char desc[100];
    int estadoNum;
    arch>>estadoNum;
    if(estadoNum==0)strcpy(desc,"Inactivo");
    else strcpy(desc,"Activo");
    SetDescripcion(desc);
    arch.get();
}

void PrioridadMedia::imprimeDatos(ofstream& arch)const{
    char descripcion[100];
    GetDescripcion(descripcion);
    Pedido::imprimeDatos(arch);
    arch<<setw(20)<<left<<"Prioridad Media"<<setw(20)<<descripcion<<endl;
}

void PrioridadMedia::actualizaDatos(){
    char estado[100];
    int fecha;
    GetDescripcion(estado);
    Pedido::SetEstado(estado);
    fecha = Pedido::GetFecha();
    if(fecha%100==31){
        if(((fecha%10000)/100)==12)fecha += 10000;
        else fecha += 100;
        fecha -= 30;
        Pedido::SetFecha(fecha);
    }
    else Pedido::SetFecha(fecha+1);
    SetNueva_fecha_entrega(fecha+1);
    double monto;
    monto = Pedido::GetSubtotal();
    Pedido::SetTotal(monto);
}
