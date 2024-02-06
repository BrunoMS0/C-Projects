/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClienteB.h
 * Author: Bruno Monzén Sullón
 *
 * Created on 2 de noviembre de 2023, 12:10 PM
 */

#ifndef CLIENTEB_H
#define CLIENTEB_H
#include "Cliente.h"
#include <fstream>
using namespace std;

class ClienteB: public Cliente {
public:
    ClienteB();
    ClienteB(const ClienteB& orig);
    virtual ~ClienteB();
    void SetFlete(double flete);
    double GetFlete() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void leerDatos(ifstream&,char);
    void imprimirDatos(ofstream&)const;
    void imprimeLinea(ofstream& arch,char c,int n)const;
    void calcula(int,double,int);
private:
    double descuento;
    double flete;
};

#endif /* CLIENTEB_H */

