//Audrey Brio
//CECS 282-05
//Project 5 -  Standard Template Library
//11/21/2019

#ifndef BigInt_hpp
#define BigInt_hpp

#include<vector>
#include<map>
#include<iostream>
using namespace std;

class BigInt{
    
private:
    vector<char> rabbits;
    //vector<char> reverse;
    //static map<BigInt, BigInt> FibMap;
    
public:
    BigInt();
    BigInt(int);
    BigInt(string);
    
    
    BigInt operator+(BigInt);
    BigInt operator-(BigInt);
    
    BigInt operator++(int);
    bool operator==(int);
    BigInt operator=(int);
    
    BigInt operator+(int);
    BigInt operator-(int);
    
    friend bool operator<(const BigInt & left, const BigInt & right);
    friend bool operator<=(const BigInt & left, const BigInt & right);
    
    friend ostream& operator<<(ostream&, const BigInt&);
    
    void print();
    
};

#endif /* BigInt_hpp */
