/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bruno Monzén Sullón
 *
 * Created on 30 de octubre de 2023, 10:42 PM
 */

#include "Procesa.h"
using namespace std;

int main(int argc, char** argv) {
    Procesa pro;
    
    pro.carga();
    pro.actualiza();
    pro.muestra();
    
    return 0;
}

