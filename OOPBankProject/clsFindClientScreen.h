#include<iostream>
#include <iomanip>
#include "clsinputValidate.h"
#include "clsScreen.h"
#include"clsBankClient.h"
#pragma once

class clsFindClientScreen:protected clsScreen
{
private:
	static void _printClient(clsBankClient Client)
	{
		cout << "\nClient Details:" << endl;
		cout << "----------------" << endl;
		cout << "Firstname: " << Client.Firstname << endl;
		cout << "Lastname: " << Client.Lastname << endl;
		cout << "Fullname: " << Client.FullName() << endl;
		cout << "Email: " << Client.Email << endl;
		cout << "Phone: " << Client.Phone << endl;
		cout << "Account Number: " << Client.getAccountNumber() << endl;
		cout << "Pin Code: " << Client.PinCode << endl;
		cout << "Account Balance: $" << Client.AccountBalance << endl;
		cout << "----------------" << endl;
	}
public:
	static void FindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindUser))
		{
			return;
		}
		_DrawScreenHeader("\t Find Client Screen");

		string AccountNumber;
		cout << "\nplease enter client Account Number: ";
		AccountNumber = clsinputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client with this Account Number does not exist, please try again: ";
			AccountNumber = clsinputValidate::ReadString();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		if (!Client1.IsEmpty())
		{
			cout << "\nClient found:)\n";
		}
		else {
			cout << "\nClient not found:(\n";
		}
		_printClient(Client1);
	}
};

