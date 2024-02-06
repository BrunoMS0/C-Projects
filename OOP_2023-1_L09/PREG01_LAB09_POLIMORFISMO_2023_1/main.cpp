/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bruno Monzén Sullón
 *
 * Created on 28 de octubre de 2023, 05:59 PM
 */

#include "Tesoreria.h"
using namespace std;

int main(int argc, char** argv) {
    Tesoreria OTeso;
    
    OTeso.cargaescalas();
    OTeso.cargaalumnos();
    OTeso.actualizaboleta(20);
    OTeso.imprimeboleta();
    
    return 0;
}

