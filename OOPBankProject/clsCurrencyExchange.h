#include <iostream>
#include <string>
#include "clsString.h"
#include "clsinputValidate.h"
#include <iomanip>
#include "clsCurrancy.h"
#include "clsScreen.h"
#include "clsShowListCurrencyScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalcScreen.h"

#pragma once
class clsCurrencyExchange : protected clsScreen
{
private:
	enum enCurrencyExchangeOptions {
		eShowAllCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
		eCurrencyCalculator = 4, eBackToMainMenue = 5
	};

	static short _ReadCurrencyExchangeMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsinputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}

	static void _GoBackToCurrencyExchangeMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Exchange Menue...\n";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}
	
	static void _ShowAllCurrenciesScreen()
	{
		//cout << "\nClient List Screen Will be here...\n";
		clsShowListCurrencyScreen::ShowCurrancyListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Screen Will be here...\n";
		clsFindCurrencyScreen::FindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		//cout << "\nUpdate Currency Rate Screen Will be here...\n";
		clsUpdateCurrencyScreen::ShowUpdateRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nCurrency Calculator Screen Will be here...\n";
		clsCurrencyCalcScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrencyExchange(enCurrencyExchangeOptions CurrencyExchange)
	{
		switch (CurrencyExchange)
		{
		case clsCurrencyExchange::eShowAllCurrencies:
			system("cls");
			_ShowAllCurrenciesScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		case clsCurrencyExchange::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		case clsCurrencyExchange::eUpdateCurrencyRate:
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		case clsCurrencyExchange::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		case clsCurrencyExchange::eBackToMainMenue:
		{

		}

		}
	}

public:
	
	static void ShowCurrencyExchangeScreen()
	{
		system("cls");
		_DrawScreenHeader("\tCurrency Exchange Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show All Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Currency Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Back To Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyExchange((enCurrencyExchangeOptions)_ReadCurrencyExchangeMenueOption());
	}
};

