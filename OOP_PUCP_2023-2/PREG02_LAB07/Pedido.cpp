/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Author: Luis Bruno Monzén Sullón
 * Código: 20213707
 * Created on 3 de noviembre de 2023, 07:58 AM
 */

#include "Pedido.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
Pedido::Pedido() {
    codigo = nullptr;
    dni_cliente = 0;
    estado = nullptr;
    subtotal = 0.0;
    total = 0.0;
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
    if(this->codigo!=nullptr)delete this->codigo;
    if(this->estado!=nullptr)delete this->estado;
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetEstado(char* cadena) {
    if(this->estado!=nullptr)delete this->estado;
    this->estado = new char [strlen(cadena)+1];
    strcpy(this->estado,cadena);
}

void Pedido::GetEstado(char *cadena) const {
    if(this->estado==nullptr)cadena[0]=0;
    else strcpy(cadena,this->estado);
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetSubtotal(double subtotal) {
    this->subtotal = subtotal;
}

double Pedido::GetSubtotal() const {
    return subtotal;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(char* cadena) {
    if(this->codigo!=nullptr)delete this->codigo;
    this->codigo = new char [strlen(cadena)+1];
    strcpy(this->codigo,cadena);
}

void Pedido::GetCodigo(char* cadena) const {
    if(this->codigo==nullptr)cadena[0]=0;
    else strcpy(cadena,this->codigo);
}

void Pedido::leerDatos(ifstream& arch){
    char codigoPed[100],c;
    char estado[100];
    strcpy(estado,"Inactivo");
    int dd,mm,aa;
    arch.getline(codigoPed,100,',');
    arch>>dni_cliente;
    arch.get();
    arch>>subtotal>>c>>aa>>c>>mm>>c>>dd>>c;
    SetEstado(estado);
    SetCodigo(codigoPed);
    fecha = aa*10000 + mm*100 + dd;
}

void Pedido::imprimirFecha(ofstream& arch)const{
    int dd,mm,aa;
    aa = fecha/10000;
    dd = fecha%100;
    mm = (fecha%10000)/100;
    arch<<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa
            <<setfill(' ')<<setw(10)<<' ';
}

void Pedido::imprimeDatos(ofstream& arch)const{
    char codigo[100],estado[100];
    GetCodigo(codigo);
    GetEstado(estado);
    arch<<left<<setw(20)<<codigo<<setw(20)<<dni_cliente<<setw(20)<<subtotal;
    imprimirFecha(arch);
    arch<<left<<setw(20)<<estado<<setw(20)<<total;    
}

void Pedido::actualizaDatos(){
    
}

