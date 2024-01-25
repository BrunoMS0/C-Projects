/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Author: Bruno Monzén Sullón
 * 
 * Created on 22 de octubre de 2023, 09:36 AM
 */

#include "Pedido.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

Pedido::Pedido() {
    nombre = nullptr;
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetPrecio(double precio) {
    this->precio = precio;
}

double Pedido::GetPrecio() const {
    return precio;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetNombre(char* cadena) {
    if(this->nombre!=nullptr)delete this->nombre;
    this->nombre = new char [strlen(cadena)+1];
    strcpy(this->nombre,cadena);
}

void Pedido::GetNombre(char *cadena) const {
    if(this->nombre==nullptr)cadena[0]=0;
    else strcpy(cadena,this->nombre);
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::imprimirFecha(ofstream& arch)const{
    int dd,mm,aa;
    aa = fecha/10000;
    dd = fecha%100;
    mm = (fecha%10000)/100;
    arch<<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)
            <<aa<<setfill(' ')<<setw(5)<<' ';
}

bool Pedido::operator == (const class Pedido& pedido){
    return GetDni()==pedido.GetDni() && GetFecha()==pedido.GetFecha() 
            && GetCodigo()==pedido.GetCodigo();
}

void Pedido::operator = (const class Pedido& pedido){
    char nombre[100];
    pedido.GetNombre(nombre);
 
    SetCantidad(pedido.GetCantidad());
    SetCodigo(pedido.GetCodigo());
    SetDni(pedido.GetDni());
    SetFecha(pedido.GetFecha());
    SetNombre(nombre);
    SetPrecio(pedido.GetPrecio());
}

void operator >>(ifstream& arch,class Pedido& pedido){
    int codigo;
    char nombre[100],c;
    int cantidad;
    double precio;
    int dni;
    int fecha,dd,mm,aa;
    arch>>codigo;
    if(arch.eof())return;
    arch.get();
    arch.getline(nombre,100,',');
    arch>>cantidad>>c>>precio>>c>>dni>>c>>dd>>c>>mm>>c>>aa;
    fecha = aa*10000 + mm*100 + dd;
    
    pedido.SetCantidad(cantidad);
    pedido.SetCodigo(codigo);
    pedido.SetDni(dni);
    pedido.SetFecha(fecha);
    pedido.SetNombre(nombre);
    pedido.SetPrecio(precio);
}
