/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrioridadAlta.h
 * Author: Luis Bruno Monzén Sullón
 * Código: 20213707
 * Created on 3 de noviembre de 2023, 07:59 AM
 */

#ifndef PRIORIDADALTA_H
#define PRIORIDADALTA_H
#include "Pedido.h"
#include <fstream>
using namespace std;
class PrioridadAlta: public Pedido {
public:
    PrioridadAlta();
    PrioridadAlta(const PrioridadAlta& orig);
    virtual ~PrioridadAlta();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void leerDatos(ifstream&);
    void imprimeDatos(ofstream&)const;
    void actualizaDatos();
private:
    double recargo;
    double total;
};

#endif /* PRIORIDADALTA_H */

