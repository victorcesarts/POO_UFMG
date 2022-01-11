#include "Time.hpp"

Time::Time(int day, int hour, int minutes, int seconds){
    setDay(day);
    setHour(hour);
    setMinutes(minutes);
    setSeconds(seconds);
    isRight();
}

Time::~Time(){}

//setters
void Time::setDay(int day){
    this -> _day = day;
}
void Time::setHour(int hour){
    this -> _hour = hour;
}
void Time::setMinutes(int minutes){
    this -> _minutes = minutes;
}
void Time::setSeconds(int seconds){
    this -> _seconds = seconds;
}

//getters
int Time::getDay() const{
    return _day;
}
int Time::getHour() const{
    return _hour;
}
int Time::getMinutes() const{
    return _minutes;
}
int Time::getSeconds() const{
    return _seconds;
}

Time Time::isRight(){
    int d = this -> getDay();
    int h = this -> getHour();
    int m = this -> getMinutes();
    int s = this -> getSeconds();

    //auxiliar for use of recursive call
    int aux = 0;

    //verifying seconds
    if(s < 0 || s > 59){
        if(s > 59){
            this -> setSeconds(s - 60);
            this -> setMinutes(m += 1);
        }else{
            this -> setSeconds(60 + s);
            this -> setMinutes(m -= 1);
        }
        aux += 1;
    }

    //verifying minutes
    if (m < 0 || m > 59){
        if(m > 59){
            this -> setMinutes(m - 60);
            this -> setHour(h += 1);
        }else{
            this -> setMinutes(60 + m);
            this -> setHour(h -= 1);
        }
        aux += 1;
    }

    //verifying hours
    if (h < 0 || h > 23){
        if(h > 23){
            this -> setHour(h - 24);
            this -> setDay(d += 1);
        }else{
            this -> setHour(24 + h);
            this -> setDay(d -= 1);
        }
        aux += 1;
    }

    //verifying days
    if (d < 0){
        this -> setDay(0);
    }

    //recursive call
    if (aux > 0){
        isRight();
    }
    return *this;
}

Time Time::sum(Time &t){
    this -> setDay((this -> getDay()) + t.getDay());
    this -> setHour((this -> getHour()) + t.getHour());
    this -> setMinutes((this -> getMinutes()) + t.getMinutes());
    this -> setSeconds((this -> getSeconds()) + t.getSeconds());
    this -> isRight();
    return *this;
}

void Time::in(){
    int day, hour, minutes, seconds;

    std::cout << "Enter a numeric value for the day" << std::endl;
    std::cin >> day;
    this -> setDay(day);
    
    std::cout <<"Enter a numeric value for hours" << std::endl;
    std::cin >> hour;
    this -> setHour(hour);

    std::cout << "Enter a numeric value for minutes" << std::endl;
    std::cin >> minutes;
    this -> setMinutes(minutes);

    std::cout << "Enter a numeric value for seconds" << std::endl;
    std::cin >> seconds;
    this -> setSeconds(seconds);

    this -> isRight();
}

void Time::print(){
    std::cout << "Day: " << this -> getDay() << ", ";
    std::cout << this -> getHour() << " Hours" << ", ";
    std::cout << this -> getMinutes() << " Minutes" << " ";
    std::cout << "and " << this -> getSeconds() << " Seconds" << std::endl;
}

Time Time::increasing(){
    int secPlusOne = this -> getSeconds(); 
    secPlusOne += 1;
    this -> setSeconds(secPlusOne);
    this -> isRight();
    return *this;
}

Time Time::decreasing(){
    int secPlusOne = this -> getSeconds(); 
    secPlusOne -= 1;
    this -> setSeconds(secPlusOne);
    this -> isRight();
    return *this;
}