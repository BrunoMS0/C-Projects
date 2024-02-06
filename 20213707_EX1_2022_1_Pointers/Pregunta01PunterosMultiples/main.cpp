/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bruno Monzén Sullón
 * codigo: 20213707
 * Created on 5 de octubre de 2023, 03:37 PM
 */

#include "ClientesPreg1.h"
#include <iostream>
#include <iomanip>
#include "FuncionesExamen01Pregunta01.h"
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    char ***cli_NombreCategoria,**pro_Descripcion;
    int ***cli_DniTelPed,**pro_Informacion,**ped_Todo;
    
    CargaDeClientes(cli_DniTelPed,cli_NombreCategoria,"ClientesPreg01.csv");
    PruebaDeClientes(cli_DniTelPed,cli_NombreCategoria,"PruebaClientes01.txt");
    
    CargarProductosPedido(pro_Informacion,pro_Descripcion,ped_Todo,
                            "PedidosPreg01.csv");
    PruebaProductosPedido(pro_Informacion,pro_Descripcion,ped_Todo,
                            "PruebaProductosPedidos01.txt");
    
    ordenarPedidos(ped_Todo);
    PruebaProductosPedido(pro_Informacion,pro_Descripcion,ped_Todo,
                            "PruebaProductosPedidos02.txt");
    
    asignarPedidos(cli_DniTelPed,pro_Informacion,ped_Todo);
    PruebaProductosPedido(pro_Informacion,pro_Descripcion,ped_Todo,
                            "PruebaProductosPedidos03.txt");
    PruebaDeClientes(cli_DniTelPed,cli_NombreCategoria,"PruebaClientes02.txt");
    return 0;
}

