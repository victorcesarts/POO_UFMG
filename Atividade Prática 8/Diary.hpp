#ifndef DIARY_H
#define DIARY_H
#include <iostream>
#include <vector>
#include <random>
#include "Friend.hpp"
#include "Acquaintance.hpp"

class Diary{
    private:  
        int NumberFriends;
        int NumberAcquaintances;
        int DiaryCapacity;
        std::vector<Person*> People;

    public:
       Diary(int);
       ~Diary();

        int getNumberFriends() const;
        int getNumberAcquaintances() const;
        

        void RandomizePerson();
        void addInfos();
        void PrintBirthday();
        void PrintEmail(); 
};

#endif