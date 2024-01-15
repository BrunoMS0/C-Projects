/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.h
 * Author: Luis Bruno Monzén Sullón
 * Codigo: 20213707
 *
 * Created on 22 de septiembre de 2023, 08:01 AM
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
#include <fstream>
using namespace std;
char* leerCadena(ifstream& arch);
void* registroProd(ifstream& arch);
void cargaproductos(void *&productos);
void *registroCli(ifstream& arch);
void cargaclientes(void *&clientes);
void leerRegistros(char *&codProd,int *&dni,int *&cantidad,ifstream& arch);
int buscarCliente(void *clientes,int dni);
int buscarProducto(void *productos,int *codProd);
void* registroPedido(char *codProd,int *cantidad,double *precio);
void asignarProducto(void **aterrizaje2,void *productos,int posCli,char *codProd,
                        int *cantidad,int posProd,int &numDat);
void cargapedidos(void *productos,void *clientes);
void liberar(void *&aterrizaje2,int numDat);
void liberarEspacios(void *clientes,int *numDat);
void imprimereporte(void *clientes);
void imprimirProd(void *aterrizaje2,ofstream& arch);
void imprimereporte(void *clientes);
void imprimeLinea(ofstream& arch,char c,int n);

#endif /* PUNTEROSGENERICOS_H */

