// uniquePtr2.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void print(const Person* person)
{
    if (person)
        cout << "Print>> Player name: " << person->name << ", age: " << person->age << endl;
}
unique_ptr<Person> createPerson(const int age, const string& name)
{
    return make_unique<Person>(age, name);

}


int main()
{
    cout << "start program." << endl;

    //unique_ptr<Person> player = make_unique<Person>(23, "John");

    //print(player.get());

    //unique_ptr<Person> person2 = createPerson(35, "Brian");

    //print(person2.get());

    //person2 = move(player);     //using move function. player will be destroy.

    //print(person2.get());
    //=========================================================================================
    //-----------------------------------------------
    struct Ball
    {
        int size{ 10 };
    };

    //only one ball, 2 persons can pass the ball by move();
    struct footballPlayer
    {
        unique_ptr<Ball> ball;
    };


    footballPlayer player1, player2;

    if (player1.ball)
        cout << "player1 has the ball" << endl;
    if (player2.ball)
        cout << "player2 has the ball" << endl;
    if (!player1.ball && !player2.ball)
        cout << "Nobody has the ball" << endl;

    player1.ball = make_unique<Ball>(); //like holding the ball to player1 (own it).

    if (player1.ball)
        cout << "player1 has the ball" << endl;
    if (player2.ball)
        cout << "player2 has the ball" << endl;
    if (!player1.ball && !player2.ball)
        cout << "Nobody has the ball" << endl;


    player2.ball = move(player1.ball);  //player1 passes the ball to player2.

    if (player1.ball)
        cout << "player1 has the ball" << endl;
    if (player2.ball)
        cout << "player2 has the ball" << endl;
    if (!player1.ball && !player2.ball)
        cout << "Nobody has the ball" << endl;


    return 0;

}

