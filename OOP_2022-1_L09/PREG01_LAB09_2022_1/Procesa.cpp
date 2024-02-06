/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.cpp
 * Author: Bruno Monzén Sullón
 * 
 * Created on 2 de noviembre de 2023, 12:11 PM
 */

#include "Procesa.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#define MAX 100

Procesa::Procesa() {
}

Procesa::Procesa(const Procesa& orig) {
}

Procesa::~Procesa() {
}

void Procesa::asignarPedidos(ifstream& arch){
    int i=0;
    int codigo,cantidad,fecha,dni,dd,mm,aa;
    char c;
    double monto;
    while(true){
        arch>>codigo;
        if(arch.eof())break;
        arch>>c>>cantidad>>c>>monto>>c>>dni>>c>>dd>>c>>mm>>c>>aa;
        fecha = aa*10000 + mm*100 + dd;
        lpedidos[i].SetDni(dni);
        lpedidos[i].SetCantidad(cantidad);
        lpedidos[i].SetCodigo(codigo);
        lpedidos[i].SetTotal(monto);
        lpedidos[i].SetFecha(fecha);
        i++;
    }
}

void Procesa::asignarClientes(ifstream& arch){
    int i=0;
    char categoria;
    while(true){
        arch>>categoria;
        if(arch.eof())break;
        arch.get();
        switch(categoria){
            case 'A':
                ldeudor[i].asignarCategoriaA();
                break;
            case 'B':
                ldeudor[i].asignarCategoriaB();
                break;
            case 'C':  
                ldeudor[i].asignarCategoriaC();
                break;
        }
        ldeudor[i].lee(arch,categoria);
        i++;     
    }
}

void Procesa::carga(){
    ifstream archPed("pedidos4.csv",ios::in);
    if(not archPed.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: pedidos4.csv"<<endl;
        exit(1);
    }
    asignarPedidos(archPed);
    
    ifstream archDeu("clientes3.csv",ios::in);
    if(not archDeu.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: clientes3.csv"<<endl;
        exit(1);
    }
    asignarClientes(archDeu);
}

void Procesa::muestra(){
    ofstream arch("Reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: Reporte.txt"<<endl;
        exit(1);
    }
    arch<<right<<setw(20)<<"REPORTE DE DEUDAS"<<endl;
    imprimeLinea(arch,'=',MAX);
    for(int i=0;ldeudor[i].ultimo();i++){
        ldeudor[i].imprime(arch);
    }
}

void Procesa::imprimeLinea(ofstream& arch,char c,int n)const{
    for(int i=0;i<n;i++)arch<<c;
    arch<<endl;
}

void Procesa::actualiza(){
    int cantidad,dni;
    double total;
    for(int i=0;ldeudor[i].ultimo();i++){
        for(int k=0;lpedidos[k].GetDni();k++){
            cantidad = lpedidos[k].GetCantidad();
            dni = lpedidos[k].GetDni();
            total = lpedidos[k].GetTotal();
            ldeudor[i].calcula(cantidad,total,dni);
        }
    }
}