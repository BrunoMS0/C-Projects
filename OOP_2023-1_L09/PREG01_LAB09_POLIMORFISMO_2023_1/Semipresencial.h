/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Semipresencial.h
 * Author: Bruno Monzén Sullón
 *
 * Created on 28 de octubre de 2023, 10:57 PM
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H
#include "Alumno.h"
using namespace std;

class Semipresencial: public Alumno {
public:
    Semipresencial();
    Semipresencial(const Semipresencial& orig);
    virtual ~Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void leerDatos(ifstream&);
    void imprimeDatos(ofstream&)const;
    void actualizaDatos(double);
private:
    double descuento;
    double total;
};

#endif /* SEMIPRESENCIAL_H */

