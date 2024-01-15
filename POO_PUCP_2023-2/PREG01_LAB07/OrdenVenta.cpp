/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OrdenVenta.cpp
 * Author: Luis Bruno Monzén Sullón
 * Código: 20213707
 * 
 * Created on 3 de noviembre de 2023, 07:59 AM
 */

#include "OrdenVenta.h"
#include "PrioridadAlta.h"
#include "PrioridadMedia.h"
#include "PrioridadBaja.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
OrdenVenta::OrdenVenta() {
}

OrdenVenta::OrdenVenta(const OrdenVenta& orig) {
}

OrdenVenta::~OrdenVenta() {
}

void OrdenVenta::asignarAlta(ifstream& arch){
    ptr_orden = new class PrioridadAlta;
}
void OrdenVenta::asignarMedia(ifstream&arch){
    ptr_orden = new class PrioridadMedia;
}
void OrdenVenta::asignarBaja(ifstream& arch){
    ptr_orden = new class PrioridadBaja;
}

void OrdenVenta::lee(ifstream& arch){
    ptr_orden->leerDatos(arch);
}

void OrdenVenta::imprime(ofstream& arch)const{
    ptr_orden->imprimeDatos(arch);
}

