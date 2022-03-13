//Audrey Brio
//CECS 282-05
//Project 5 -  Standard Template Library
//11/21/2019

#include "BigInt.hpp"
#include<vector>
#include<map>
#include<iostream>
using namespace std;

BigInt goldRabbits(BigInt n){
    static map<BigInt,BigInt> rabbitMap;
    if(n == 0 || n == 1){
        rabbitMap[n] = BigInt(1);
        //return rabbitMap[n];
    }

   else{
        rabbitMap[n] = rabbitMap[n-1] + rabbitMap[n-2];

   }
//    else if (rabbitMap.find(n) == rabbitMap.end()){
//        rabbitMap[n] = rabbitMap[n-1] + rabbitMap[n-2];
//    }
    return rabbitMap[n];

}

BigInt goldRabbits(BigInt);
void pause() {cout << "Press Enter to continue..."; getchar();}

int main(){
    BigInt B1("123456789123456789123456789123456789");
    BigInt B2(B1);
    BigInt MAX(INT_MAX);
    cout << "B1:" << B1 << "\nB2:"<<B2 << "\nMAX:" << MAX << endl;
    pause();
    cout << "\nB1:";
    B1.print();
    cout << endl;
    pause();

    for(BigInt i = 0; i <= 3000; i++){
       cout << "\ngoldRabbits(" << i <<") = " << goldRabbits(i);
   }
    
    cout << endl;
    pause();
    
    cout << "\nThis is the value of goldRabbits(3000)\n\n";
    BigInt gR3000 = goldRabbits(BigInt(3000));
    gR3000.print();
    cout << endl;
    
    pause();
    
}

