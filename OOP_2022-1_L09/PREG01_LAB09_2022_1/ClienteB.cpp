/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClienteB.cpp
 * Author: Bruno Monzén Sullón
 * 
 * Created on 2 de noviembre de 2023, 12:10 PM
 */

#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ClienteB.h"
#define MAX 100
ClienteB::ClienteB() {
    descuento = 0.0;
    flete = 0.0;
}

ClienteB::ClienteB(const ClienteB& orig) {
}

ClienteB::~ClienteB() {
}

void ClienteB::SetFlete(double flete) {
    this->flete = flete;
}

double ClienteB::GetFlete() const {
    return flete;
}

void ClienteB::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double ClienteB::GetDescuento() const {
    return descuento;
}

void ClienteB::leerDatos(ifstream& arch,char categoria){
    char c;
    arch>>descuento>>c>>flete>>c;
    Cliente::leerDatos(arch,categoria);
}

void ClienteB::imprimirDatos(ofstream& arch)const{
    char nombre[100];
    int dni;
    Cliente::GetNombre(nombre);
    dni = Cliente::GetDni();
    arch<<left<<setw(20)<<dni<<nombre<<endl;
    imprimeLinea(arch,'-',MAX);
    arch<<left<<setw(15)<<"Descuento:"<<descuento<<setw(15)<<'%'<<setw(15)
            <<"Flete:"<<flete<<'%'<<endl;
    Cliente::imprimirDatos(arch);
}

void ClienteB::calcula(int cantidad,double total,int dni){
    if(dni==Cliente::GetDni()){
        total = total*(1 - descuento/100 + flete/100);
        Cliente::calcula(cantidad,total,dni);
    }
}

void ClienteB::imprimeLinea(ofstream& arch,char c,int n)const{
    for(int i=0;i<n;i++)arch<<c;
    arch<<endl;
}
