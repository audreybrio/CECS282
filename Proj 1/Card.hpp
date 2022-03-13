//Audrey Brio
//CECS 282 - 05
//Project 1 - Solitaire Prime
//09/17/2019

#ifndef Card_hpp
#define Card_hpp

#include <iostream>
using namespace std;

class Card
{

private:
    char rank;
    char suit;
    
public:
    Card();
    Card(char, char);
    int getValue();
    string getName();
    string getSuit();
    void setCard(char, char);
    void showCard();
    void display();
    //string toString();
    
};

#endif /* Card_hpp */
