// multiple_thread_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;
using namespace std::literals;

void hello(int num) {
	this_thread::sleep_for(chrono::seconds(num));
	cout << "Hello from thread " << num << endl;
}

int main()
{
    std::cout << "Start of Learning Multi Threads creation tut1!\n";
	// Get starting timepoint
	auto start = high_resolution_clock::now();

	thread t1{ hello, 1 };
	thread t2{ hello, 2 };
	thread t3{ hello, 3 };

	t1.join();
	t2.join();
	t3.join();

	// After function call
	auto stop = high_resolution_clock::now();

	// Subtract stop and start timepoints and
	// cast it to required unit. Predefined units
	// are nanoseconds, microseconds, milliseconds,
	// seconds, minutes, hours. Use duration_cast()
	// function.
	auto duration = duration_cast<microseconds>(stop - start);
	auto duration_sec = duration_cast<seconds>(stop - start);

	// To get the value of duration use the count()
	// member function on the duration object
	cout << duration.count() <<" microsec" << endl;
	cout << duration_sec.count() << " sec" << endl;

	return 0;
}

