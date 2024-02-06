/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesExamen01Pregunta01.h
 * Author: Bruno Monzén Sullón
 * codigo: 20213707
 *
 * Created on 5 de octubre de 2023, 03:51 PM
 */

#ifndef FUNCIONESEXAMEN01PREGUNTA01_H
#define FUNCIONESEXAMEN01PREGUNTA01_H
#include <fstream>
using namespace std;
char* leerCadena(ifstream& arch);
void leerDatos(int &codigo,int &descuento,int &cantidad,int &precioUni,
                int &stock,int &dni,int &fecha,char *&descripcion,
                ifstream& arch);
int buscarProducto(int codigo,int **buffer_Inf);
void agregarPedidos(char **buffer_Desc,int **buffer_Inf,int codigo,
                    int descuento,int precioUni,int stock,char *descripcion,
                    int j);
void agregarCliente(int **buffer_Todo,int dni,int fecha,int cantidad,
                    int codigo,int i);
void pasarPedidos(char **buffer_Desc,int **buffer_Inf,int **buffer_Todo,
                  char **&pro_Descripcion,int **&pro_Informacion,
                  int **&ped_Todo,int i,int j);
void CargarProductosPedido(int **&pro_Informacion,char **&pro_Descripcion,
                            int **&ped_Todo,const char *nombre_archivo);
void PruebaProductosPedido(int **pro_Informacion,char **pro_Descripcion,
                            int **ped_Todo,const char *nombre_archivo);
int verifica(int **ped_Todo,int i,int izq);
void cambiar(int **ped_Todo,int i,int j);
void ordenamiento(int **ped_Todo,int izq,int der);
void ordenarPedidos(int **ped_Todo);
void aumentarMemoriaPedido(int *&auxDni,int &i,int &capacidad);
void agregarPedido(int *ped_Todo,int &i,int &capacidad,int **pro_Informacion,
                    int *&auxDni);
void asignarPedidos(int ***cli_DniTelPed,int** pro_Informacion,int **ped_Todo);

#endif /* FUNCIONESEXAMEN01PREGUNTA01_H */

