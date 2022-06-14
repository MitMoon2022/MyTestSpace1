// uniquePtr1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

using namespace std;

struct Person
{
    Person(int age, const string& name) : age(age), name(name)
    {
        cout << "[CREATED]  Player name: " << name << ", age: " << age << endl;
    }
    ~Person()
    {
        cout << "[DELETED]  Player name: " << name << ", age: " << age << endl;
    }

    int age;
    string name;
};
void lesson1()
{
    unique_ptr<Person> player;
    //Person * p = nullptr;

    bool blive = (bool)player;

    if (blive)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    //cout<< (blive) ? "True!"<<endl) : ("False"<<endl;) 

    if (player)
        cout << "player exists" << endl;
    else
        cout << "no player" << endl;

    //pointing to Person
    player = make_unique<Person>(24, "John");

    if (player)
        cout << "Player name " << player->name << " joined" << endl;

    player.reset();     //null ptr

    //deletes old memory, assigns new memory
    player = make_unique<Person>(35, "Brian");

    if (player)
        cout << "Player name " << player->name << " joined" << endl;

    //Pass ownership of ptr to a raw pointer.
    Person* ownsPlayer = player.release();

    //Need to del because it is a raw ptr.

    //Player does not own the memory anymore
    if (!player)
        cout << "Brian not owned by unique_ptr player anymore.\n";

    if (ownsPlayer)
        cout << "ownsPlayer name: " << ownsPlayer->name << ", age: " << ownsPlayer->age << endl;

    //Need to del because it is a raw ptr.
    delete ownsPlayer;
    ownsPlayer = nullptr;

    Person* secPlayer = new Person(54, "Joe");
    player = make_unique<Person>(44, "Matt");
    player.reset(secPlayer);    //destroy secPlayer and take ownship of Joe.

    //delete secPlayer; //Wrong!
    //Another way:
    {
        Person* somePlayer = new Person(33, "jack");
        //taking ownership of the raw pointer
        unique_ptr<Person> thirdPlayer{ somePlayer };

        //delete somePlayer; //wrong! not neccessary
    }

}



int main()
{
    cout << "start program." << endl;

    //Person p1(45, "John");

    lesson1();

    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
