/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrioridadBaja.cpp
 * Author: Luis Bruno Monzén Sullón
 * Código: 20213707
 * Created on 3 de noviembre de 2023, 07:59 AM
 */

#include "PrioridadBaja.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
PrioridadBaja::PrioridadBaja() {
    dias_espera = 0;
    nueva_fecha_entrega = 0;
}

PrioridadBaja::PrioridadBaja(const PrioridadBaja& orig) {
}

PrioridadBaja::~PrioridadBaja() {
}

void PrioridadBaja::SetNueva_fecha_entrega(int nueva_fecha_entrega) {
    this->nueva_fecha_entrega = nueva_fecha_entrega;
}

int PrioridadBaja::GetNueva_fecha_entrega() const {
    return nueva_fecha_entrega;
}

void PrioridadBaja::SetDias_espera(int dias_espera) {
    this->dias_espera = dias_espera;
}

int PrioridadBaja::GetDias_espera() const {
    return dias_espera;
}

void PrioridadBaja::leerDatos(ifstream& arch){
    Pedido::leerDatos(arch);
    arch>>dias_espera;
    arch.get();
}

void PrioridadBaja::imprimeDatos(ofstream& arch)const{
    Pedido::imprimeDatos(arch);
    arch<<setw(20)<<left<<"Prioridad Baja"<<setw(20)<<dias_espera<<endl;
}

void PrioridadBaja::actualizaDatos(){
    int fecha;
    double monto;
    monto = Pedido::GetSubtotal();
    Pedido::SetTotal(monto);
    fecha = Pedido::GetFecha();
    nueva_fecha_entrega = fecha;
}