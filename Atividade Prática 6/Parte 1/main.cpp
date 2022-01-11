/*
VÍCTOR CÉSAR TEIXEIRA SANTOS 
ENGENHARIA DE CONTROLE E AUTOMAÇÃO - UFMG
MATRÍCULA - 2020021832
*/
#include <iostream>
#include<cmath>

//Fbonacci Sequence Generator
template <typename U>
U sequence(const int& n){
    U a = 0, b = 1, c;
    int i;
    if(n == 0)
        return a;
    for(i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }        
    return b;
}

//To check if the sequence value is correct or
//it's beyond the values that the given type can handle
template <typename U>
int isRight(U x){
    if(x < 0 || std::isinf(x))
        return 1;
    return 0;
}

int main(){
    int n = 40;

std::cout << "------------n = 40------------" <<  std::endl;
    float x = sequence<float>(n);
    if (isRight(x) == 0)
        std::cout << "As float: " << x << std::endl;
    else std::cout << "Error as float" << std::endl;

    int y = sequence<int>(n);
    if (isRight(y) == 0)
        std::cout << "As int: " << y << std::endl;
    else std::cout << "Error as int" << std::endl;

    double z = sequence<double>(n);
    if (isRight(z) == 0)
        std::cout << "As double: " << z << std::endl;
    else std::cout << "Error as double" << std::endl;

    long q = sequence<long>(n);
    if (isRight(q) == 0)
        std::cout << "As long: " << q << std::endl;
    else std::cout << "Error as long" << std::endl;
std::cout << "-------------------------------" <<  std::endl;

std::cout << "------------n = 200------------" <<  std::endl;
    n = 200;
    x = sequence<float>(n);
    if (isRight(x) == 0)
        std::cout << "As float: " << x << std::endl;
    else std::cout << "Error as float" << std::endl;

    y = sequence<int>(n);
    if (isRight(y) == 0)
        std::cout << "As int: " << y << std::endl;
    else std::cout << "Error as int" << std::endl;

    z = sequence<double>(n);
    if (isRight(z) == 0)
        std::cout << "As double: " << z << std::endl;
    else std::cout << "Error as double" << std::endl;

    q = sequence<long>(n);
    if (isRight(q) == 0)
        std::cout << "As long: " << q << std::endl;
    else std::cout << "Error as long" << std::endl;
std::cout << "-------------------------------" <<  std::endl;
    return 0;
}

