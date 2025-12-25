#include "clsScreen.h"
#include "clsCurrancy.h"
#include <iomanip>
#include <vector>
#include <string>

#pragma once
class clsShowListCurrencyScreen : protected clsScreen
{
private:
	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(35) << left << Currency.CurrencyName();
		cout << "| " << setw(20) << left << Currency.Rate();
	}

public:

	static void ShowCurrancyListScreen()
	{
		vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();
		string Title = "\t Currencies List Screen";
		string SubTitle = "\t (" + to_string(vCurrency.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(35) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(35) << "Name";
		cout << "| " << left << setw(20) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vCurrency.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsCurrency Currency : vCurrency)
			{

				_PrintCurrencyRecordLine(Currency);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
};

