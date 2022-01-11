#include "matriz.hpp"

void inicializaMatriz(Matriz &X, int ls, int cs, const double elem){
    X.nLinhas = ls;
    X.nColunas = cs;
    X.m = new double*[ls];

    for (int i = 0; i < ls; i++){
        X.m[i] = new double[cs];
    }
    for (int i = 0; i < ls; i++){
        for (int j = 0; j < cs; j++){
            X.m[i][j] = elem;
        }
    }
}

void apagaMatriz(Matriz &X){
    int ls = X.nLinhas;
    int cs = X.nColunas;
    for (int i = 0; i < ls; i++){
        delete[] X.m[i]; 
    }
    delete[] X.m;
    X.m = NULL;
}

Matriz transposta(Matriz &X){
    double elem = X.m[1][1];
    inicializaMatriz(X, X.nColunas, X.nLinhas, elem);
    return X; 
}

Matriz multiplica_por_cte(Matriz &X, double k){
    Matriz aux;
    aux.nLinhas = X.nLinhas;
    aux.nColunas = X.nColunas;
    int ls = aux.nLinhas;
    int cs = aux.nColunas;

    aux.m = new double*[ls];
    for (int i = 0; i < ls; i++){
        aux.m[i] = new double[cs];
    }
    for (int i = 0; i < ls; i++){
        for (int j = 0; j < cs; j++){
           aux.m[i][j] = X.m[i][j]*k;
        }
    } 
 return aux;
}

void imprimeMatriz(Matriz &X){
    int ls = X.nLinhas;
    int cs = X.nColunas;
for (int i = 0; i < ls; i++){
        for (int j = 0; j < cs; j++){
            cout << X.m[i][j] << " ";
        }
        cout << endl;
    }
}