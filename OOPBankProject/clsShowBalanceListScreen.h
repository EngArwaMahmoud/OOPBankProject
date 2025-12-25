#include<iostream>
#include <iomanip>
#include "clsinputValidate.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include"clsBankClient.h"

#pragma once
class clsShowBalanceListScreen:protected clsScreen
{
private:
	static void _PrintClientRecordLineBalance(clsBankClient Client)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.getAccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}
public:

	static void ShowBalanceList()
	{

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t Total Balance Screen";
		string SubTitle = "\t (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);
 

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		double TotalBalance = clsBankClient::GetTotalBalance();

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordLineBalance(Client);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t\t\t\t\t   Total Balance = " << TotalBalance << endl;
		cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalance) << ")";

	}
};

