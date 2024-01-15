/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrioridadMedia.h
 * Author: Luis Bruno Monzén Sullón
 * Código: 20213707
 * Created on 3 de noviembre de 2023, 07:59 AM
 */

#ifndef PRIORIDADMEDIA_H
#define PRIORIDADMEDIA_H
#include "Pedido.h"
#include <fstream>
using namespace std;
class PrioridadMedia: public Pedido {
public:
    PrioridadMedia();
    PrioridadMedia(const PrioridadMedia& orig);
    virtual ~PrioridadMedia();
    void SetNueva_fecha_entrega(int nueva_fecha_entrega);
    int GetNueva_fecha_entrega() const;
    void SetDescripcion(char*);
    void GetDescripcion(char*) const;
    void leerDatos(ifstream&);
    void imprimeDatos(ofstream&)const;
private:
    char *descripcion;
    int nueva_fecha_entrega;
};

#endif /* PRIORIDADMEDIA_H */

