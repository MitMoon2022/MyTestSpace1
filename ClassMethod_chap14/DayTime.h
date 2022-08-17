#pragma once
// DayTime.h
// The class DayTime represents the time in
// hours, minutes and seconds.
// ---------------------------------------------------
#ifndef _DAYTIME_
#define _DAYTIME_
class DayTime
{
private:
	short hour, minute, second;
	bool overflow;
public:
	DayTime(int h = 0, int m = 0, int s = 0)
	{
		overflow = false;
		if (!setTime(h, m, s))			// this->setTime(...)
			hour = minute = second = 0; // hour is equivalent
	}									// to this->hour etc.

	bool setTime(int hour, int minute, int second = 0)
	{
		if (hour >= 0 && hour < 24
			&& minute >= 0 && minute < 60
			&& second >= 0 && second < 60)
		{
			this->hour = (short)hour;
			this->minute = (short)minute;
			this->second = (short)second;
			return true;
		}
		else
			return false;
	}
	//= Implementation ========================================================================
	int getHour() const { return hour; }
	int getMinute() const { return minute; }
	int getSecond() const { return second; }
	int asSeconds() const						// daytime in seconds
	{
		return (60 * 60 * hour + 60 * minute + second);
	}

	//it is also meaning Passing by Value! simplifying explain to myself.
	//When the method isLess() is called, the copy constructor executesand initializes the
	//created object, t, with the argument.
	//depart1.isLess(depart2) // Copy constructor
	//The function uses a copy of the object depart2.The copy is cleaned up when leaving
	//the function, that is, the destructor is called.

	bool isLess(DayTime t) const				// compare *this and t
	{
		return asSeconds() < t.asSeconds();
	}	
	// this->asSeconds() < t.asSeconds();

	void print() const
	{
		cout << this->hour <<"hour:" <<this->minute<<" mins.\n";
	}


};
#endif // _DAYTIME_