/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bruno Monzén Sullón
 *
 * Created on 22 de octubre de 2023, 12:01 AM
 */

#include <cstdlib>
#include "Cliente.h"
#include "Pedido.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archCli("clientes2.csv",ios::in);
    if(not archCli.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO clientes2.csv"<<endl;
        exit(1);
    }
    ifstream archPed("pedidos2.csv",ios::in);
    if(not archPed.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO pedidos2.csv"<<endl;
        exit(1);
    }
    ifstream archEli("eliminar2.csv",ios::in);
    if(not archEli.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO eliminar2.csv"<<endl;
        exit(1);
    }
    ofstream archRep("Reporte.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO Reporte.txt"<<endl;
        exit(1);
    }
    class Cliente cliente[10];
    class Pedido pedido[10];
    
    for(int i=0;i<10;i++){
        archCli>>cliente[i];
    }
    for(int i=0;i<10;i++){
        archPed>>pedido[i];
    }
    cliente[0]=pedido[0];
    cliente[0]=pedido[1];
    pedido[2]=pedido[0];
    cliente[0]-=pedido[2];
    cliente[0]/25;
    
    for(int i=0;i<10;i++){
        archRep<<cliente[i];
    }
    
    
    return 0;
}

