/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.h
 * Author: Bruno Monzén Sullón
 *
 * Created on 7 de octubre de 2023, 03:12 PM
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
#include <fstream>
using namespace std;
char* leerCadena(ifstream& arch);
void aumentarMemoria(void **&ptr,int &i,int &capacidad);
void* registroProd(ifstream& arch);
void cargaProductos(void *&productos);
void* registroPed(ifstream& arch);
void cargaPedidos(void *&pedidos);
int buscarProducto(void *aterrizaje2_ped,void **aterrizaje1_prod);
void actualizarEstadosPed(void *productos,void *pedidos);
char *leerNombre(ifstream& arch);
void *registroCli(ifstream& arch);
void *registroClixPed(void **aterrizaje2_ped);
void guardarPedido(void **&aterrizaje3_cli,void **aterrizaje2_ped,int &i,
                    int &capacidad);
void registrarPedidos(void *auxClientes,void *pedidos,int &i,int &capacidad);
void procesaClientes(void *productos,void *pedidos,void *&clientes);
void imprimirPedidos(void **aterrizaje2,ofstream& arch);
void imprimeReporte(void *clientes);
void imprimeLinea(char c,int n,ofstream& arch);
#endif /* PUNTEROSGENERICOS_H */

