/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boleta.h
 * Author: Bruno Monzén Sullón
 *
 * Created on 28 de octubre de 2023, 10:57 PM
 */

#ifndef BOLETA_H
#define BOLETA_H
#include "Alumno.h"
#include <fstream>
using namespace std;
class Boleta {
public:
    Boleta();
    Boleta(const Boleta& orig);
    virtual ~Boleta();
    void asignarPresencial();
    void asignarSemipresencial();
    void asignarVirtual();
    void lee(ifstream&);
    void imprime(ofstream&)const;
    bool ultimo();
    void actualizaDatos(double);
    int GetEscala();
private:
    class Alumno *pboleta;
};

#endif /* BOLETA_H */

