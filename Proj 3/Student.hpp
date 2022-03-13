//Audrey Brio
//CECS 282-05
//Project 3 -  Structs and Pointers
//10/15/2019

#ifndef Student_hpp
#define Student_hpp

#include <iostream>
#include "myDate.hpp"
#include<string>

struct student{
    
    char name[20]; 
    int ID;
    myDate bday;
    string hometown;
    char grade;
    
};

#endif /* Student_hpp */
