#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include <fstream>

template <class TValor> class Matrix;

template <class TValor> 
std::ostream& operator<<(std::ostream&, const Matrix<TValor>&);
template <class TValor> 
std::istream& operator>>(std::istream& in, const Matrix<TValor>& k);

template <class TValor> 
class Matrix {
    private:

        TValor** m; // m é um array 2D a ser implementado como um pointer de pointers
        int nRows;  // numero de linhas
        int nCols;  //  numero de colunas
        Matrix auxMultiply(const Matrix& k);

    public:
        
        // Construtores
        Matrix();                           
        Matrix(int rows, int cols, const TValor &value = 0.0);
        Matrix(std::ifstream& myFile);
        Matrix(const Matrix& that);
        // destrutor
        ~Matrix();
    
        // basic getters
        int getRows() const;
        int getCols() const;
        //Get value from a given position in matrix
        TValor get(int row, int col) const;
        void set(int row, int col);
        
        //Just print the matrix
        void print() const;
        //Get the indetity matrix
        void unit();
        //Change all values to 0
        void zeros();
        //Change all values to 1
        void ones();

        /*  
        OVERLOADING OPERATORS
        */
       //To acess specific position in a matrix in order to change its value
        TValor& operator()(int x, int y);

        //Assign a value to a specific position in matrix
        Matrix& operator=(const TValor& value);

        //Add two matrices
        Matrix operator+(const Matrix& k);

        //Assign to a matrix the value of a matrix minus another matrix
        Matrix operator-(const Matrix& k);
        
        //To multiply two given matrices
        Matrix operator*(const Matrix& k);
        
        //To calculate the transpose of a matrix
        Matrix operator~();

        //Assign matrix to another matrix
        void operator=(const Matrix& k);

        //Assign to a matrix its value minus value of other matrix
        void operator-=(const Matrix& k);

        //Assign to a matrix its values plus values of another matrix
        void operator+=(const Matrix& k);

        //To multiply a matrix by a given value
       void operator*=(const TValor& value);

        //To multiply called matrix by a given matrix
        void operator*=(const Matrix& k);

        //To verify if two matrices are equal
        bool operator==(const Matrix& k);

        //To verify if two matrices are NOT equal
        bool operator!=(const Matrix& k);

        
};

/*  
Constructors
*/
template <class TValor> 
Matrix<TValor>::Matrix() : nRows(0), nCols(0){
    m = new TValor*[nRows];
    m[0] = new TValor[nCols];
    m[0][0] = 0;
}

template <class TValor> 
Matrix<TValor>::Matrix(int rows, int cols, const TValor &value) : nRows(rows), nCols(cols){
    m = new TValor*[nRows];  
    for (int i = 0; i < nRows; i++){
        m[i] = new TValor[nCols];
        for (int j = 0; j < nCols; j++){
            m[i][j] = value;
        }
    }
}

template <class TValor> 
Matrix<TValor>::Matrix(std::ifstream& myFile){
    TValor value = 0.0;
    while (myFile >> nRows >> nCols >> value){
        myFile.clear();
    }
    m = new TValor*[nRows];  
    for (int i = 0; i < nRows; i++){
        m[i] = new TValor[nCols];
        for (int j = 0; j < nCols; j++){
            m[i][j] = value;
        }
    }
}

template <class TValor> 
Matrix<TValor>::Matrix(const Matrix& that) : nRows(that.getRows()), nCols(that.getCols()){
    m = new TValor*[nRows];  
    for (int i = 0; i < nRows; i++){
        m[i] = new TValor[nCols];
        for (int j = 0; j < nCols; j++){
            m[i][j] = that.get(i, j);
        }
    }
}
/*  
Destructor
*/
template <class TValor> 
Matrix<TValor>::~Matrix(){
    for (int i = 0; i < nRows; i++){
        delete[] m[i];
    }
    delete[] m;
}

template <class TValor> 
inline int Matrix<TValor>::getRows() const {return nRows;}

template <class TValor> 
inline int Matrix<TValor>::getCols() const {return nCols;}

template <class TValor> 
inline TValor Matrix<TValor>::get(int row, int col) const {return m[row][col];}

template <class TValor> 
inline void Matrix<TValor>::set(int row, int col){nRows = row; nCols = col;}

template <class TValor> 
void Matrix<TValor>::print() const{
    for (int i = 0; i < nRows; i++){
        for (int j = 0; j < nCols; j++){
            std::cout << this -> get(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

template <class TValor> 
void Matrix<TValor>::unit(){
    if(nRows == nCols){
        for (int i = 0; i < nRows; i++){
            m[i] = new TValor[nCols];
            for (int j = 0; j < nCols; j++){
                if(i==j)
                    m[i][j] = 1;
                else    
                    m[i][j] = 0;
            }
        }
    }else
        throw std::out_of_range("ERROR: It's not possible convert this matrix to an identity matrix. They must have Rows = Columns");
}

template <class TValor> 
void Matrix<TValor>::zeros(){
    for (int i = 0; i < nRows; i++){
        m[i] = new TValor[nCols];
        for (int j = 0; j < nCols; j++){
            m[i][j] = 0;
        }
    }
}

template <class TValor> 
void Matrix<TValor>::ones(){
    for (int i = 0; i < nRows; i++){
        m[i] = new TValor[nCols];
        for (int j = 0; j < nCols; j++){
            m[i][j] = 1;
        }
    }
}

/*
This function is to help in multiplication of matrices that use same code
*/
template <class TValor> 
Matrix<TValor> Matrix<TValor>::auxMultiply(const Matrix& k){
    int Colsk = k.getCols();
    Matrix Result(nRows, Colsk);
    for(int h = 0; h < nRows; h++){
        int aux = 0;
        for (int i = 0; i < Colsk; i++){
            int tempResult = 0;
            for (int j = 0; j < nCols; j++){
                tempResult  += this -> m[h][j]*k.m[j][i];
            }
            Result.m[h][aux] = tempResult;
            aux++;
        }
    }
    return Result;
}

/*
--------------------------------------
Begin of overload operators section
--------------------------------------
*/

template <class TValor> 
TValor& Matrix<TValor>::operator()(int x, int y){
    int rows = (this -> getRows()) - 1;
    int cols = (this -> getCols()) -1;
    if(x <= rows && y <= cols){
        return m[x][y];
    }else
        throw std::out_of_range("ERROR: Number of rows and/or columns of the matrix does not match x and/or y values. Consider first row index = 0 and first column index = 0");
}

template <class TValor> 
Matrix<TValor>& Matrix<TValor>::operator=(const TValor& value){
    return *this;
}

template <class TValor> 
Matrix<TValor> Matrix<TValor>::operator+(const Matrix& k){
    if(k.getRows() == nRows && k.getCols() == nCols){
        Matrix newM(nRows, nCols);
        for (int i = 0; i < nRows; i++){
                for (int j = 0; j < nCols; j++){
                    newM.m[i][j] = this -> m[i][j] + k.m[i][j];
            }
        }
        return newM;
    } else  
    throw std::out_of_range("ERROR: You cannot add two matrices of differents dimensions");
}

template <class TValor> 
Matrix<TValor> Matrix<TValor>::operator-(const Matrix& k){
    if(k.getRows() == nRows  && k.getCols() == nCols){
        Matrix newM(nRows, nCols);
        for (int i = 0; i < nRows; i++){
                for (int j = 0; j < nCols; j++){
                    newM.m[i][j] = this -> m[i][j] - k.m[i][j];
            }
        }
        return newM;
    } else  
    throw std::out_of_range("ERROR: You cannot subtract two matrices of different dimensions");
}

template <class TValor> 
Matrix<TValor> Matrix<TValor>::operator*(const Matrix& k){
    int Rowsk = k.getRows();
    if(nCols == Rowsk){
        return auxMultiply(k);
    } else  
    throw std::out_of_range("ERROR: To be possible to multiply two matrices, the number of columns of the first matrix must be equal to the number of rows of the second one");
}

template <class TValor> 
Matrix<TValor> Matrix<TValor>::operator~(){
    Matrix newM(nCols, nRows);
        for (int i = 0; i < nRows; i++){
            for (int j = 0; j < nCols; j++){
                newM.m[j][i] = this -> m[i][j];
            }
        }
    return newM;
}

template <class TValor> 
void Matrix<TValor>::operator=(const Matrix& k){
    int Rowsk = k.getRows();
    int Colsk = k.getCols();

    if(Rowsk == nRows  && Colsk == nCols){
    for (int i = 0; i < Rowsk; i++){
        for (int j = 0; j < Colsk; j++){
            this -> m[i][j] = k.m[i][j];
        }
    }
    }else{
        for (int i = 0; i < nRows; i++){
            delete[] m[i];
        }
        delete[] m;
        this -> set(Rowsk, Colsk);
        m = new TValor*[nRows];  
        for (int i = 0; i < Rowsk; i++){
            m[i] = new TValor[nCols];
            for (int j = 0; j < Colsk; j++){
                this -> m[i][j] = k.m[i][j];
            }
        }
    }
    
}

template <class TValor> 
void Matrix<TValor>::operator-=(const Matrix& k){
    
    if(k.getRows() == nRows  && k.getCols() == nCols){
        for (int i = 0; i < nRows; i++){
            for (int j = 0; j < nCols; j++){
                this -> m[i][j] = this -> m[i][j] - k.m[i][j];
            }
        }
    } else  
    throw std::out_of_range("ERROR: You cannot subtract two matrices of different dimensions");
}

template <class TValor> 
void Matrix<TValor>::operator+=(const Matrix& k){
    
    if(k.getRows() == nRows  && k.getCols() == nCols){
        for (int i = 0; i < nRows; i++){
            for (int j = 0; j < nCols; j++){
                this -> m[i][j] = this -> m[i][j] + k.m[i][j];
            }
        }
    } else  
    throw std::out_of_range("ERROR: You cannot subtract two matrices of different dimensions");
}

template <class TValor> 
void Matrix<TValor>::operator*=(const TValor& value){
    for (int i = 0; i < nRows; i++){
        for (int j = 0; j < nCols; j++){
            this -> m[i][j] = this -> m[i][j]*value;
        }
    }
}

template <class TValor> 
void Matrix<TValor>::operator*=(const Matrix&k){
    int Rowsk = k.getRows();
    int Colsk = k.getCols();

    if(nCols == Rowsk){
        Matrix Result = auxMultiply(k);
        //resizing matrix
        for (int i = 0; i < nRows; i++){
            delete[] m[i];
        }
        delete[] m;
        this -> set(nRows, Colsk);
        m = new TValor*[nRows];  
        for (int i = 0; i < nRows; i++){
            m[i] = new TValor[nCols];
            for (int j = 0; j < Colsk; j++){
                this -> m[i][j] = Result.m[i][j];
            }
        } 
    } else  
    throw std::out_of_range("ERROR: To be possible to multiply two matrices, the number of columns of the first matrix must be equal to the number of rows of the second one");
}

template <class TValor> 
bool Matrix<TValor>::operator==(const Matrix& k){
    bool result = true;
    if(nRows == k.getRows() && nCols == k.getCols()){
        for (int i = 0; i < nRows; i++){
            for (int j = 0; j < nCols; j++){
                if(this -> m[i][j] != k.m[i][j]){
                    result = false; break;
                }
            }
        }
    }else result = false;
    return result;
}

template <class TValor> 
bool Matrix<TValor>::operator!=(const Matrix& k){
    return !(operator==(k));
}

template <class TValor> 
std::ostream& operator<<(std::ostream& out, const Matrix<TValor>& k){
    int Rowsk = k.getRows();
    int Colsk = k.getCols();
    for (int i = 0; i < Rowsk; i++){
        for (int j = 0; j < Colsk; j++){
            out << k.get(i, j) << " ";
        }
        out << std::endl;        
    }
    return out;
}

template <class TValor> 
std::istream& operator>>(std::istream& in, const Matrix<TValor>& k){
    std::cout << "This matrix have " << k.getRows() << " ROWS and " 
    << k.getCols() << " COLUMNS." << " You'll need to insert up to " <<
    k.getRows()*k.getCols() << " values" << std::endl;

    int Rowsk = k.getRows();
    int Colsk = k.getCols();
    for (int i = 0; i < Rowsk; i++){
        for (int j = 0; j < Colsk; j++){
            in >> k.m[i][j];
        }      
    }
    return in;
}
#endif