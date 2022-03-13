//Audrey Brio
//CECS 282 - 05
//Project 1 - Solitaire Prime
//09/17/2019

#include<stdlib.h>
#include<time.h>
#include "Deck.hpp"
#include <iostream>
using namespace std;

Deck::Deck()
{
    //top = 0;
    card = 0;
    storage[0].setCard('A','S');
    storage[1].setCard('2','S');
    storage[2].setCard('3','S');
    storage[3].setCard('4','S');
    storage[4].setCard('5','S');
    storage[5].setCard('6','S');
    storage[6].setCard('7','S');
    storage[7].setCard('8','S');
    storage[8].setCard('9','S');
    storage[9].setCard('T','S');
    storage[10].setCard('J','S');
    storage[11].setCard('Q','S');
    storage[12].setCard('K','S');
    storage[13].setCard('A','H');
    storage[14].setCard('2','H');
    storage[15].setCard('3','H');
    storage[16].setCard('4','H');
    storage[17].setCard('5','H');
    storage[18].setCard('6','H');
    storage[19].setCard('7','H');
    storage[20].setCard('8','H');
    storage[21].setCard('9','H');
    storage[22].setCard('T','H');
    storage[23].setCard('J','H');
    storage[24].setCard('Q','H');
    storage[25].setCard('K','H');
    storage[26].setCard('A','D');
    storage[27].setCard('2','D');
    storage[28].setCard('3','D');
    storage[29].setCard('4','D');
    storage[30].setCard('5','D');
    storage[31].setCard('6','D');
    storage[32].setCard('7','D');
    storage[33].setCard('8','D');
    storage[34].setCard('9','D');
    storage[35].setCard('T','D');
    storage[36].setCard('J','D');
    storage[37].setCard('Q','D');
    storage[38].setCard('K','D');
    storage[39].setCard('A','C');
    storage[40].setCard('2','C');
    storage[41].setCard('3','C');
    storage[42].setCard('4','C');
    storage[43].setCard('5','C');
    storage[44].setCard('6','C');
    storage[45].setCard('7','C');
    storage[46].setCard('8','C');
    storage[47].setCard('9','C');
    storage[48].setCard('T','C');
    storage[49].setCard('J','C');
    storage[50].setCard('Q','C');
    storage[51].setCard('K','C');
    
}

void Deck::shuffle(){
    //Card storage[52];
    Deck();
    srand(time(0));
    for(int i = 0; i < 900000; i++){
        int x = rand()%52;
        int y = rand()%52;
        Card C = storage[x];
        storage[x] = storage[y];
        storage[y] = C;
    }
    
    //showDeck();

}

void Deck::showDeck(){
    for(int i = 0; i <= 12; i++){
        storage[i].display();
        cout << ", ";
    }
    cout << endl;
    for(int j = 13; j <= 25; j++){
        storage[j].display();
        cout << ", ";
    }
    cout << endl;
    for(int k = 26; k <= 38; k++){
        storage[k].display();
        cout << ", ";
    }
    cout << endl;
    for(int l = 39; l <= 51; l++){
        storage[l].display();
        cout << ", ";
    }
    cout << endl;
}

int Deck::cardsLeft(){
    int cardsLeft = 0;
    cardsLeft = 52 - (card + 1);
    return cardsLeft;
}

void Deck::refreshDeck(){
    storage[0].setCard('A','S');
    storage[1].setCard('2','S');
    storage[2].setCard('3','S');
    storage[3].setCard('4','S');
    storage[4].setCard('5','S');
    storage[5].setCard('6','S');
    storage[6].setCard('7','S');
    storage[7].setCard('8','S');
    storage[8].setCard('9','S');
    storage[9].setCard('T','S');
    storage[10].setCard('J','S');
    storage[11].setCard('Q','S');
    storage[12].setCard('K','S');
    storage[13].setCard('A','H');
    storage[14].setCard('2','H');
    storage[15].setCard('3','H');
    storage[16].setCard('4','H');
    storage[17].setCard('5','H');
    storage[18].setCard('6','H');
    storage[19].setCard('7','H');
    storage[20].setCard('8','H');
    storage[21].setCard('9','H');
    storage[22].setCard('T','H');
    storage[23].setCard('J','H');
    storage[24].setCard('Q','H');
    storage[25].setCard('K','H');
    storage[26].setCard('A','D');
    storage[27].setCard('2','D');
    storage[28].setCard('3','D');
    storage[29].setCard('4','D');
    storage[30].setCard('5','D');
    storage[31].setCard('6','D');
    storage[32].setCard('7','D');
    storage[33].setCard('8','D');
    storage[34].setCard('9','D');
    storage[35].setCard('T','D');
    storage[36].setCard('J','D');
    storage[37].setCard('Q','D');
    storage[38].setCard('K','D');
    storage[39].setCard('A','C');
    storage[40].setCard('2','C');
    storage[41].setCard('3','C');
    storage[42].setCard('4','C');
    storage[43].setCard('5','C');
    storage[44].setCard('6','C');
    storage[45].setCard('7','C');
    storage[46].setCard('8','C');
    storage[47].setCard('9','C');
    storage[48].setCard('T','C');
    storage[49].setCard('J','C');
    storage[50].setCard('Q','C');
    storage[51].setCard('K','C');
}

void Deck::zero(){
    card = 0;
}

Card Deck::deal(){
    Card playing;
    playing = storage[card];
    card = card + 1;
    playing.display();
    cout << ", ";
    
    return playing;
}
