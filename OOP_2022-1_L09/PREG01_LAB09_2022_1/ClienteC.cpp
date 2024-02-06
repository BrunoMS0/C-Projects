/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClienteC.cpp
 * Author: Bruno Monzén Sullón
 * 
 * Created on 2 de noviembre de 2023, 12:10 PM
 */

#include "ClienteC.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#define MAX 100
ClienteC::ClienteC() {
    flete = 0.0;
}

ClienteC::ClienteC(const ClienteC& orig) {
}

ClienteC::~ClienteC() {
}

void ClienteC::SetFlete(double flete) {
    this->flete = flete;
}

double ClienteC::GetFlete() const {
    return flete;
}

void ClienteC::leerDatos(ifstream& arch,char categoria){
    char c;
    arch>>flete>>c;
    Cliente::leerDatos(arch,categoria);
}

void ClienteC::imprimirDatos(ofstream& arch)const{
    char nombre[100];
    int dni;
    Cliente::GetNombre(nombre);
    dni = Cliente::GetDni();
    arch<<left<<setw(20)<<dni<<nombre<<endl;
    imprimeLinea(arch,'-',MAX);
    arch<<left<<setw(15)<<"Descuento:"<<flete<<setw(15)<<'%'<<endl;
    Cliente::imprimirDatos(arch);
}

void ClienteC::imprimeLinea(ofstream& arch,char c,int n)const{
    for(int i=0;i<n;i++)arch<<c;
    arch<<endl;
}

void ClienteC::calcula(int cantidad,double total,int dni){
    if(dni==Cliente::GetDni()){
        total = total*(1 + flete/100);
        Cliente::calcula(cantidad,total,dni);
    }
}