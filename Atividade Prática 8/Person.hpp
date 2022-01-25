#ifndef PERSON_H
#define PERSON_H
#include <iostream>

class Person{
    private: 
        int Age; 
        std::string Name;
    public:
        Person(int& age, std::string& name);
        Person();
        virtual ~Person() = 0;
        virtual std::string getName() const;
        virtual int getAge() const;
        
        void setName(std::string& name);
        void setAge(int& age);

        /* To be overwritten in derived class: Friend */
        virtual std::string getBirthDay() const = 0;
        virtual void setBirthDay(std::string&) = 0;

        /* To be overwritten in derived class: Acquaintance */
        virtual std::string getEmail() const = 0;
        virtual void setEmail(std::string&) = 0;

        virtual std::string ObjectType() = 0;
};

#endif