//Audrey Brio
//CECS 282-05
//Project 6 -  Inheritance/Virtual Functions
//12/5/2019



#include "Luggage.cpp"

int Luggage::count = 0;

int main(){
    //Luggage * cargo[100];
    vector<Luggage*> cargo;
    double volume = 0;
    
    while(true){
        int choice;
        cout << "1) Add luggage to storage container" << endl;
        cout << "2) Remove luggage from storage container" << endl;
        cout << "3) Show all luggage" << endl;
        cout << "4) Quit" << endl;
        cin >> choice;
        
        if(choice == 1){
            int pick;
            cout << "Here is a list of the available luggage types. Please choose a number" << endl;
            cout << "1) Box" << endl;
            cout << "2) Sphere" << endl;
            cout << "3) Cube" << endl;
            cout << "4) Pyramid" << endl;
            cout << "5) Cylinder" << endl;
            cout << "6) Ellipsoid" << endl;
            cout << "7) Hemisphere" << endl;
            cout << "8) Prisim" << endl;
            cin >> pick;
            
            if(pick == 1){
                double length, height, width;
                cout << "You've picked a box as your luggage type!" << endl;
                cout << "Please enter the length of the box: " << endl;
                cin >> length;
                cout << "Please enter the height of the box: " << endl;
                cin >> height;
                cout << "Please enter the width of the box: " << endl;
                cin >> width;
                
                box b(width, length, height);
                //volume = volume + b.volume();
                cargo.push_back(new box(width,length,height));
                
                //cout << "Volume: " << b.volume()  << endl;
                
            }
            
            else if(pick == 2){
                double radius;
                cout << "You've picked a sphere as your luggage type!" << endl;
                cout << "Please enter the radius of the sphere: " << endl;
                cin >> radius;
                
                sphere s(radius);
                //volume = volume + s.volume();
                cargo.push_back(new sphere(radius));
                
                //cout << "Volume: " << s.volume() << endl;
            }
            
            else if(pick == 3){
                double width;
                cout << "You've picked a cube as your luggage type!" << endl;
                cout << "Please enter the width of the cube: " << endl;
                cin >> width;
                
                cube c(width);
                //volume = volume + c.volume();
                cargo.push_back(new cube(width));
                
                //cout << "Volume: " << c.volume()  << endl;
                
            }
            
            else if(pick == 4){
                double base, height;
                cout << "You've picked a pyramid as your luggage type!" << endl;
                cout << "Please enter the base of the pyramid: " << endl;
                cin >> base;
                cout << "Please enter the height of the pyramid: " << endl;
                cin >> height;
                
                pyramid py(base, height);
                //volume = volume + py.volume();
                cargo.push_back(new pyramid(base,height));
                
                //cout << "Volume: " << py.volume()  << endl;
                
            }
            
            else if(pick == 5){
                double radius, length;
                cout << "You've picked a cylinder as your luggage type!" << endl;
                cout << "Please enter the radius of the cylinder: " << endl;
                cin >> radius;
                cout << "Please enter the length of the cylinder: " << endl;
                cin >> length;
                
                cylinder cy(radius, length);
                //volume = volume + cy.volume();
                cargo.push_back(new cylinder(radius, length));
                
                //cout << "Volume: " << cy.volume()  << endl;
            }
            
            
            else if(pick == 6){
                double radius_one, radius_two, radius_three;
                cout << "You've picked an ellipsoid as your luggage type!" << endl;
                cout << "Please enter the 1st radius of the ellipsoid: " << endl;
                cin >> radius_one;
                cout << "Please enter the 2nd radius of the ellipsoid: " << endl;
                cin >> radius_two;
                cout << "Please enter the 3rd radius of the ellipsoid: " << endl;
                cin >> radius_three;
                
                ellipsoid e(radius_one, radius_two, radius_three);
                //volume = volume + e.volume();
                cargo.push_back(new ellipsoid(radius_one,radius_two,radius_three));
                
                //cout << "Volume: " << e.volume()  << endl;
                
            }
            
            else if(pick == 7){
                double radius;
                cout << "You've picked a hemisphere as your luggage type!" << endl;
                cout << "Please enter the radius of the hemisphere: " << endl;
                cin >> radius;
                
                hemisphere h(radius);
                //volume = volume + h.volume();
                cargo.push_back(new hemisphere(radius));
                
                //cout << "Volume: " << h.volume()  << endl;
            }
            
            else if(pick == 8){
                double base, height;
                cout << "You've picked a prisim as your luggage type!" << endl;
                cout << "Please enter the base of the prisim: " << endl;
                cin >> base;
                cout << "Please enter the height of the prisim: " << endl;
                cin >> height;
                
                prisim pr(base, height);
                //volume = volume + pr.volume();
                cargo.push_back(new prisim(base,height));
                
                //cout << "Volume: " << pr.volume()  << endl;
            }
            
        }
        
        else if(choice == 2){
            int del;
            int size = Luggage::getCount();
            //size = size - 2;
            //int range = 1;
            cout << "Here are the items in the storage container:" << endl;
            for(int i = 0; i < size / 2; i++){
                cout << (i+1) << ". " << cargo[i] -> getType() << ": " << cargo[i] -> volume() << endl;
                //range = range + 1;
                //cout << cargo[i] -> volume() << endl;
            }
            cout << "Please pick an item to remove:" << endl;
            cin >> del;
            cargo.erase(cargo.begin() + del - 1);
            
           // delete cargo[del - 1];
            
            volume = volume - cargo[del - 1] -> volume();
            cargo[del - 1] -> minus();
            
            
        }
        
        else if(choice == 3){
            int size = Luggage::getCount();
            volume = 0;
            for(int i = 0; i < size / 2; i++){
                cout << (i+1) << ". " << cargo[i] -> getType() << ": " << cargo[i] -> volume() << endl;
                volume = volume + cargo[i] -> volume();
            }
            cout << "Total Luggage: " << Luggage::getCount() / 2 << endl;
            cout << "Total Volume: " << volume << endl;
            
        }
        
        else if(choice == 4){
            break;
        }
        cout << endl;
    }
    
    
}
