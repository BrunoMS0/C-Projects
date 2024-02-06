/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deudor.h
 * Author: Bruno Monzén Sullón
 *
 * Created on 2 de noviembre de 2023, 12:10 PM
 */

#ifndef DEUDOR_H
#define DEUDOR_H
#include "Cliente.h"
#include "ClienteA.h"
#include "ClienteB.h"
#include "ClienteC.h"
#include <fstream>
using namespace std;

class Deudor {
public:
    Deudor();
    Deudor(const Deudor& orig);
    virtual ~Deudor();
    bool ultimo();
    void asignarCategoriaA();
    void asignarCategoriaB();
    void asignarCategoriaC();
    void lee(ifstream&,char);
    void imprime(ofstream&)const;
    void calcula(int,double,int);
private:
    class Cliente *Cdeudor;
};

#endif /* DEUDOR_H */

