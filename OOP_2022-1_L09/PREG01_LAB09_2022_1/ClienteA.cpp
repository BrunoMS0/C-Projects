/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClienteA.cpp
 * Author: Bruno Monzén Sullón
 * 
 * Created on 2 de noviembre de 2023, 12:10 PM
 */

#include "ClienteA.h"
#include "Cliente.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#define MAX 100

ClienteA::ClienteA() {
    descuento = 0.0;
}

ClienteA::ClienteA(const ClienteA& orig) {
}

ClienteA::~ClienteA() {
}

void ClienteA::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double ClienteA::GetDescuento() const {
    return descuento;
}

void ClienteA::leerDatos(ifstream& arch,char categoria){
    char c;
    arch>>descuento>>c;
    Cliente::leerDatos(arch,categoria);
}

void ClienteA::imprimirDatos(ofstream& arch)const{
    char nombre[100];
    int dni;
    Cliente::GetNombre(nombre);
    dni = Cliente::GetDni();
    arch<<left<<setw(20)<<dni<<nombre<<endl;
    imprimeLinea(arch,'-',MAX);
    arch<<left<<setw(15)<<"Descuento:"<<descuento<<setw(15)<<'%'<<endl;
    Cliente::imprimirDatos(arch);
}

void ClienteA::imprimeLinea(ofstream& arch,char c,int n)const{
    for(int i=0;i<n;i++)arch<<c;
    arch<<endl;
}

void ClienteA::calcula(int cantidad,double total,int dni){
    if(dni==Cliente::GetDni()){
        total = total*(1 - descuento/100);
        Cliente::calcula(cantidad,total,dni);
    }
}
