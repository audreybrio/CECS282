//Audrey Brio
//CECS 282-05
//Project 3 -  Structs and Pointers
//10/15/2019

#include "Student.hpp"

#include <iostream>

void createStudents(student * people[]);
void display(student * people[], int s);
void copyArray(student * copyPeople[], student * people[]);
void sortID(student * sortI[]);
void sortName(student * sortN[]);
void sortGrade(student * sortG[]);
void sortBirthday(student * sortB[]);
void sortHometown(student * sortH[]);
int main(){
    int size = 9;
    student * people[9];
    createStudents(people);
  
    student * sortI[9];
    copyArray(sortI, people);
    sortID(sortI);
    
    student * sortN[9];
    copyArray(sortN, people);
    sortName(sortN);
    
    student * sortG[9];
    copyArray(sortG, people);
    sortGrade(sortG);
    
    student * sortB[9];
    copyArray(sortB, people);
    sortBirthday(sortB);
    
    student * sortH[9];
    copyArray(sortH, people);
    sortHometown(sortH);
    
    while(true){
        int choice;
        cout << "1) Display Original List" << endl;
        cout << "2) Display List Sorted by Student ID" << endl;
        cout << "3) Display List Sorted bt Name" << endl;
        cout << "4) Display List Sorted by Grade" << endl;
        cout << "5) Display List Sorted by Birthday" << endl;
        cout << "6) Display List Sorted by Hometown" << endl;
        cout << "7) Exit" << endl;
        cin >> choice;
        if(choice == 1){
            display(people, size);
            continue;
        }
        else if(choice == 2){
            display(sortI, size);
            continue;
        }
        else if(choice == 3){
            display(sortN, size);
            continue;
        }
        else if(choice == 4){
            display(sortG, size);
            continue;
        }
        else if(choice == 5){
            display(sortB, size);
            continue;
        }
        else if(choice == 6){
            display(sortH, size);
            continue;
        }
        else if(choice == 7){
            break;
        }
        
    }
}
