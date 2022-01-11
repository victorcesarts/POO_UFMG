#include "matriz.hpp"
#include <iostream>

Matrix::Matrix(){}

Matrix::~Matrix(){}

Matrix::Matrix(int rows, int cols) : nRows(rows), nCols(cols){
    m = new double*[rows];  

    for (int i = 0; i < rows; i++){
        m[i] = new double[cols];
        for (int j = 0; j < cols; j++){
            m[i][j] = 0;
        }
    }
}

int Matrix::getRows()const{
    return nRows;
}

int Matrix::getCols()const{
    return nCols;
}

Matrix Matrix::transpose(){
    int lines = getRows();
    int cols = getCols();
    Matrix aux(cols, lines);
    return aux;
}

void Matrix::print() const{
    int ls = this -> nRows;
    int cs = this -> nCols;
    for (int i = 0; i < ls; i++){
        for (int j = 0; j < cs; j++){
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
