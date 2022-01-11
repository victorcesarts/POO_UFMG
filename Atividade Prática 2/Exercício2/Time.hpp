#include <iostream>

class Time
{
private:
    int _day; 
    int _hour;
    int _minutes;
    int _seconds;

public:
    Time(int day=01, int hour=01, int minute=01, int second=01);
    ~Time();

    //check if the objects have the right statements
    Time isRight();

    //sum of two objects
    Time sum(Time &t);

    //allows user input
    void in();

    //print the time
    void print();

    //increment seconds
    Time increasing();

    //decrement seconds
    Time decreasing();

    //geters
    int getDay() const;
    int getHour() const;
    int getMinutes() const;
    int getSeconds() const;

    //setters
    void setDay(int day);
    void setHour(int hour);
    void setMinutes(int minutes);
    void setSeconds(int second);
};
