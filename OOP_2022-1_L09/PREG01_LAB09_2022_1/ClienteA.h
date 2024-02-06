/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClienteA.h
 * Author: Bruno Monzén Sullón
 *
 * Created on 2 de noviembre de 2023, 12:10 PM
 */

#ifndef CLIENTEA_H
#define CLIENTEA_H
#include "Cliente.h"
#include <fstream>
using namespace std;

class ClienteA: public Cliente {
public:
    ClienteA();
    ClienteA(const ClienteA& orig);
    virtual ~ClienteA();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void leerDatos(ifstream&,char);
    void imprimirDatos(ofstream&)const;
    void imprimeLinea(ofstream&,char,int)const;
    void calcula(int,double,int);
private:
    double descuento; 
};

#endif /* CLIENTEA_H */

