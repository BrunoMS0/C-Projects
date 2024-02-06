/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deudor.cpp
 * Author: Bruno Monzén Sullón
 * 
 * Created on 2 de noviembre de 2023, 12:10 PM
 */

#include "Deudor.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ClienteA.h"
#include "ClienteB.h"
#include "ClienteC.h"

Deudor::Deudor() {
    Cdeudor = nullptr;
}

Deudor::Deudor(const Deudor& orig) {
}

Deudor::~Deudor() {
}

bool Deudor::ultimo(){
    return Cdeudor!=nullptr;
}

void Deudor::asignarCategoriaA(){
    Cdeudor = new class ClienteA;
}

void Deudor::asignarCategoriaB(){
    Cdeudor = new class ClienteB;
}

void Deudor::asignarCategoriaC(){
    Cdeudor = new class ClienteC;
}

void Deudor::lee(ifstream& arch,char categoria){
    Cdeudor->leerDatos(arch,categoria);
}

void Deudor::imprime(ofstream& arch)const{
    Cdeudor->imprimirDatos(arch);
}

void Deudor::calcula(int cantidad,double total,int dni){
    Cdeudor->calcula(cantidad,total,dni);
}