/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Presencial.h
 * Author: Bruno Monzén Sullón
 *
 * Created on 28 de octubre de 2023, 10:57 PM
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H
#include "Alumno.h"
#include <fstream>
using namespace std;

class Presencial: public Alumno{
public:
    Presencial();
    Presencial(const Presencial& orig);
    virtual ~Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void leerDatos(ifstream&);
    void imprimeDatos(ofstream&)const;
    void actualizaDatos(double);
private:
    double recargo;
    double total;
};

#endif /* PRESENCIAL_H */

