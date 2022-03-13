//Audrey Brio
//CECS 282-05
//Project 5 -  Standard Template Library
//11/21/2019
//

#include "BigInt.hpp"
#include<vector>
#include<map>
#include<iostream>
using namespace std;



BigInt::BigInt(){
    rabbits.push_back('1');
}

BigInt::BigInt(int n){
    string a = to_string(n);
    for(int i = 0; i < a.length(); i++){
        rabbits.push_back(a[i]);
    }
}

BigInt::BigInt(string s){
    for(int i = 0; i < s.length(); i++){
        rabbits.push_back(s[i]);
    }
    
}

void BigInt::print(){
    for(int i = 0; i < this -> rabbits.size(); i++){
        cout << rabbits[i];
    }
    //cout << endl;
}

BigInt BigInt::operator+(BigInt B){
    string replace = "";
    for(int i = 0; i < this -> rabbits.size(); i++){
        string str = to_string((this -> rabbits[i])- 48);
        replace = replace + str;
    }
    BigInt edit(replace); //this copy
    BigInt copy(B);
    
    int size_this = edit.rabbits.size();
    int size_B = copy.rabbits.size();
    if(size_this > size_B){
        for(int i = 0; i < (size_this - size_B); i++){
            copy.rabbits.insert(copy.rabbits.begin(), '0');
        }
    }
    if(size_this < size_B){
        for(int i = 0; i < (size_B - size_this); i++){
            edit.rabbits.insert(edit.rabbits.begin(), '0');
        }
    }

    string p = "";
    int carry = 0;
    BigInt temp(edit);
    for(int i = copy.rabbits.size() - 1; i > -1; i--){
        int a = (edit.rabbits[i]) - 48;
        int b = (copy.rabbits[i]) - 48;
        int sum = a + b;
        carry =  sum / 10;
        int lay = sum % 10;
        if(lay == 0){
            temp.rabbits[i] = '0';
        }
        else if(lay == 1){
            temp.rabbits[i] = '1';
        }
        else if(lay == 2){
            temp.rabbits[i] = '2';
        }
        else if(lay == 3){
            temp.rabbits[i] = '3';
        }
        else if(lay == 4){
            temp.rabbits[i] = '4';
        }
        else if(lay == 5){
            temp.rabbits[i] = '5';
        }
        else if(lay == 6){
            temp.rabbits[i] = '6';
        }
        else if(lay == 7){
            temp.rabbits[i] = '7';
        }
        else if(lay == 8){
            temp.rabbits[i] = '8';
        }
        else if(lay == 9){
            temp.rabbits[i] = '9';
        }
        //temp.rabbits[i] = lay;
        if(i==0 && carry == 1){
            carry = 1;
        }
        else{
            if(carry == 1){
                copy.rabbits[i-1] = (copy.rabbits[i-1]) + 1;
            }
        }
    
    }
    
    if(carry == 1){
        temp.rabbits.insert(temp.rabbits.begin(), '1');
    }
    return temp;
}



BigInt BigInt::operator-(BigInt B){
    string replace2 = "";
    for(int i = 0; i < this -> rabbits.size(); i++){
        string str = to_string((this -> rabbits[i])- 48);
        replace2 = replace2 + str;
    }
    BigInt edit2(replace2); //this copy
    BigInt copy2(B);
    
    
    int size_this = edit2.rabbits.size();
    int size_B = copy2.rabbits.size();
    if(size_this > size_B){
        for(int i = 0; i < (size_this - size_B); i++){
            copy2.rabbits.insert(copy2.rabbits.begin(), '0');
        }
    }
    if(size_this < size_B){
        for(int i = 0; i < (size_B - size_this); i++){
            edit2.rabbits.insert(edit2.rabbits.begin(), '0');
        }
    }
    
    
    string p2 = "";
    int sub = 0;
    for(int i = copy2.rabbits.size() - 1; i > -1; i--){
        int a2 = (edit2.rabbits[i]) - 48;
        int b2 =  (int(copy2.rabbits[i])) - 48;
        if(a2 >= b2){
            if(a2==0 && b2 == 0 && i == 0){
                BigInt D(p2);
                return D;
            }
            else{
                 sub = a2 - b2;
            }
        }
        else if(a2 < b2){
            if(edit2.rabbits[i-1] == 0){
                edit2.rabbits[i-2] = (edit2.rabbits[i-2]) - 1;
                edit2.rabbits[i-1] = (edit2.rabbits[i]-1) + 9;
                edit2.rabbits[i] = (edit2.rabbits[i]) + 10;
                sub = (edit2.rabbits[i]) - 48 - b2;

            }
            else{
                edit2.rabbits[i-1] = (edit2.rabbits[i-1]) - 1;
                edit2.rabbits[i] = (edit2.rabbits[i]) + 10;
                sub = (edit2.rabbits[i]) - 48 - b2;
            }
        }
            p2 = to_string(sub) + p2;
        }
    
    BigInt diff(p2);
    
    return diff;
}

BigInt BigInt::operator+(int q){
    return *this + BigInt(q);
}


BigInt BigInt::operator-(int w){
    return *this - BigInt(w);
}

BigInt BigInt::operator++(int k){
    *this = *this + BigInt(1);
    return *this;
}


ostream& operator<<(ostream& os, const BigInt& B){
    if(B.rabbits.size() > 12){
        os << (B.rabbits[0]) - 48 << "." << B.rabbits[1] << B.rabbits[2] << B.rabbits[3] << B.rabbits[4] << B.rabbits[5] << B.rabbits[6] << B.rabbits[7] << B.rabbits[8] << B.rabbits[9] << B.rabbits[10] <<  "e" << B.rabbits.size();
    }
    else{
        for(int i = 0; i < B.rabbits.size(); i++){
            os << B.rabbits[i];
        }
    //cout << endl;
    }
    return os;
}

bool operator<(const BigInt & left, const BigInt & right){
    
    BigInt L(left); //this copy
    BigInt R(right);
    
    int size_L = L.rabbits.size();
    int size_R = R.rabbits.size();
    
    if(size_L > size_R){
        for(int i = 0; i < (size_L - size_R); i++){
            R.rabbits.insert(R.rabbits.begin(), '0');
        }
    }
    if(size_L < size_R){
        for(int i = 0; i < (size_R - size_L); i++){
            L.rabbits.insert(L.rabbits.begin(), '0');
        }
    }
    int i = 0;
    while(L.rabbits[i] == R.rabbits[i]){
        if(i == L.rabbits.size()-1){
            return false;
        }
        i++;
    }
    if((L.rabbits[i])<R.rabbits[i]){
        return true;
    }
    else{
        return false;
    }
}

bool BigInt::operator==(int b){
    bool a = false;
    int size =  this -> rabbits.size();
    if(size == 1){
        int compare = (this -> rabbits[0] - 48);
        if(compare == b){
            a = true;
        }
        else{
            a = false;
        }
    }
    else{
        a = false;
    }
    return a;
}

BigInt BigInt::operator=(int c){
    BigInt B(c);
    return c;
}

bool operator<=(const BigInt & left, const BigInt & right){
        
        BigInt L(left); //this copy
        BigInt R(right);
        
        int size_L = L.rabbits.size();
        int size_R = R.rabbits.size();
        
        if(size_L > size_R){
            for(int i = 0; i < (size_L - size_R); i++){
                R.rabbits.insert(R.rabbits.begin(), '0');
            }
        }
        if(size_L < size_R){
            for(int i = 0; i < (size_R - size_L); i++){
                L.rabbits.insert(L.rabbits.begin(), '0');
            }
        }
        int i = 0;
        while(L.rabbits[i] == R.rabbits[i]){
            if(i == L.rabbits.size()-1){
                return true;
            }
            i++;
        }
        if((L.rabbits[i])<R.rabbits[i]){
            return true;
        }
        else{
            return false;
        }
    
}

