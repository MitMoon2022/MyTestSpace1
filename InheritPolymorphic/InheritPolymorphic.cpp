// InheritPolymorphic.cpp : This file contains the 'main' function. Program execution begins and ends there.
// A complete Guide to Proj in C++
// Chap 23 Inheritance and Chap 25 Polymorphism
// 
//The classes Car and PassCar are to modify to allow objects to be createdand
//destroyed.In addition, the class Truck is to be added to the class hierarchy.
//■ Change the classes Carand PassCar to make the constructor issue the
//following message :
//"Creating an object of type ... ."
// 
//■ Define a destructor for the Carand PassCar classes.The destructor
//should issue the following message :
//"Destroying an object of type ...."
// 
//■ Then define the class Truck, which is derived from Car, using the data
//members shown opposite, a constructor, a destructor, and the additional
//methods shown opposite.
// 
//■ Implement the constructor for the Truck class—the constructor should
//again issue a suitable message.Use the base initializer to initialize the data
//members of Car.
// 
//■ Define a destructor for Truck—the destructor should again issue a suitable
//message for trucks.
// 
//■ To test your class, createand display a Truck type object in your main
//function.If required by the user, enable your program to createand display
//objects of the types PassCarand Car.
//Observe how the various objectsand member objects are created and
//destroyed.




#include <iostream>
#include "Car.h"        //base class
#include "PassCar.h"    //Derived class
#include "Truck.h"      //Derived class

using namespace std;



int main()
{
    cout << "Start Learning Inheritance and Polymorphic!\n";

    //================= Lesson from inheritance chap 23 ===============================
    //const PassCar beetle("Beetle", false, 3421, "VW");
    //beetle.display();
    //cout << "\nAnd the passenger car number again: "
    //    << beetle.getNr() << endl;

    //PassCar cabrio("Carrera", true);
    //cabrio.setNr(1000);                 //using its parent's class method
    //cabrio.setProd("Porsche");          //using its parent's class method
    //cabrio.display();

    //cout << "\nOnly data of the base class: ";
    //cabrio.Car::display();
    //==============================================================================
    // Continue on Pg 522:
    /*cout << "====================== Truck Testing!============================" << endl;
    Truck toy(5, 7.5, 1111, "Volvo");
    toy.display();

    char c;
    cout << "\nDo you want to create an object of type "
        << " PassCar? (y/n) "; cin >> c;
    if (c == 'y' || c == 'Y')
    {
        const PassCar beetle("Beetle", false, 3421, "VW");
        beetle.display();
    }
    cout << "\nDo you want to create an object "
        << " of type car? (y/n) "; cin >> c;
    if (c == 'y' || c == 'Y')
    {
        const Car oldy(3421, "Rolls Royce");
        oldy.display();
    }*/
    //==============================================================================
    // Demostrate of Polymorphism - base class "Car.h", virtual keyword insert on method display().
    // Object-Oriented Approach
    /*The approach adopted by object - oriented languages is polymorphism(Greek for multiform).
    In C++, virtual methods are used to implement polymorphic classes.Calling a virtual
    method makes the compiler execute a version of the method suitable for the object
    in question, when the object is accessed by a pointer or a reference to the base class!*/
    // virtual.cpp : Tests the virtual method display()
    // of the classes Car and PassCar.
    // ----------------------------------------------------
    Car* pCar[3]; // Three pointers to the base class.
    int i = 0; // Index
    pCar[0] = new Car(5634L, "Mercedes");
    pCar[1] = new PassCar("Miata", true, 3421, "Mazda");
    pCar[2] = new Truck(5, 7.5, 1234, "Ford");
    while (true)
    {
        cout << "\nTo output an object of type "
            "Car, PassCar or Truck!"
            "\n 1 = Car, 2 = PassCar, 3 = Truck"
            "\nYour input (break with 0): ";
        cin >> i;
        --i;
        if (i < 0 || i > 2)
            break;
        pCar[i]->display();
    }

    //==============================================================================
    return 0;
}

