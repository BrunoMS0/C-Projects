/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.cpp
 * Author: Bruno Monzén Sullón
 * 
 * Created on 28 de octubre de 2023, 10:57 PM
 */

#include "Virtual.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

Virtual::Virtual() {
    licencia = nullptr;
    total = 0.0;
}

Virtual::Virtual(const Virtual& orig) {
}

Virtual::~Virtual() {
    if(this->licencia!=nullptr)delete this->licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(char* cadena) {
    if(this->licencia!=nullptr)delete this->licencia;
    this->licencia = new char [strlen(cadena)+1];
    strcpy(this->licencia,cadena);
}

void Virtual::GetLicencia(char *cadena) const {
    if(this->licencia==nullptr)cadena[0]=0;
    else strcpy(cadena,this->licencia);
}

void Virtual::leerDatos(ifstream& arch){
    Alumno::leerDatos(arch);
    char licencia[100];
    arch.getline(licencia,100,'\n');
    SetLicencia(licencia);
}

void Virtual::imprimeDatos(ofstream& arch)const{
    Alumno::imprimeDatos(arch);
    char licencia[100];
    GetLicencia(licencia);
    arch<<right<<setw(15)<<licencia<<setw(15)<<Alumno::GetTotal()<<endl;
}

void Virtual::actualizaDatos(double monto){
    Alumno::actualizaDatos(monto + total);
}