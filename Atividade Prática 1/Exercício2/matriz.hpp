#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
using namespace std;

typedef struct{
    double** m;
    int nLinhas;
    int nColunas;
}Matriz;

void inicializaMatriz(Matriz &X, int ls, int cs, const double elem);

void apagaMatriz(Matriz &X);

Matriz transposta(Matriz &X);

Matriz multiplica_por_cte(Matriz &X, double k);

void imprimeMatriz(Matriz &X);
#endif