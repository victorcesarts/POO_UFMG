#ifndef FRIEND_H
#define FRIEND_H
#include <iostream>
#include "Person.hpp"

class Friend : public Person{
    private:  
        std::string BirthDay;
    public:
        Friend();
        ~Friend();
        std::string getBirthDay() const override;
        void setBirthDay(std::string& birthday) override;

        /* Only for acquaintances */
        virtual std::string getEmail() const override;
        virtual void setEmail(std::string&) override;

        virtual std::string ObjectType() override;
};

#endif