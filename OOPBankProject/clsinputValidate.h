#pragma once
#include <iostream>
#include "clsDate.h"
#include "ClsString.h"
using namespace std;

class clsinputValidate
{
public:

	static bool IsNumberBetween(int Num, int from, int to)
	{
		return (Num >= from && Num <= to);
	}

	static bool IsNumberBetween(double Num, double from, double to)
	{
		return (Num >= from && Num <= to);
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		if (clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)
			&& clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)
			)
		{
			return true;
		}

		if (clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)
			&& clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)
			)
		{
			return true;
		}
	}

	static int ReadIntNumber(string Message = "Invalid Number, Please try again\n")
	{
		int Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Message;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int from, int to , string Message = "Number not in the ring, Please try again\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number,from,to))
		{
			cout << Message;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static double ReadDblNumber(string Message = "Invalid Number, Please try agÔin\n")
	{
		double Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Message;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double from, double to, string Message = "Number not in the ring, Please try again\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, from, to))
		{
			cout << Message;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static bool IsValiDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}

};

