/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escala.cpp
 * Author: Bruno Monzén Sullón
 * 
 * Created on 28 de octubre de 2023, 10:57 PM
 */

#include "Escala.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

Escala::Escala() {
    codigo = 0;
}

Escala::Escala(const Escala& orig) {
}

Escala::~Escala() {
}

void Escala::SetPrecio(double precio) {
    this->precio = precio;
}

double Escala::GetPrecio() const {
    return precio;
}

void Escala::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Escala::GetCodigo() const {
    return codigo;
}

