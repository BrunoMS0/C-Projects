/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Luis Bruno Monzén Sullón
 * Codigo: 20213707
 * Created on 22 de septiembre de 2023, 08:00 AM
 */

#include "MuestraPunteros.h"
#include "PunterosGenericos.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *productos,*clientes;
    
    cargaproductos(productos);
    cargaclientes(clientes);
    cargapedidos(productos,clientes);
    imprimereporte(clientes);
    return 0;
}

