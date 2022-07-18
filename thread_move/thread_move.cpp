// thread_move.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <string>

class Grabber {
public:
	void operator () (std::string s) {
		std::cout << "Class Ownership of \"" << s << "\" transferred to thread" << std::endl;
	}
};

void func(std::string s) {
	std::cout << "Func Ownership of \"" << s << "\" transferred to thread" << std::endl;
}

int main()
{
    std::cout << "Start of Program!\n";

	std::string s{ "moveable" };
	

	std::cout << "Starting thread" << std::endl;
	//auto t = std::thread(func, std::move(s));


	Grabber grab;
	//auto t = std::thread(grab, std::move(s1));
	auto t = std::thread([s = std::move(s)]{
		std::cout << "Lamdba Ownership of \"" << s << "\" transferred to thread" << std::endl;
		});
	t.join();
	std::cout << "Do I still have any data?" << std::endl;
	std::cout << s << std::endl;
	



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
