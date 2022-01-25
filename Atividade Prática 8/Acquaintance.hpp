#ifndef ACQUAINTANCE_H
#define ACQUAINTANCE_H
#include <iostream>
#include "Person.hpp"

class Acquaintance : public Person{
    private:  
        std::string Email;
    public:
        Acquaintance();
        ~Acquaintance();
        
        virtual std::string getEmail() const override;
        virtual void setEmail(std::string&) override;
        
        
        /* Only for Friends */
        std::string getBirthDay() const override;
        void setBirthDay(std::string& birthday) override;

        virtual std::string ObjectType() override;
};

#endif