#include "account.h"

// account.h
// Account class with read-only methods.
// ----------------------------------------------------


//Account::Account(const string& a_name, unsigned long a_nr, double a_state)
//	{
//		nr = a_nr;
//		name = a_name;
//		state = a_state;
//	};

Account::Account(const string& a_name)
	{
		name = a_name;
		nr = 1111111; state = 0.0;
	}

Account::Account(const string& a_name, unsigned long a_nr, double a_state)
	{
		name = a_name; nr = a_nr; state = a_state;
	}


<<<<<<< HEAD
	void Account::display() const
=======
	void Account::display() //const
>>>>>>> 3e536b5d1883dcab580934e570cb0e91ebef07f4
	{
		cout << fixed << setprecision(2)
			<< "--------------------------------------\n"
			<< "Account holder: " << name << '\n'
			<< "Account number: " << nr << '\n'
			<< "Account state: " << state << '\n'
			<< "--------------------------------------\n"
			<< endl;
	}
