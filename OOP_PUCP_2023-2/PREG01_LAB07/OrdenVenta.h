/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OrdenVenta.h
 * Author: Luis Bruno Monzén Sullón
 * Código: 20213707
 * Created on 3 de noviembre de 2023, 07:59 AM
 */

#ifndef ORDENVENTA_H
#define ORDENVENTA_H
#include "Pedido.h"
#include <fstream>
using namespace std;
class OrdenVenta {
public:
    OrdenVenta();
    OrdenVenta(const OrdenVenta& orig);
    virtual ~OrdenVenta();
    void asignarAlta(ifstream&);
    void asignarMedia(ifstream&);
    void asignarBaja(ifstream&);
    void lee(ifstream&);
    void imprime(ofstream&)const;
private:
    class Pedido *ptr_orden;
};

#endif /* ORDENVENTA_H */

