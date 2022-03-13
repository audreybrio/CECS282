//Audrey Brio
//CECS 282-05
//Project 2 -  myDate
//10/01/2019

#include <iostream>
using namespace std;
#include "myDate.hpp"
#include <string>

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

myDate::myDate(){
    month = 5;
    day = 11;
    year = 1959;
}

myDate::myDate(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

void myDate::display(){
    string a;
    if(month < 13){
        if(month == 1){
            a = "January";
        }
        if(month == 2){
            a = "February";
        }
        if(month == 3){
            a = "March";
        }
        if(month == 4){
            a = "April";
        }
        if(month == 5){
            a = "May";
        }
        if(month == 6){
            a = "June";
        }
        if(month == 7){
            a = "July";
        }
        if(month == 8){
            a = "August";
        }
        if(month == 9){
            a = "September";
        }
        if(month == 10){
            a = "October";
        }
        if(month == 11){
            a = "November";
        }
        if(month == 12){
            a = "December";
        }
        cout << a << " " << day << ", " << year << " ";
    }
    else{
        // cout << month << " is not a valid month. Please enter a valid date.";
        month = 5;
        day = 11;
        year = 1959;
        cout << "May " << "11, " << "1959 ";
        
    }
    
}

void myDate::increaseDate(int a){
    int jd = 0;
    jd = Greg2Julian(month, day, year);
    jd = jd + a;
    Julian2Greg(jd, month, day, year);
    
}

void myDate::decreaseDate(int b){
    int jd = 0;
    jd = Greg2Julian(month, day, year);
    jd = jd - b;
    Julian2Greg(jd, month, day, year);
}

int myDate::daysBetween(myDate D){
    int date1;
    int date2;
    date1= Greg2Julian(month, day, year);
    
    int d = D.getDay();
    int m = D.getMonth();
    int y = D.getYear();
    date2 = Greg2Julian(m, d, y);
    int total;
    total = date2 - date1;
    return total;
}

int myDate::getDay(){
    return day;
}

int myDate::getYear(){
    return year;
}

int myDate::getMonth(){
    return month;
}

int myDate::dayOfYear(){
    int a = 0;
    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0){
                if(month == 1){
                    a = 0;
                }
                if(month == 2){
                    a = 31;
                }
                if(month == 3){
                    a = 60;
                }
                if(month == 4){
                    a = 91;
                }
                if(month == 5){
                    a = 121;
                }
                if(month == 6){
                    a = 152;
                }
                if(month == 7){
                    a = 182;
                }
                if(month == 8){
                    a = 213;
                }
                if(month == 9){
                    a = 244;
                }
                if(month == 10){
                    a = 274;
                }
                if(month == 11){
                    a = 305;
                }
                if(month == 12){
                    a = 335;
                }
                a =  a + day;
            }
            else{
                if(month == 1){
                    a = 0;
                }
                if(month == 2){
                    a = 31;
                }
                if(month == 3){
                    a = 59;
                }
                if(month == 4){
                    a = 90;
                }
                if(month == 5){
                    a = 120;
                }
                if(month == 6){
                    a = 151;
                }
                if(month == 7){
                    a = 181;
                }
                if(month == 8){
                    a = 212;
                }
                if(month == 9){
                    a = 243;
                }
                if(month == 10){
                    a = 273;
                }
                if(month == 11){
                    a = 304;
                }
                if(month == 12){
                    a = 334;
                }
                a =  a + day;
            }
        }
        else{
            if(month == 1){
                a = 0;
            }
            if(month == 2){
                a = 31;
            }
            if(month == 3){
                a = 60;
            }
            if(month == 4){
                a = 91;
            }
            if(month == 5){
                a = 121;
            }
            if(month == 6){
                a = 152;
            }
            if(month == 7){
                a = 182;
            }
            if(month == 8){
                a = 213;
            }
            if(month == 9){
                a = 244;
            }
            if(month == 10){
                a = 274;
            }
            if(month == 11){
                a = 305;
            }
            if(month == 12){
                a = 335;
            }
            a =  a + day;
        }
    }
    else{
        if(month == 1){
            a = 0;
        }
        if(month == 2){
            a = 31;
        }
        if(month == 3){
            a = 59;
        }
        if(month == 4){
            a = 90;
        }
        if(month == 5){
            a = 120;
        }
        if(month == 6){
            a = 151;
        }
        if(month == 7){
            a = 181;
        }
        if(month == 8){
            a = 212;
        }
        if(month == 9){
            a = 243;
        }
        if(month == 10){
            a = 273;
        }
        if(month == 11){
            a = 304;
        }
        if(month == 12){
            a = 334;
        }
        a =  a + day;
    }
    
    return a;
}

string myDate::dayName(){
    int a = 0;
    int total;
    if(month == 1){
        a = 1;
    }
    if(month == 2){
        a = 4;
    }
    if(month == 3){
        a = 4;
    }
    if(month == 4){
        a = 0;
    }
    if(month == 5){
        a = 2;
    }
    if(month == 6){
        a = 5;
    }
    if(month == 7){
        a = 0;
    }
    if(month == 8){
        a = 3;
    }
    if(month == 9){
        a = 6;
    }
    if(month == 10){
        a = 1;
    }
    if(month == 11){
        a = 4;
    }
    if(month == 12){
        a = 6;
    }
    string b = to_string(year);
    string c = b.substr(0,2);
    string d = b.substr(2,3);
    int e = stoi(c);
    int f = stoi(d);
    int g = 0;
    if(e == 15){
        g = 0;
    }
    if(e == 16){
        g = 6;
    }
    if(e == 17){
        g = 4;
    }
    if(e == 18){
        g = 2;
    }
    if(e == 19){
        g = 0;
    }
    if(e == 20){
        g = 6;
    }
    int h = f / 4;
    total =  a + day + g + f + h;
    int i = total % 7;
    string j = "";
    if(i == 0){
        j = "Saturday";
    }
    if(i == 1){
        j = "Sunday";
    }
    if(i == 2){
        j = "Monday";
    }
    if(i == 3){
        j = "Tuesday";
    }
    if(i == 4){
        j = "Wednesday";
    }
    if(i == 5){
        j = "Thursday";
    }
    if(i == 6){
        j = "Friday";
    }
    return j;
}

string myDate::formatDate(){
    string a = "";
    string b = "";
    if(month == 1){
        a = "January";
    }
    if(month == 2){
        a = "February";
    }
    if(month == 3){
        a = "March";
    }
    if(month == 4){
        a = "April";
    }
    if(month == 5){
        a = "May";
    }
    if(month == 6){
        a = "June";
    }
    if(month == 7){
        a = "July";
    }
    if(month == 8){
        a = "August";
    }
    if(month == 9){
        a = "September";
    }
    if(month == 10){
        a = "October";
    }
    if(month == 11){
        a = "November";
    }
    if(month == 12){
        a = "December";
    }
    b = a + " " + std::to_string(day) + ", " + std::to_string(year);
    return b;
}
