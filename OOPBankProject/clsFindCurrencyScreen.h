#include "clsScreen.h"
#include "clsCurrancy.h"
#include "clsinputValidate.h"
#include <iomanip>
#include <vector>
#include <string>

#pragma once
class clsFindCurrencyScreen : protected clsScreen
{
private:

	enum enChooseFindMethod {eCurrencyCode = 1 , eCountryName = 2};

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card\n";
		cout << "\n----------------------------------" << endl;
		cout << "Country      : " << Currency.Country() << endl;
		cout << "Currency Code: " << Currency.CurrencyCode() << endl;
		cout << "Currency Name: " << Currency.CurrencyName() << endl;
		cout << "Rate         : " << Currency.Rate() << endl;
		cout << "----------------------------------" << endl;
	}

	static void _CountryCode()
	{
		string Currency;
		cout << "\nplease enter Currency Code: ";
		Currency = clsinputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(Currency))
		{
			cout << "Country with this Code does not exist, please try again: ";
			Currency = clsinputValidate::ReadString();
		}
		clsCurrency C1 = clsCurrency::FindByCode(Currency);
		if (!C1.IsEmpty())
		{
			cout << "\nCurrency found:)\n";
			_PrintCurrency(C1);
		}
		else
		{
			cout << "\nCurrency not found:(\n";
		}
	}
	
	static void _CountryName()
	{
		string Currency;
		cout << "\nplease enter Country Name: ";
		Currency = clsinputValidate::ReadString();

	
		clsCurrency C1 = clsCurrency::FindByCountry(Currency);
		if (!C1.IsEmpty())
		{
			cout << "\nCurrency found:)\n";
			_PrintCurrency(C1);
		}
		else
		{
			cout << "\nCurrency not found:(\n";
		}
	}

public:
	static void FindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen");

		short Choose;
		cout << "Find By: [1] Code or [2] Country ? ";
		cin >> Choose;

		switch (Choose)
		{
		case enChooseFindMethod::eCurrencyCode:
		{
			_CountryCode();
			break;
		}

		case enChooseFindMethod::eCountryName:
			_CountryName();
			break;
		}
	}
};

