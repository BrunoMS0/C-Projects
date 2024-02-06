/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: Bruno Monzén Sullón
 *
 * Created on 2 de noviembre de 2023, 12:10 PM
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include <fstream>
using namespace std;

class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetTotalped(double totalped);
    double GetTotalped() const;
    void SetCantped(int cantped);
    int GetCantped() const;
    void SetNombre(char*);
    void GetNombre(char*) const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    virtual void leerDatos(ifstream&,char);
    virtual void imprimirDatos(ofstream&)const;
    virtual void calcula(int,double,int);
private:
    int dni;
    char categoria;
    char *nombre;
    int cantped;
    double totalped;
};

#endif /* CLIENTE_H */

