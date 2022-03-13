//Audrey Brio
//CECS 282 - 05
//Project 1 - Solitaire Prime
//09/17/2019

#include "Deck.hpp"
#include "Card.hpp"
#include <iostream>
using namespace std;

bool isPrime(int a){
    bool sum = true;
    if(a == 1){
        sum = false;
    }
    for(int i = 2; i < a; i++){
        if(a % i == 0){
            sum = false;
        }
    }
    return sum;
}

int main() {
    Deck d;
    int pile = 0;
    int sum = 0;
    while(true){
        int choice;
        cout << "Welcome to Solitaire Prime!" << endl;
        cout << "1) New Deck" << endl;
        cout << "2) Display Deck" << endl;
        cout << "3) Shuffle Deck" << endl;
        cout << "4) Play Solitaire Prime" << endl;
        cout << "5) Exit" << endl;
        cin >> choice;
        if(choice == 1){
            d.refreshDeck();
            cout << " " << endl;
            continue;
        }
        else if(choice == 2){
            d.showDeck();
            cout << " " << endl;
            continue;
        }
        else if(choice == 3){
             d.shuffle();
            cout << " " << endl;
            continue;
        }
        else if(choice == 4){
            //d.shuffle();
            for(int i = 0; i < 52; i++){
                Card cd = d.deal();
                int q = cd.getValue();
                sum = sum + q;
                bool prime = isPrime(sum);
                if(prime == true){
                    cout << "Prime: " << sum << endl;
                    pile = pile + 1;
                    sum = 0;
                    if(i == 51){
                        cout << " " << endl;
                        cout << "Winner in " << pile << " piles!" << endl;
                    }
                }
                else if(prime == false){
                    if(i == 51){
                        cout << "LOSER" << endl;
                    }
                    continue;
                }
            }
            pile = 0;
            sum = 0;
            d.zero();
            cout << " " << endl;
            continue;
        }
        else if(choice == 5){
            break;
        }
    }
}


