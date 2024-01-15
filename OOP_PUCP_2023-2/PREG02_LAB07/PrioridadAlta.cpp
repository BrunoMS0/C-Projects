/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrioridadAlta.cpp
 * Author: Luis Bruno Monzén Sullón
 * Código: 20213707
 * Created on 3 de noviembre de 2023, 07:59 AM
 */

#include "PrioridadAlta.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
PrioridadAlta::PrioridadAlta() {
    recargo = 0.0;
    total = 0.0;
}

PrioridadAlta::PrioridadAlta(const PrioridadAlta& orig) {
}

PrioridadAlta::~PrioridadAlta() {
}

void PrioridadAlta::SetTotal(double total) {
    this->total = total;
}

double PrioridadAlta::GetTotal() const {
    return total;
}

void PrioridadAlta::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double PrioridadAlta::GetRecargo() const {
    return recargo;
}

void PrioridadAlta::leerDatos(ifstream& arch){
    Pedido::leerDatos(arch);
    arch>>recargo;
    arch.get();
}

void PrioridadAlta::imprimeDatos(ofstream& arch)const{
    Pedido::imprimeDatos(arch);
    arch<<setw(20)<<left<<"Prioridad Alta"<<setw(20)<<recargo<<endl;
}

void PrioridadAlta::actualizaDatos(){
    double subtotal;
    subtotal = Pedido::GetSubtotal();
    total = subtotal*(recargo/100);
    Pedido::SetTotal(total+subtotal);   
}