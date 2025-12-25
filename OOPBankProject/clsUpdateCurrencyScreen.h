#include "clsScreen.h"
#include "clsCurrancy.h"
#include "clsinputValidate.h"
#include <iomanip>
#include <vector>
#include <string>

#pragma once
class clsUpdateCurrencyScreen : protected clsScreen
{
private:
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

	static float _UpdateRate()
	{
		float NewRate = 0;
		cout << "Enter New Rate: ";
		NewRate = clsinputValidate::ReadDblNumber();
		return NewRate;
	}

public:

	static void ShowUpdateRateScreen()
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
		_PrintCurrency(C1);

		cout << "Are you sure you want to update the rate of this currency? y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			cout << "\n\nUpdate Currency Rate:\n";
			cout << "------------------------\n";
			
			C1.UpdateRate(_UpdateRate());
			cout << "\nCurrency Rate Updatted Successfully:)\n";
			_PrintCurrency(C1);
		}
	}

};

