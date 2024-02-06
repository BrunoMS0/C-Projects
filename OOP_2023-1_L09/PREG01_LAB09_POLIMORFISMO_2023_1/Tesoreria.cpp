/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.cpp
 * Author: Bruno Monzén Sullón
 * 
 * Created on 28 de octubre de 2023, 10:58 PM
 */

#include "Tesoreria.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#define MAX 105

Tesoreria::Tesoreria() {
}

Tesoreria::Tesoreria(const Tesoreria& orig) {
}

Tesoreria::~Tesoreria() {
}

void Tesoreria::cargaescalas(){
    ifstream arch("escalas.csv",ios::in);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: escalas.csv"<<endl;
        exit(1);
    }
    int i=0;
    int codigo;
    double precio;
    while(true){
        arch>>codigo;
        if(arch.eof())break;
        arch.get();
        arch>>precio;
        lescala[i].SetCodigo(codigo);
        lescala[i].SetPrecio(precio);
        i++;
    }
    lescala[i].SetCodigo(0);
}

void Tesoreria::cargaalumnos(){
    ifstream arch("Alumnos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: Alumnos.csv"<<endl;
        exit(1);
    }
    int i=0;
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        switch(tipo){
            case 'P':
                lboleta[i].asignarPresencial();
                break;
            case 'S':
                lboleta[i].asignarSemipresencial();
                break;
            case 'V':   
                lboleta[i].asignarVirtual();
                break;
        }
        lboleta[i].lee(arch);
        i++;
    }
}

void Tesoreria::imprimeboleta(){
    ofstream arch("Reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: Reporte.txt"<<endl;
        exit(1);
    }  
    arch<<left<<setw(15)<<"Codigo"<<setw(40)<<"Nombre"<<right<<setw(20)<<
            "Escala"<<setw(15)<<"Licencia"<<setw(15)<<"Total"<<endl;
    imprimeLinea(arch,'=',MAX);
    for(int i=0;lboleta[i].ultimo();i++){
        lboleta[i].imprime(arch);
    }
}

void Tesoreria::actualizaboleta(int credito){
    int monto;
    int escala;
    for(int i=0;lboleta[i].ultimo();i++){
        escala = lboleta[i].GetEscala();
        monto = credito*lescala[5-escala].GetPrecio();
        lboleta[i].actualizaDatos(monto);
    }
}

void Tesoreria::imprimeLinea(ofstream &arch,char c,int n)const{
    for(int i=0;i<n;i++)arch<<c;
    arch<<endl;
}