/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstdlib>
#include "Cliente.h"
#include "Pedido.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

void cargarCliente(class Cliente *cliente,int &numCli,
        const char *nombre_archivo){
    ifstream arch(nombre_archivo,ios::in);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: "<<nombre_archivo<<endl;
        exit(1);
    }
    
    numCli=0;
    while(true){
        arch>>cliente[numCli];
        if(arch.eof())break;
        numCli++;
    }
}

void cargarPedido(class Pedido *pedido,int &numPed,const char *nombre_archivo){
    ifstream arch(nombre_archivo,ios::in);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: "<<nombre_archivo<<endl;
        exit(1);
    }
    
    numPed=0;
    while(true){
        arch>>pedido[numPed];
        if(arch.eof())break;
        numPed++;
    }    
}

void agregarPedidos(class Cliente *cliente,const class Pedido *pedido,
                    int numCli,int numPed){
    for(int i=0;i<numPed;i++){
        for(int k=0;k<numCli;k++){
            if(pedido[i].GetDni()==cliente[k].GetDni()){
                cliente[k]=pedido[i];
                break;
            }
        }
    }  
}

void eliminarPedidos(class Cliente *cliente,int numCli,
                    const char *nombre_archivo){
    ifstream arch(nombre_archivo,ios::in);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: "<<nombre_archivo<<endl;
        exit(1);
    }
    class Pedido pedido;
    while(true){
        arch>>pedido;
        if(arch.eof())break;
        for(int i=0;i<numCli;i++){
            if(cliente[i].GetDni()==pedido.GetDni())cliente[i]-=pedido; ;
            break;
        }
    }
}

void aplicarDescuento(class Cliente *cliente,int numCli){
    for(int i=0;i<numCli;i++){
        if(cliente[i].GetCategoria()=='A'){
            cliente[i]/10;
        }
    }
}

void emitirReporte(const class Cliente *cliente,int numCli,
                    const char *nombre_archivo){
    ofstream arch(nombre_archivo,ios::out);
    if(not arch.is_open()){
        cout<<"NO SE ABRIO EL ARCHIVO: "<<nombre_archivo<<endl;
        exit(1);
    }
    for(int i=0;i<numCli;i++)arch<<cliente[i];
}