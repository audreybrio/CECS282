//Audrey Brio
//CECS 282-05
//Project 2 -  myDate
//10/01/2019

#ifndef myDate_hpp
#define myDate_hpp

#include <iostream>
//#include <CalendarStore/CalendarStore.h>
using namespace std;

class myDate
{
    
private:
    int day;
    int month;
    int year;
    
public:
    myDate();
    myDate(int, int, int);
    void display();
    void increaseDate(int);
    void decreaseDate(int);
    int daysBetween(myDate);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    string dayName();
    string formatDate();
    //string toString();
    
};

#endif /* myDate_hpp */
