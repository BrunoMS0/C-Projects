/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClienteC.h
 * Author: Bruno Monzén Sullón
 *
 * Created on 2 de noviembre de 2023, 12:10 PM
 */

#ifndef CLIENTEC_H
#define CLIENTEC_H
#include "Cliente.h"
#include <fstream>
using namespace std;

class ClienteC: public Cliente {
public:
    ClienteC();
    ClienteC(const ClienteC& orig);
    virtual ~ClienteC();
    void SetFlete(double flete);
    double GetFlete() const;
    void leerDatos(ifstream&,char);
    void imprimirDatos(ofstream&)const;
    void imprimeLinea(ofstream&,char,int)const;
    void calcula(int,double,int);
private:
    double flete;
};

#endif /* CLIENTEC_H */

