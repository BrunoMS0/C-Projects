/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Almacen.h
 * Author: Luis Bruno Monzén Sullón
 * Código: 20213707
 * Created on 3 de noviembre de 2023, 07:59 AM
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include "OrdenVenta.h"
class Almacen {
public:
    Almacen();
    Almacen(const Almacen& orig);
    virtual ~Almacen();
    void SetCantidad_ordenes(int cantidad_ordenes);
    int GetCantidad_ordenes() const;
    void imprimirLinea(ofstream&,char,int)const;
    void cargar_pedidos();
    void imprimir_ordenes_venta();
    void actualizar_orden();
private:
    class OrdenVenta ordenes[600];
    int cantidad_ordenes;
};

#endif /* ALMACEN_H */

