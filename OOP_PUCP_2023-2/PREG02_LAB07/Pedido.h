/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Author: Luis Bruno Monzén Sullón
 * Código: 20213707
 * Created on 3 de noviembre de 2023, 07:58 AM
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
    void SetTotal(double total);
    double GetTotal() const;
    void SetEstado(char*);
    void GetEstado(char*) const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetSubtotal(double subtotal);
    double GetSubtotal() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(char*);
    void GetCodigo(char*) const;
    void imprimirFecha(ofstream&)const;
    virtual void leerDatos(ifstream&);
    virtual void imprimeDatos(ofstream&)const;
    virtual void actualizaDatos() = 0;
private:
    char *codigo;
    int dni_cliente;
    double subtotal;
    int fecha;
    char *estado;
    double total;
};

#endif /* PEDIDO_H */

