/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: Bruno Monzén Sullón
 *
 * Created on 28 de octubre de 2023, 10:57 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include <fstream>
using namespace std;

class Alumno {
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(char*);
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void leerDatos(ifstream&);
    virtual void imprimeDatos(ofstream&)const;
    virtual void actualizaDatos(double monto);
private:
    int codigo;
    char *nombre;
    int escala;
    double creditos;
    double total;
};

#endif /* ALUMNO_H */

