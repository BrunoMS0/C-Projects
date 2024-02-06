/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.h
 * Author: Bruno Monzén Sullón
 *
 * Created on 28 de octubre de 2023, 10:58 PM
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include "Boleta.h"
#include "Escala.h"
class Tesoreria {
public:
    Tesoreria();
    Tesoreria(const Tesoreria& orig);
    virtual ~Tesoreria();
    void cargaescalas();
    void cargaalumnos();
    void imprimeboleta();
    void actualizaboleta(int);
    void imprimeLinea(ofstream &arch,char,int)const;
private:
    class Boleta lboleta[200];
    class Escala lescala[200];
};

#endif /* TESORERIA_H */

