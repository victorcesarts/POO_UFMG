#include "matriz.hpp"
#include <iostream>
#include <fstream>

Matrix::Matrix(){}

Matrix::Matrix(int rows, int cols, const double &value) : nRows(rows), nCols(cols){
    m = new double*[nRows];  
    for (int i = 0; i < nRows; i++){
        m[i] = new double[nCols];
        for (int j = 0; j < nCols; j++){
            m[i][j] = value;
        }
    }
}

Matrix::Matrix(std::ifstream& myFile){
    double value = 0.0;
    while (myFile >> nRows >> nCols >> value){
        myFile.clear();
    }
    m = new double*[nRows];  
    for (int i = 0; i < nRows; i++){
        m[i] = new double[nCols];
        for (int j = 0; j < nCols; j++){
            m[i][j] = value;
        }
    }
}

Matrix::Matrix(const Matrix& that) : nRows(that.getRows()), nCols(that.getCols()){
    m = new double*[nRows];  
    for (int i = 0; i < nRows; i++){
        m[i] = new double[nCols];
        for (int j = 0; j < nCols; j++){
            m[i][j] = that.get(i, j);
        }
    }
}
Matrix::~Matrix(){
    
    for (int i = 0; i < nRows; i++){
        delete[] m[i];
    }
    delete[] m;
}

inline int Matrix::getRows() const {return nRows;}
inline int Matrix::getCols() const {return nCols;}
inline double Matrix::get(int row, int col) const {return m[row][col];}

void Matrix::print() const{
    int ls = this -> getRows();
    int cs = this -> getCols();
    for (int i = 0; i < ls; i++){
        for (int j = 0; j < cs; j++){
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void Matrix::unit(){
    if(nRows == nCols){
        for (int i = 0; i < nRows; i++){
            m[i] = new double[nCols];
            for (int j = 0; j < nCols; j++){
                if(i==j)
                    m[i][j] = 1;
                else    
                    m[i][j] = 0;
            }
        }
    }else{ 
        std::cout << 
        "It's not possible convert this matrix to an identity matrix. They must have Rows = Columns"
        << std::endl;
    }
}

void Matrix::zeros(){
    for (int i = 0; i < nRows; i++){
        m[i] = new double[nCols];
        for (int j = 0; j < nCols; j++){
            m[i][j] = 0;
        }
    }
}

void Matrix::ones(){
    for (int i = 0; i < nRows; i++){
        m[i] = new double[nCols];
        for (int j = 0; j < nCols; j++){
            m[i][j] = 1;
        }
    }
}
