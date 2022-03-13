//Audrey Brio
//CECS 282 - 05
//Project 1 - Solitaire Prime
//09/17/2019

#include <iostream>
using namespace std;
#include "Card.hpp"

Card::Card(){
    
}

Card::Card(char r, char s){
    rank = r;
    suit = s;
    
}

int Card::getValue(){
    int a = 0;
    if(rank == 'A'){
        a = 1;
    }
    else if(rank == '2'){
        a = 2;
    }
    else if(rank == '3'){
        a = 3;
    }
    else if(rank == '4'){
        a = 4;
    }
    else if(rank == '5'){
        a = 5;
    }
    else if(rank == '6'){
        a = 6;
    }
    else if(rank == '7'){
        a = 7;
    }
    else if(rank == '8'){
        a = 8;
    }
    else if(rank == '9'){
        a = 9;
    }
    else if(rank == 'T'){
        a = 10;
    }
    else if(rank == 'J'){
        a = 10;
    }
    else if(rank == 'Q'){
        a = 10;
    }
    else if(rank == 'K'){
        a = 10;
    }
    return a;
}


string Card::getName(){
    string b = "";
    if(rank == 'A'){
        b = "Ace";
    }
    else if(rank == '2'){
        b = "Two";
    }
    else if(rank == '3'){
        b = "Three";
    }
    else if(rank == '4'){
        b = "Four";
    }
    else if(rank == '5'){
        b = "Five";
    }
    else if(rank == '6'){
        b = "Six";
    }
    else if(rank == '7'){
        b = "Seven";
    }
    else if(rank == '8'){
        b = "Eight";
    }
    else if(rank == '9'){
        b = "Nine";
    }
    else if(rank == 'T'){
        b = "Ten";
    }
    else if(rank == 'J'){
        b = "Jack";
    }
    else if(rank == 'Q'){
        b = "Queen";
    }
    else if(rank == 'K'){
        b = "King";
    }
    return b;
    }

string Card::getSuit(){
    string c = "";
    if(suit == 'S'){
        c = "Spades";
    }
    else if(suit == 'H'){
        c = "Hearts";
    }
    else if(suit == 'D'){
        c = "Diamonds";
    }
    else if(suit == 'C'){
        c = "Clubs";
    }
    return c;
}

void Card::setCard(char r, char s)
{
    rank = r;
    suit = s;
}

void Card::showCard(){
    cout << getName() << " of " << getSuit() << ":" << rank << suit;
}

void Card::display(){
    if(rank == 'T'){
        cout << "10" << suit;
    }
    else{
    cout << rank << suit;
    }
}


