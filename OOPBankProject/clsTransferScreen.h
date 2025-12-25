#include<iostream>
#include <iomanip>
#include "clsinputValidate.h"
#include "clsScreen.h"
#include"clsBankClient.h"
#include "Global.h"

#pragma once
class clsTransferScreen : protected clsScreen
{
private :

	static void _printClient(clsBankClient Client)
	{
		cout << "\nClient card:" << endl;
		cout << "----------------" << endl;
		cout << "Fullname: " << Client.FullName() << endl;
		cout << "Account Number: " << Client.getAccountNumber() << endl;
		cout << "Balance: $" << Client.AccountBalance << endl;
		cout << "----------------" << endl;
	}

	static float ReadAmount(clsBankClient FromClient)
	{
		double Amount = 0;
		cout << "\nPlease enter Transfer amount? ";
		Amount = clsinputValidate::ReadDblNumber();
		while (Amount > FromClient.AccountBalance)
		{
			cout << "\nYou can't transfer more than " << FromClient.AccountBalance << " $ !\n";
			cout << "\nPlease enter Transfer amount? ";
			Amount = clsinputValidate::ReadDblNumber();
		}
		return Amount;
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t   Transfer Screen");

		string FromAccountNumber = "";
		cout << "\nPlease enter Account Number to Transfer From? ";
		cin >> FromAccountNumber;

		while (!clsBankClient::IsClientExist(FromAccountNumber))
		{
			cout << "\nClient with [" << FromAccountNumber << "] does not exist! Try again.\n";
			cout << "\nPlease enter Account Number to Transfer From? ";
			cin >> FromAccountNumber;
		}

		clsBankClient FromClient = clsBankClient::Find(FromAccountNumber);
		_printClient(FromClient);

		string ToAccountNumber = "";
		cout << "\nPlease enter Account Number to Transfer To? ";
		cin >> ToAccountNumber;
		while (!clsBankClient::IsClientExist(ToAccountNumber) || ToAccountNumber == FromAccountNumber)
		{
			if (ToAccountNumber == FromAccountNumber)
			{
				cout << "\nYou can't transfer to the same account!\n";
			}
			else {
				cout << "\nClient with [" << ToAccountNumber << "] does not exist! Try again.\n";
			}
			cout << "\nPlease enter Account Number to Transfer To? ";
			cin >> ToAccountNumber;
		}

		clsBankClient ToClient = clsBankClient::Find(ToAccountNumber);
		_printClient(ToClient);

		float Amount = ReadAmount(FromClient);

		cout << "Are you sure you want to perform this transaction? (y/n) ";
		char Answer = 'n';
		cin >> Answer;
		if(Answer == 'Y' || Answer == 'y')
		{
			FromClient.Transfer(Amount, ToClient, CurrentUser.GetUserName());
			cout << "\nTransaction completed successfully!\n";
		}
		else
		{
			cout << "\nTransaction cancelled!\n";
		}
			_printClient(FromClient);
			_printClient(ToClient);
	}
};

