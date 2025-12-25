#include<iostream>
#include <iomanip>
#include "clsinputValidate.h"
#include "clsScreen.h"
#include"clsBankClient.h"
#pragma once

class clsDeleteClientScreen:protected clsScreen
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
	static void DeleteClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteUser))
		{
			return;
		}
		_DrawScreenHeader("\t Delete Client Screen");
 

		string AccountNumber = " ";
		cout << "\nplease enter client Account Number: ";
		AccountNumber = clsinputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client with this Account Number not fount, please try again: ";
			AccountNumber = clsinputValidate::ReadString();
		}

		clsBankClient DeleteClient = clsBankClient::Find(AccountNumber);
		_printClient(DeleteClient);

		char answer = 'n';
		cout << "Are you sure you want to delete this client? y/n?";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			if (DeleteClient.Delete())
			{
				cout << "\nClient Deleted Successfully:)\n";
				_printClient(DeleteClient);
			}
			else {
				cout << "\nError wasn't deleted\n";
			}
		}

	}

};

