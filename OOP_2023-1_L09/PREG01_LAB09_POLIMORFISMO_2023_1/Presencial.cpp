/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Presencial.cpp
 * Author: Bruno Monzén Sullón
 * 
 * Created on 28 de octubre de 2023, 10:57 PM
 */

#include "Presencial.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

Presencial::Presencial() {
    total = 0.0;
}

Presencial::Presencial(const Presencial& orig) {
}

Presencial::~Presencial() {
}

void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}

void Presencial::leerDatos(ifstream& arch){
    Alumno::leerDatos(arch);
    arch>>recargo;
    arch.get();
}

void Presencial::imprimeDatos(ofstream& arch)const{
    Alumno::imprimeDatos(arch);
    arch<<right<<setw(30)<<Alumno::GetTotal()<<endl;
}

void Presencial::actualizaDatos(double monto){
    total = monto*recargo/100;
    Alumno::actualizaDatos(monto + total);
}
