/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Author: Bruno Monzén Sullón
 *
 * Created on 22 de octubre de 2023, 09:36 AM
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream>
using namespace std;
class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(char*);
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void imprimirFecha(ofstream&)const;
    bool operator == (const class Pedido&);
    void operator = (const class Pedido&);
private:
    int codigo;
    char *nombre;
    int cantidad;
    double precio;
    int dni;
    int fecha;
};
void operator >>(ifstream&,class Pedido&);
#endif /* PEDIDO_H */

