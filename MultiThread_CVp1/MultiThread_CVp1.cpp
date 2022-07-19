// MultiThread_CVp1.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

//CppNuts-Master_Utube/Threading/ProducerConsuer.cpp - with using Class Buffer

#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <condition_variable>
#include <chrono>
using namespace std;

class Buffer {

    std::mutex m;
    std::condition_variable cv;
    std::deque<int> queue;
    const unsigned long size = 100;

public:
    void addNum(int num) {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [this]() { return queue.size() <= size; });
        if (queue.size() <= size) {
            queue.push_back(num);
            cout << "Pushed " << num << endl;
        }
        lock.unlock();
        cv.notify_all();
    }
    int removeNum() {
        std::unique_lock<std::mutex> lock(m);
        int num{0};
        cv.wait(lock, [this]() { return queue.size()>0; });
       
        if (queue.size() > 0) {
            num = queue.back();
            queue.pop_back();
            cout << "Poped " << num << endl;
        }
        lock.unlock();
        cv.notify_all();
        return num;
    }

};

void producer(int val, Buffer& buf) {
    for (int i = 0; i < val; ++i) {
        buf.addNum(i);
    }
}

void consumer(int val, Buffer& buf) {
    for (int i = 0; i < val; ++i) {
        buf.removeNum();
    }
}

int main()
{
    cout << "Start of Program!\n";
    Buffer b;
    auto start = std::chrono::high_resolution_clock::now();
    std::thread t1(producer, 10000, std::ref(b));
    std::thread t2(consumer, 10000, std::ref(b));
    auto end = std::chrono::high_resolution_clock::now();
    t1.join();
    t2.join();
    std::chrono::duration<double> elapsed = end - start;
    cout << elapsed.count() << endl;

    cout << "The End\n";
    return 0;


}

