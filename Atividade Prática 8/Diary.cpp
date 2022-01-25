#include "Diary.hpp"

Diary::Diary(int capacity) : DiaryCapacity(capacity), NumberFriends(0), NumberAcquaintances(0){
    People.reserve(DiaryCapacity);
    RandomizePerson();
}

Diary::~Diary(){}

void Diary::RandomizePerson(){
    for (int i = 0; i < DiaryCapacity; i++){
        std::random_device rd; 
        std::mt19937 gen(rd()); 
        std::uniform_int_distribution<> distr(1, 2); 
        int Friendship = distr(gen);
        if (Friendship == 1){
            People.push_back(new Friend());
            this -> NumberFriends = ++NumberFriends;
        }else if (Friendship == 2){
            People.push_back(new Acquaintance());
            this -> NumberAcquaintances = ++NumberAcquaintances;
        }
    }
    
}
 int Diary::getNumberFriends() const {return NumberFriends;}
 int Diary::getNumberAcquaintances() const {return NumberAcquaintances;}


void Diary::addInfos(){
    std::string InfosStr;
    int InfoInt;

    for (auto it : People){
        if (it -> ObjectType() == "Friend"){
            std::cout << "Insert infos for a friend: " << std::endl;
            std::cout << "Name: "; 
               /*  std::getline(std::cin, InfosStr); */
                std::cin >> InfosStr;
                it -> setName(InfosStr);
            std::cout << "Age: ";
                std::cin >> InfoInt;
                it -> setAge(InfoInt);
            std::cout << "Birthday: ";
                /* std::getline(std::cin, InfosStr); */
                std::cin >> InfosStr;
                it -> setBirthDay(InfosStr);
        } else{
            std::cout << "Insert infos for a acquaintance: " << std::endl;
            std::cout << "Name: "; 
                /* std::getline(std::cin, InfosStr); */
                std::cin >> InfosStr;
                it -> setName(InfosStr);
            std::cout << "Age: ";
                std::cin >> InfoInt;
                it -> setAge(InfoInt);
            std::cout << "Email: ";
                /* std::getline(std::cin, InfosStr); */
                std::cin >> InfosStr;
                it -> setEmail(InfosStr);
        }
    }
}

void Diary::PrintBirthday(){
    for (auto it : People){
        if (it -> ObjectType() == "Friend"){
            std::cout << "The birthday of your friend " << it -> getName() << " is on: " << std::endl;
            std::cout << it -> getBirthDay() << std::endl;
            std::cout << "and he/she will be: " << it -> getAge() + 1 << " years old." << std::endl;
            std::cout << std::endl;
        }
    }
}

void Diary::PrintEmail(){
     for (auto it : People){
        if (it -> ObjectType() == "Acquaintance"){
            std::cout << "The E-mail of your acquaintance " << it -> getName() << " is: " << std::endl;
            std::cout << it -> getEmail() << std::endl;
            std::cout << std::endl;
        }
    }
} 