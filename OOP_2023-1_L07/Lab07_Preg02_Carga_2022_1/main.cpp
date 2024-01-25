/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bruno Monzén Sullón
 *
 * Created on 22 de octubre de 2023, 02:11 PM
 */

#include <cstdlib>
#include "Cliente.h"
#include "Pedido.h"
#include "FunAux.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    class Cliente cliente[30];
    class Pedido pedido[200];
    int numCli,numPed;
    
    cargarCliente(cliente,numCli,"clientes2.csv");
    cargarPedido(pedido,numPed,"pedidos2.csv");
    agregarPedidos(cliente,pedido,numCli,numPed);
    eliminarPedidos(cliente,numCli,"eliminar2.csv");
    aplicarDescuento(cliente,numCli);
    emitirReporte(cliente,numCli,"Reporte.txt");
    return 0;
}

