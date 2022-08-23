// StaticClassMemeber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Static Function Members
//By declaring a function member as static, you make it independent of any particular object of the class.
//A static member function can be called even if no objects of the class existand the static functions are accessed using only the class nameand the scope resolution operator ::.
//A static member function can only access static data member, other static member functions and any other functions from outside the class.

//Static member functions have a class scope and they do not have access to the this pointer of the class.You could use a static member function 
//to determine whether some objects of the class have been created or not.

//*This also means that static member functions cannot access data members 
//and methods that are not static themselves.

#include <iostream>
#include "Player.h"

using namespace std;


void display_active_players() {
    cout << "Active players: " << Player::get_num_players() << endl;
}

int main()
{
    std::cout << "Start of Program!\n";

    //---------------------------------------
    display_active_players();
    Player hero{ "Hero" };
    display_active_players();

    {
        Player frank{ "Frank" };
        display_active_players();
    }
    display_active_players();

    Player* enemy = new Player("Enemy", 100, 100);
    display_active_players();
    delete enemy;
    display_active_players();




}

