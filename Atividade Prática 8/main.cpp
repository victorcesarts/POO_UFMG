#include "Diary.hpp"

int main(){
    int capacity;
    std::cout << "What's the size of the diary?" << std::endl;
    std::cin >> capacity;
    Diary D(capacity);
    std::cout << "You have " << D.getNumberFriends() << " friends and "; 
    std::cout <<  D.getNumberAcquaintances() << " acquaintances." << std::endl; 
    
    D.addInfos();

    std::cout << "-----PRINTING FRIENDS-----" << std::endl;
    D.PrintBirthday();
    std::cout << "-----PRINTING ACQUAINTANCES-----" << std::endl;
    D.PrintEmail();

    return 0;
};