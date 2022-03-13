//Audrey Brio
//CECS 282-05
//Project 4 -  Overlading Operators
//11/05/2019

#ifndef upDate_hpp
#define upDate_hpp

#include <iostream>
using namespace std;

class upDate{
    
private:
    int * dptr;
    static int count; //static int count;
    
public:
    //static int count;
    upDate();
    upDate(int, int, int);
    upDate(int);
    ~upDate();
    
    upDate(const upDate&);
    
    void setDate(int, int, int);
    int getMonth();
    int getDay();
    int getYear();
    string getMonthName();
    
    upDate operator+=(int);
    upDate operator-=(int);
    
    upDate operator+(int);
    upDate operator-(int);
    friend upDate operator+(int,upDate);
    
    int operator-(upDate);
    
    upDate operator++(int); //d1++
    upDate operator++(); //++d1
    upDate operator--(int); //d1--
    upDate operator--(); //--d1
    
    bool operator==(upDate);
    bool operator<(upDate);
    bool operator>(upDate);
    
    static int getDateCount();
    int julian();
    
    friend ostream& operator<<(ostream&, const upDate&);

    
    
};


#endif /* upDate_hpp */
