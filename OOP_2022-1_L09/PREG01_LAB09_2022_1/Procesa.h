/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.h
 * Author: Bruno Monzén Sullón
 *
 * Created on 2 de noviembre de 2023, 12:11 PM
 */

#ifndef PROCESA_H
#define PROCESA_H
#include "Pedido.h"
#include "Deudor.h"
#include <fstream>
using namespace std;

class Procesa {
public:
    Procesa();
    Procesa(const Procesa& orig);
    virtual ~Procesa();
    void carga();
    void muestra();
    void actualiza();
    void asignarPedidos(ifstream&);
    void asignarClientes(ifstream&);
    void imprimeLinea(ofstream& arch,char c,int n)const;
private:
    class Pedido lpedidos[200];
    class Deudor ldeudor[200];
};

#endif /* PROCESA_H */

