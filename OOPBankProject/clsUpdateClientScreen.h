#include<iostream>
#include <iomanip>
#include "clsinputValidate.h"
#include "clsScreen.h"
#include"clsBankClient.h"
#pragma once
class clsUpdateClientScreen:clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nplease enter First Name: ";
		Client.Firstname = clsinputValidate::ReadString();

		cout << "please enter Last Name: ";
		Client.Lastname = clsinputValidate::ReadString();

		cout << "please enter Email: ";
		Client.Email = clsinputValidate::ReadString();

		cout << "please enter Phone: ";
		Client.Phone = clsinputValidate::ReadString();

		cout << "please enter Pin Code: ";
		Client.PinCode = clsinputValidate::ReadString();

		cout << "please enter Account Balance: ";
		Client.AccountBalance = clsinputValidate::ReadDblNumber();

	}

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
	static void UpdateClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateUsers))
		{
			return;
		}
		_DrawScreenHeader("\t Update Client Screen");
 
		string AccountNumber = " ";
		cout << "\nplease enter client Account Number: ";
		AccountNumber = clsinputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client with this Account Number does not exist, please try again: ";
			AccountNumber = clsinputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_printClient(Client1);
		
		char Answer = 'n';
		cout << "Are you sure you want to Update this client? y/n?";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\nUpdate Client Info";
			cout << "\n-------------------\n";
			_ReadClientInfo(Client1);
			//Client1.Firstname = "Arwa";
			clsBankClient::enSaveResult Result = Client1.Save();

			switch (Result)
			{
			case clsBankClient::enSaveResult::svFailedEmptyMode:
				cout << "Failed to update client info, client is in empty mode." << endl;
				break;
			case clsBankClient::enSaveResult::svSucceeded:
				cout << "\nClient info updated successfully.:-)" << endl;
				_printClient(Client1);
				break;
			}
		}
		else {
			cout << "Client Did not updated.";
		}
	}
};

