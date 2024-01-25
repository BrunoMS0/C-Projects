/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: Bruno Monzén Sullón
 *
 * Created on 22 de octubre de 2023, 09:34 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include "Pedido.h"
#include <fstream>
using namespace std;

class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetTotal(double total);
    double GetTotal() const;
    void SetNumPed(int numPed);
    int GetNumPed() const;
    void SetNombre(char*);
    void GetNombre(char*) const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    void operator = (const class Pedido&);
    void operator -= (const class Pedido&);
    void operator / (const double);
    void imprimirLinea(ofstream&,char,int)const;
    void imprimirPedidos(ofstream& arch)const;    
private:
    int dni;
    char categoria;
    char *nombre;
    class Pedido lped[100];
    int numPed;
    double total;
};
void operator >>(ifstream&,class Cliente&);
void operator <<(ofstream&,const class Cliente&);
#endif /* CLIENTE_H */

