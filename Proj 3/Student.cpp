//Audrey Brio
//CECS 282-05
//Project 3 -  Structs and Pointers
//10/15/2019

#include "Student.hpp"
#include <iostream>
#include <iomanip>

void createStudents(student **s){ //bc array is like a pointer, its the same; s is a pointer to a pointer to a student
    
    s[0] = new student; //pointer to a student
    char name1[] = "Michael Scott";
    strcpy(s[0] -> name, name1);
    (*s[0]).ID = 174930;
    (*s[0]).bday = myDate(5, 5, 1999);
    (*s[0]).grade = 'C';
    (*s[0]).hometown = "Scranton";
    
    s[1] = new student; //pointer to a student
    char name2[] = "Blair Waldorf";
    strcpy(s[1] -> name, name2);
    (*s[1]).ID = 928343;
    (*s[1]).bday = myDate(10, 20, 2000);
    (*s[1]).grade = 'A';
    (*s[1]).hometown = "Upper East Side";
    
    s[2] = new student; //pointer to a student
    char name3[] = "Nathan Scott";
    strcpy(s[2] -> name, name3);
    (*s[2]).ID = 478932;
    (*s[2]).bday = myDate(8, 12, 2002);
    (*s[2]).grade = 'D';
    (*s[2]).hometown = "One Tree Hill";
    
    s[3] = new student; //pointer to a student
    char name4[] = "Rachel Green";
    strcpy(s[3] -> name, name4);
    (*s[3]).ID = 829320;
    (*s[3]).bday = myDate(2, 17, 2001);
    (*s[3]).grade = 'F';
    (*s[3]).hometown = "Manhattan";
    
    s[4] = new student; //pointer to a student
    char name5[] = "Jack Pearson";
    strcpy(s[4] -> name, name5);
    (*s[4]).ID = 792473;
    (*s[4]).bday = myDate(6, 9, 1999);
    (*s[4]).grade = 'B';
    (*s[4]).hometown = "Philadelphia";
    
    s[5] = new student; //pointer to a student
    char name6[] = "Meredith Grey";
    strcpy(s[5] -> name, name6);
    (*s[5]).ID = 293028;
    (*s[5]).bday = myDate(7, 30, 2001);
    (*s[5]).grade = 'A';
    (*s[5]).hometown = "Boston";
    
    s[6] = new student; //pointer to a student
    char name7[] = "Chris Brio";
    strcpy(s[6] -> name, name7);
    (*s[6]).ID = 239022;
    (*s[6]).bday = myDate(6, 6, 2002);
    (*s[6]).grade = 'D';
    (*s[6]).hometown = "Long Beach";
    
    s[7] = new student; //pointer to a student
    char name8[] = "Makena Seal";
    strcpy(s[7] -> name, name8);
    (*s[7]).ID = 839201;
    (*s[7]).bday = myDate(2, 3, 1999);
    (*s[7]).grade = 'B';
    (*s[7]).hometown = "Costa Mesa";
    
    s[8] = new student; //pointer to a student
    char name9[] = "Klaus Mikaelson";
    strcpy(s[8] -> name, name9);
    (*s[8]).ID = 578329;
    (*s[8]).bday = myDate(4, 12, 2000);
    (*s[8]).grade = 'C';
    (*s[8]).hometown = "New Orleans";
    
}


void display(student * s[], int size){
    cout << left <<  setw(15) <<"Student ID" << left <<  setw(20) << " Name " << left <<  setw(12) << " Grade " << left << setw(22) <<  " Birthday " << " Hometown" << endl;
    for (int i = 0; i < size; i++){
        cout << left <<  setw(16) << s[i] -> ID;
        cout << left << setw(20) << s[i] -> name;
        cout << left << setw(12) << s[i] -> grade;
        cout << left << setw(22) << s[i] -> bday.formatDate();
        cout << s[i] -> hometown << endl;
    }
    cout << endl;
}

void copyArray(student * d[], student * s[]){
    for (int i = 0; i < 9; i++){
        d[i] = s[i];
    }
}

void sortName(student * s[]){
    for(int i = 0; i < 9-1; i++){
        for(int j = 0; j < 9-i-1; j++){
            if(strcmp((*(s[j])).name, (*(s[j+1])).name) > 0){
                student * temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

void sortID(student * s[]){
    for(int i = 0; i < 9-1; i++){
        for(int j = 0; j < 9-i-1; j++){
            if((*(s[j])).ID > (*(s[j+1])).ID){
                student * temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

void sortBirthday(student * s[]){
    for(int i = 0; i < 9-1; i++){
        for(int j = 0; j < 9-i-1; j++){
            if((*(s[j])).bday.daysBetween((*(s[j+1])).bday) < 0){
                student * temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
    
}

void sortHometown(student * s[]){
    for(int i = 0; i < 9-1; i++){
        for(int j = 0; j < 9-i-1; j++){
            if((*(s[j])).hometown.compare((*(s[j+1])).hometown) > 0){
                student * temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

}

void sortGrade(student * s[]){
    for(int i = 0; i < 9-1; i++){
        for(int j = 0; j < 9-i-1; j++){
            if((*(s[j])).grade > (*(s[j+1])).grade){
                student * temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

}

