/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Luis Bruno Monzén Sullón
 * Código: 20213707
 * Created on 3 de noviembre de 2023, 07:58 AM
 */

#include "Almacen.h"
using namespace std;

int main(int argc, char** argv) {
    Almacen almacen;
    
    almacen.cargar_pedidos();
    almacen.imprimir_ordenes_venta();
    
    return 0;
}

