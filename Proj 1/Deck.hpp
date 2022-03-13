//Audrey Brio
//CECS 282 - 05
//Project 1 - Solitaire Prime
//09/17/2019

#ifndef Deck_hpp
#define Deck_hpp
#include <iostream>
using namespace std;
#include "Card.hpp"
//Deck myDeck
//myDeck.refreshDeack();

class Deck
{
private:
    Card storage[52];
    int card;
    
public:
    Deck();
    void shuffle();
    void showDeck();
    int cardsLeft();
    void refreshDeck();
    void zero();
    Card deal();
    
};

#endif /* Deck_hpp */
