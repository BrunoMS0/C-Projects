/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: Bruno Monzén Sullón
 * 
 * Created on 22 de octubre de 2023, 09:34 AM
 */

#include <cstring>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Cliente.h"
using namespace std;
#define MAXLINEA 100
Cliente::Cliente() {
    nombre = nullptr;
    numPed = 0;
    total = 0;
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
}

void Cliente::SetTotal(double total) {
    this->total = total;
}

double Cliente::GetTotal() const {
    return total;
}

void Cliente::SetNumPed(int numPed) {
    this->numPed = numPed;
}

int Cliente::GetNumPed() const {
    return numPed;
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

void operator >>(ifstream& arch,class Cliente& cliente){
    int dni;
    char nombre[100];
    char categoria;
    arch>>dni;
    if(arch.eof())return;
    arch.get();
    arch.getline(nombre,100,',');
    arch>>categoria;
    cliente.SetDni(dni);
    cliente.SetNombre(nombre);
    cliente.SetCategoria(categoria);
}

void Cliente::operator =(const class Pedido& pedido){
    double precio = pedido.GetPrecio();
    int cantidad = pedido.GetCantidad();
    lped[numPed] = pedido;
    total += precio*cantidad;
    numPed++;
//    pedido.GetNombre(nombre);
//    lped[num].SetCantidad(pedido.GetCantidad());
//    lped[num].SetCodigo(pedido.GetCodigo());
//    lped[num].SetDni(pedido.GetDni());
//    lped[num].SetFecha(pedido.GetFecha());
//    lped[num].SetNombre(nombre);
//    lped[num].SetPrecio(pedido.GetPrecio());
//    SetNumPed(num++);
//    SetTotal(GetTotal()+pedido.GetPrecio());
}

void Cliente::operator -= (const class Pedido& pedido){
    int cantidad = pedido.GetCantidad();
    double precio = pedido.GetPrecio();
    for(int i=0;i<numPed;i++){
        if(lped[i]==pedido){
            for(int k=i;k<numPed-1;k++){
                lped[k] = lped[k+1];
            }
            numPed--;
            SetTotal(GetTotal()-(cantidad*precio));
            return;
        }
    }
}

void Cliente::operator / (const double descuento){
    double precio;
    for(int i=0;i<numPed;i++){
        precio = lped[numPed].GetPrecio();
        precio = (precio*descuento)/100;
        lped[numPed].SetPrecio(precio);
    }
    total = (total*descuento)/100;
}

void Cliente::imprimirLinea(ofstream& arch,char c,int n)const{
    for(int i=0;i<n;i++)arch<<c;
    arch<<endl;
}

void Cliente::imprimirPedidos(ofstream& arch)const{
    char nombre[100];
    for(int i=0;i<numPed;i++){
        lped[i].GetNombre(nombre);
        lped[i].imprimirFecha(arch);
        arch<<left<<setw(10)<<lped[i].GetCodigo()<<setw(40)<<nombre<<right
                <<setw(20)<<lped[i].GetCantidad()<<setw(10)<<
                lped[i].GetPrecio()<<endl;
    }
}

void operator <<(ofstream& arch,class Cliente& cliente){
    char nombre[100];
    cliente.GetNombre(nombre);
    arch<<left<<setw(20)<<cliente.GetDni()<<nombre<<" DEL "<<
            cliente.GetCategoria()<<endl;
    cliente.imprimirLinea(arch,'=',MAXLINEA);
    cliente.imprimirPedidos(arch);
    arch<<left<<setw(15)<<"# de pedidos: "<<cliente.GetNumPed()<<endl;
    arch<<left<<setw(15)<<"Monto total: "<<cliente.GetTotal()<<endl;
    arch<<endl;
}
