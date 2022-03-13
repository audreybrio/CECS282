//Audrey Brio
//CECS 282-05
//Project 6 -  Inheritance/Virtual Functions
//12/5/2019
//

#include<vector>
#include<iostream>
#include<cmath>
using namespace std;


class Luggage{
    
protected:
    string type;
    static int count; //how many pieces of luggage i have
    
    
public:
    Luggage(){
        count++;
    }
    static int getCount(){
        return count;
    }
    virtual string getType(){
        return type;
    }
    virtual double volume() = 0;
    
    void minus(){
        count--;
        count--;
    }
};

class box:public Luggage {
private:
    double length, width, height;
public:
    box(double w, double l, double h){
        width = w;
        length = l;
        height = h;
        type = "box";
    }
    double volume(){
        return length*width*height;
    }
    string getType(){
        type = "box";
        return type;
    }
    void minus(){
        count--;
        count--;
    }
    
};

class sphere:public Luggage {
private:
    double radius;
public:
    sphere(double r){
        radius = r;
        type = "sphere";
    }
    double volume(){
        return (4/3) * radius * radius * radius * M_PI;
    }
    string getType(){
        type = "sphere";
        return type;
    }
    void minus(){
        count--;
        count--;
    }
    
};

class cube:public Luggage {
private:
    double width;
public:
    cube(double w){
        width = w;
        type = "cube";
    }
    double volume(){
        return width * width * width;
    }
    string getType(){
        type = "cube";
        return type;
    }
    void minus(){
        count--;
        count--;
    }
    
};

class pyramid:public Luggage {
private:
    double base, height;
public:
    pyramid(double b, double h){
        base = b;
        height = h;
        type = "pyramid";
    }
    double volume(){
        return base * height * 0.3333333333333;
    }
    string getType(){
        type = "pyramid";
        return type;
    }
    void minus(){
        count--;
        count--;
    }
    
};

class cylinder:public Luggage {
private:
    double radius, length;
public:
    cylinder(double r, double l){
        radius = r;
        length = l;
        type = "cylinder";
    }
    double volume(){
        return M_PI * radius * radius * length;
    }
    string getType(){
        type = "cylinder";
        return type;
    }
    void minus(){
        count--;
        count--;
    }
    
};


class ellipsoid:public Luggage {
private:
    double radius_one, radius_two, radius_three;
public:
    ellipsoid(double r1, double r2, double r3){
        radius_one = r1;
        radius_two = r2;
        radius_three = r3;
        type = "ellipsoid";
    }
    double volume(){
        return (4/3) * M_PI * radius_one * radius_two * radius_three;
    }
    string getType(){
        type = "ellipsoid";
        return type;
    }
    void minus(){
        count--;
        count--;
    }
};

class hemisphere:public Luggage {
private:
    double radius;
public:
    hemisphere(double r){
        radius = r;
        type = "hemisphere";
    }
    double volume(){
        return 0.6666666667 * radius * radius * radius * M_PI;
    }
    string getType(){
        type = "hemisphere";
        return type;
    }
    void minus(){
        count--;
        count--;
    }
    
};

class prisim:public Luggage {
private:
    double base, height;
public:
    prisim(double b, double h){
        base = b;
        height = h;
        type = "prisim";
    }
    double volume(){
        return base * height;
    }
    string getType(){
        type = "prisim";
        return type;
    }
    void minus(){
        count--;
        count--;
    }
    
};
