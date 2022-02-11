#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <iostream>
using namespace std;

class Professor{
    private:
        string nome;
    public:
        Professor(std::string n);
        virtual ~Professor();
        
        string getName() const;
        virtual double getSalario() = 0;
        
};

#endif

