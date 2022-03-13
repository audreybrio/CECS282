//Audrey Brio
//CECS 282-05
//Project 4 -  Overlading Operators
//11/05/2019

#include <iostream>
using namespace std;
#include "upDate.hpp"

int upDate::count = 0;

int Greg2Julian(int month, int day, int year){
    int i;
    int j;
    int k;
    int jd;
    i = year;
    j = month;
    k = day;
    jd = k-32075+1461*(i+4800+(j-14)/12)/4+367*(j-2-(j-14)/12*12)/12-3*((i+4900+(j-14)/12)/100)/4;
    
    return jd;
}


void Julian2Greg(int JD, int & month, int & day, int & year){
    int i;
    int j;
    int k;
    int L;
    int N;
    
    L = JD + 68569;
    N = 4 * L / 146097;
    L = L - (146097 * N + 3) / 4;
    i = 4000 * (L+1) / 1461001;
    L = L - 1461 * i / 4 + 31;
    j = 80 * L / 2447;
    k = L - 2447 * j / 80;
    L = j / 11;
    j = j + 2 - 12 * L;
    i = 100 * (N-49) + i + L;
    
    year = i;
    month = j;
    day = k;
}


upDate::upDate(){
    dptr = new int[3];
    dptr[0] = 5;
    dptr[1] = 11;
    dptr[2] = 1959;
    count++;
    //upDate(*this);
}

upDate::upDate(int m, int d, int y){
    dptr = new int[3];
    dptr[0] = m;
    dptr[1] = d;
    dptr[2] = y;
    count++;
    //upDate(*this);
}

upDate::upDate(int j){
    dptr = new int[3];
    Julian2Greg(j, dptr[0], dptr[1], dptr[2]);
    count++;
    
}

upDate::~upDate(){
    delete[] dptr;
    count--;
}

void upDate::setDate(int m, int d, int y){
    dptr = new int[3];
    dptr[0] = m;
    dptr[1] = d;
    dptr[2] = y;
    
}

int upDate::getMonth(){
    int a = dptr[0];
    return a;
}

int upDate::getDay(){
    int b = dptr[1];
    return b;
}

int upDate::getYear(){
    int c = dptr[2];
    return c;
}

string upDate::getMonthName(){
    string a = "";
    if(dptr[0] == 1){
        a = "January";
    }
    if(dptr[0] == 2){
        a = "February";
    }
    if(dptr[0] == 3){
        a = "March";
    }
    if(dptr[0] == 4){
        a = "April";
    }
    if(dptr[0] == 5){
        a = "May";
    }
    if(dptr[0] == 6){
        a = "June";
    }
    if(dptr[0] == 7){
        a = "July";
    }
    if(dptr[0] == 8){
        a = "August";
    }
    if(dptr[0] == 9){
        a = "September";
    }
    if(dptr[0] == 10){
        a = "October";
    }
    if(dptr[0] == 11){
        a = "November";
    }
    if(dptr[0] == 12){
        a = "December";
    }
    return a;
}



upDate::upDate(const upDate & D){
    dptr = new int[3];
    dptr[0] = D.dptr[0];
    dptr[1] = D.dptr[1];
    dptr[2] = D.dptr[2];
    count++;
    
}

upDate upDate::operator+=(int a){
    int month = getMonth();
    int day = getDay();
    int year = getYear();
    int jd = 0;
    jd = Greg2Julian(month, day, year);
    jd = jd + a;
    Julian2Greg(jd, dptr[0], dptr[1], dptr[2]);
    upDate D2( dptr[0], dptr[1], dptr[2]);
    return D2;
    
}

upDate upDate::operator-=(int b){
    int month = getMonth();
    int day = getDay();
    int year = getYear();
    int jd = 0;
    jd = Greg2Julian(month, day, year);
    jd = jd - b;
    Julian2Greg(jd, dptr[0], dptr[1], dptr[2]);
    upDate D2( dptr[0], dptr[1], dptr[2]);
    return D2;
}

upDate upDate::operator+(int a){
    upDate D2(dptr[0], dptr[1], dptr[2]);
    int month = D2.getMonth();
    int day = D2.getDay();
    int year = D2.getYear();
    int jd = 0;
    jd = Greg2Julian(month, day, year);
    jd = jd + a;
    Julian2Greg(jd, D2.dptr[0], D2.dptr[1], D2.dptr[2]);
    return D2;
}

upDate upDate::operator-(int b){
    upDate D2(dptr[0], dptr[1], dptr[2]);
    int month = D2.getMonth();
    int day = D2.getDay();
    int year = D2.getYear();
    int jd = 0;
    jd = Greg2Julian(month, day, year);
    jd = jd - b;
    Julian2Greg(jd, D2.dptr[0], D2.dptr[1], D2.dptr[2]);
    return D2;
}



int upDate::operator-(upDate D){
    int date1;
    int date2;
    date1 = Greg2Julian(dptr[0], dptr[1], dptr[2]);
    int d = D.getDay();
    int m = D.getMonth();
    int y = D.getYear();
    date2 = Greg2Julian(m, d, y);
    int total;
    total = date1 - date2;
    return total;
    
}

upDate operator+(int a, upDate D){
    upDate D2(D.dptr[0], D.dptr[1], D.dptr[2]);
    int month = D2.getMonth();
    int day = D2.getDay();
    int year = D2.getYear();
    int jd = 0;
    jd = Greg2Julian(month, day, year);
    jd = jd + a;
    Julian2Greg(jd, D2.dptr[0], D2.dptr[1], D2.dptr[2]);
    return D2;
}

upDate upDate::operator++(){ //++d1
    *this +=1;
    return *this;
    
}

upDate upDate::operator++(int a){ //d1++
    *this +=1;
    return *this;
}

upDate upDate::operator--(){ //--d1
    *this -=1;
    return *this;
    
}

upDate upDate::operator--(int a){ //d1--
    *this -=1;
    return *this;
}

ostream& operator<<(ostream& os, const upDate& D){
    os << D.dptr[0] << "/" << D.dptr[1] << "/" << D.dptr[2];
    return os;
    
}

 //count = 0;
 int upDate::getDateCount(){
    //count = count + 1;
    return count;
}

int upDate::julian(){
    int x = Greg2Julian(dptr[0], dptr[1], dptr[2]);
    return x;
}

bool upDate::operator==(upDate D){
    bool a = false;
    int m = dptr[0];
    int d = dptr[1];
    int y = dptr[2];
    int month = D.dptr[0];
    int day = D.dptr[1];
    int year = D.dptr[2];
    if(m == month && d == day && y==year){
        a = true;
    }
    else{
        a = false;
    }
    return a;
}

bool upDate::operator<(upDate D){
    bool a = false;
    int date1;
    int date2;
    date1 = Greg2Julian(dptr[0], dptr[1], dptr[2]);
    int d = D.getDay();
    int m = D.getMonth();
    int y = D.getYear();
    date2 = Greg2Julian(m, d, y);
    if(date1 < date2){
        a = true;
    }
    else{
        a = false;
    }
    return a;
}

bool upDate::operator>(upDate D){
    bool a = false;
    int date1;
    int date2;
    date1 = Greg2Julian(dptr[0], dptr[1], dptr[2]);
    int d = D.getDay();
    int m = D.getMonth();
    int y = D.getYear();
    date2 = Greg2Julian(m, d, y);
    if(date1 > date2){
        a = true;
    }
    else{
        a = false;
    }
    return a;
}


