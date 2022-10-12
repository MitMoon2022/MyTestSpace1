// UniquePtrL1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// TOPIC: Unique Pointer In C++

// NOTES:
// 0. unique_ptr is a class template.
// 1. unique_ptr is one of the smart pointer provided by c++11 to prevent memory leaks.
// 2. unique_ptr wraps a raw pointer in it, and de-allocates the raw pointer,
//    when unique_ptr object goes out of scope.
// 3. similar to actual pointers we can use -> and * on the object of unique_ptr, 
//    because it is overloaded in unique_ptr class.
// 4. When exception comes then also it will de-allocate the memory hence no memory leak.
// 5. Not only object we can create array of objects of unique_ptr.

// OPERATIONS:
// release, reset, swap, get, get_deleter.


// PROGRAM: 

#include<iostream>
#include<memory>
using namespace std;

class Foo {
    int x;
public:
    explicit Foo(int x) : x{ x } {}
    int getX() { return x; }
    ~Foo() { cout << "Foo Dest" << endl; }
};




int main()
{
    cout << "Start learn unique ptr from NutCpp!\n";

    // Foo *f = new Foo(10);
   // cout << f->getX() << endl;

  /* std::unique_ptr<Foo> p(new Foo(10));
   cout << p->getX() << endl;*/

   //==============================================================================================
    std::unique_ptr<Foo> p1(new Foo(10));
    //Another way of calling a unique ptr.
    std::unique_ptr<Foo> p2 = make_unique<Foo>(20); //should use make_unique (there are reasons).

    cout << p1->getX() <<"Next " << (*p2).getX() << endl;

    // p1 = p2; //Fail:This will fail because you can not copy ownership
    std::unique_ptr<Foo> p3 = std::move(p1);    //PASS: coz' moving ownership is allowed.

    Foo* p = p3.get();  //Returns the stored pointer.
                        //https://cplusplus.com/reference/memory/unique_ptr/get/
                        // does not make unique_ptr release ownership of the pointer

    cout << "pointer p shows "<< p->getX() << endl;
    cout << "p3 shows " << p3->getX() << endl;

    Foo* p4 = p3.release();

    p2.reset(p4);

    cout << p2->getX() << endl;

    return 0;
}

