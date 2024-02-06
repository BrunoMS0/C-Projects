/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Semipresencial.cpp
 * Author: Bruno Monzén Sullón
 * 
 * Created on 28 de octubre de 2023, 10:57 PM
 */

#include "Semipresencial.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

Semipresencial::Semipresencial() {
    total = 0.0;
}

Semipresencial::Semipresencial(const Semipresencial& orig) {
}

Semipresencial::~Semipresencial() {
}

void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
    return descuento;
}

void Semipresencial::leerDatos(ifstream& arch){
    Alumno::leerDatos(arch);
    arch>>descuento;
    arch.get();
}

void Semipresencial::imprimeDatos(ofstream& arch)const{
    Alumno::imprimeDatos(arch);
    arch<<right<<setw(30)<<Alumno::GetTotal()<<endl;
}

void Semipresencial::actualizaDatos(double monto){
    total = monto*descuento/100;
    Alumno::actualizaDatos(monto - total);
}