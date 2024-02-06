/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: Bruno Monzén Sullón
 * 
 * Created on 2 de noviembre de 2023, 12:10 PM
 */

#include "Cliente.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

Cliente::Cliente() {
    nombre = nullptr;
    cantped = 0;
    totalped = 0;
    dni = 0;
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
    if(this->nombre!=nullptr)delete this->nombre;
}

void Cliente::SetTotalped(double totalped) {
    this->totalped = totalped;
}

double Cliente::GetTotalped() const {
    return totalped;
}

void Cliente::SetCantped(int cantped) {
    this->cantped = cantped;
}

int Cliente::GetCantped() const {
    return cantped;
}

void Cliente::SetNombre(char* cadena) {
    if(this->nombre!=nullptr)delete this->nombre;
    this->nombre = new char [strlen(cadena)+1];
    strcpy(this->nombre,cadena);
}

void Cliente::GetNombre(char *cadena) const {
    if(this->nombre==nullptr)cadena[0]=0;
    else strcpy(cadena,this->nombre);
}

void Cliente::SetCategoria(char categoria) {
    this->categoria = categoria;
}

char Cliente::GetCategoria() const {
    return categoria;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

 void Cliente::leerDatos(ifstream& arch,char categoria){
     arch>>dni;
     arch.get();
     char nombre[100];
     arch.getline(nombre,100,'\n');
     SetNombre(nombre);
     SetCategoria(categoria);
 }

 void Cliente::imprimirDatos(ofstream& arch)const{
     arch<<left<<setw(15)<<"Total:"<<totalped<<endl;
     arch<<left<<setw(28)<<"Cantidad de Pedidos:"<<cantped<<endl<<endl;
 }
 
 void Cliente::calcula(int cantidad,double total,int dni){
     totalped += total;
     cantped += cantidad;
 }