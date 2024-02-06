/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.h
 * Author: Bruno Monzén Sullón
 *
 * Created on 28 de octubre de 2023, 10:57 PM
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H
#include "Alumno.h"
using namespace std;

class Virtual: public Alumno {
public:
    Virtual();
    Virtual(const Virtual& orig);
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(char*);
    void GetLicencia(char*) const;
    void leerDatos(ifstream&);
    void imprimeDatos(ofstream&)const;
    void actualizaDatos(double);
private:
    char *licencia;
    double total;
};

#endif /* VIRTUAL_H */

