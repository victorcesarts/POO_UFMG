#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <iostream>

class Professor{
        std::string nome;
    public:
        Professor(std::string n);
        virtual ~Professor();
        std::string getName() const;
    
        virtual double getSalario() = 0;
        
};

#endif

