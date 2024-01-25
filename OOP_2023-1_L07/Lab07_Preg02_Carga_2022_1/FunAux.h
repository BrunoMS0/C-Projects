/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FunAux.h
 * Author: Bruno Monzén Sullón
 *
 * Created on 22 de octubre de 2023, 02:18 PM
 */

#ifndef FUNAUX_H
#define FUNAUX_H
#include <fstream>
using namespace std;

void cargarCliente(class Cliente *cliente,int &numCli,
        const char *nombre_archivo);
void cargarPedido(class Pedido *pedido,int &numPed,const char *nombre_archivo);
void agregarPedidos(class Cliente *cliente,const class Pedido *pedido,
                    int numCli,int numPed);
void eliminarPedidos(class Cliente *cliente,int numCli,
                    const char *nombre_archivo);
void aplicarDescuento(class Cliente *cliente,int numCli);
void emitirReporte(const class Cliente *cliente,int numCli,
                    const char *nombre_archivo);

#endif /* FUNAUX_H */

