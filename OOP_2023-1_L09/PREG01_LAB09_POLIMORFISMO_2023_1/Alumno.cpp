/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: Bruno Monzén Sullón
 * 
 * Created on 28 de octubre de 2023, 10:57 PM
 */

#include "Alumno.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

Alumno::Alumno() {
    codigo = 0;
    nombre = nullptr;
    total = 0.0;
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
    if(this->nombre!=nullptr)delete this->nombre;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(char* cadena) {
    if(this->nombre!=nullptr)delete this->nombre;
    this->nombre = new char [strlen(cadena)+1];
    strcpy(this->nombre,cadena);
}

void Alumno::GetNombre(char *cadena) const {
    if(this->nombre==nullptr)cadena[0]=0;
    else strcpy(cadena,this->nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::leerDatos(ifstream& arch){
    char nombre[100],c;
    arch>>codigo>>c;
    arch.getline(nombre,100,',');
    arch>>escala>>c;
    SetNombre(nombre);
}

void Alumno::imprimeDatos(ofstream& arch)const{
    char nombre[100];
    GetNombre(nombre);
    arch<<left<<setw(15)<<codigo<<setw(40)<<nombre<<right<<setw(20)<<escala
            <<"  ";
}

void Alumno::actualizaDatos(double monto){
    total = monto;
}

