/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bruno Monzén Sullón
 *
 * Created on 7 de octubre de 2023, 03:09 PM
 */

#include "PunterosGenericos.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *productos,*pedidos,*clientes;
    
    cargaProductos(productos);
    cargaPedidos(pedidos);
    procesaClientes(productos,pedidos,clientes);
    imprimeReporte(clientes);
    return 0;
}

