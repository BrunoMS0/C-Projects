/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boleta.cpp
 * Author: Bruno Monzén Sullón
 * 
 * Created on 28 de octubre de 2023, 10:57 PM
 */

#include "Boleta.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

Boleta::Boleta() {
    pboleta = nullptr;
}

Boleta::Boleta(const Boleta& orig) {
}

Boleta::~Boleta() {
}

bool Boleta::ultimo(){
    return pboleta != nullptr;
}

void Boleta::asignarPresencial(){
    pboleta = new class Presencial;
}

void Boleta::asignarSemipresencial(){
    pboleta = new class Semipresencial;
}

void Boleta::asignarVirtual(){
    pboleta = new class Virtual;
}

void Boleta::lee(ifstream& arch){
    pboleta->leerDatos(arch);
}

void Boleta::imprime(ofstream& arch)const{
    pboleta->imprimeDatos(arch);
}

void Boleta::actualizaDatos(double monto){
    pboleta->actualizaDatos(monto);
}

int Boleta::GetEscala(){
    return pboleta->GetEscala();
}
