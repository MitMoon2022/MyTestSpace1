// MultiThread_CVp0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// TOPIC: Condition Variable In C++ Threading

// NOTES:
// 1. Condition variables allow us to synchronize threads via notifications.
//    a. notify_one();
//    b. notify_all();
// 2. You need mutex to use condition variable
// 3. Condition variable is used to synchronize two or more threads.
// 4. Best use case of condition variable is Producer/Consumer problem.
// 5. Condition variables can be used for two purposes:
//     a. Notify other threads
//     b. Wait for some condition
// 
// 
// https://thispointer.com//c11-multithreading-part-7-condition-variables-explained/
//Condition Variable is a kind of Event used for signaling between two or more threads.
//One or more thread can wait on it to get signaled, while an another thread can signal.

//CppNuts-Master_Utube/Threading/ProducerConsumer_final.cpp - Simple

#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <condition_variable>
using namespace std;

std::mutex mu;
std::condition_variable cond;
deque<int> buffer;
const unsigned int maxBufferSize = 50;

void producer(int val) {
    while (val) {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, []() {return buffer.size() < maxBufferSize; }); //void wait( std::unique_lock<std::mutex>& lock, Predicate stop_waiting );
        buffer.push_back(val);
        cout << "Produced: " << val << endl;
        val--;
        locker.unlock();
        cond.notify_one();
    }
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, []() {return buffer.size() > 0; });   ////void wait( std::unique_lock<std::mutex>& lock, Predicate stop_waiting );
        int val = buffer.back();
        buffer.pop_back();
        cout << "Consumed: " << val << endl;
        //Modify
        if (buffer.size() == 0)
            break;
        locker.unlock();
        cond.notify_one();
    }
}


int main()
{
    cout << "A Simple Producer & Comsumer Problem!\n";
    std::thread t1(producer, 100);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    cout << "The End\n";
    return 0;


}


