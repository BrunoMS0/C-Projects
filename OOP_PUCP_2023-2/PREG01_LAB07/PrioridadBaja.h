/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrioridadBaja.h
 * Author: Luis Bruno Monzén Sullón
 * Código: 20213707
 * Created on 3 de noviembre de 2023, 07:59 AM
 */

#ifndef PRIORIDADBAJA_H
#define PRIORIDADBAJA_H
#include "Pedido.h"
#include <fstream>
using namespace std;
class PrioridadBaja: public Pedido {
public:
    PrioridadBaja();
    PrioridadBaja(const PrioridadBaja& orig);
    virtual ~PrioridadBaja();
    void SetNueva_fecha_entrega(int nueva_fecha_entrega);
    int GetNueva_fecha_entrega() const;
    void SetDias_espera(int dias_espera);
    int GetDias_espera() const;
    void leerDatos(ifstream&);
    void imprimeDatos(ofstream&)const;
private:
    int dias_espera;
    int nueva_fecha_entrega;
};

#endif /* PRIORIDADBAJA_H */

