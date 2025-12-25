#include<iostream>
#include <iomanip>
#include "clsinputValidate.h"
#include "clsScreen.h"
#include"clsBankClient.h"
#pragma once
class clsAddNewClientScreen:protected clsScreen
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
	static void AddNewClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewUser))
		{
			return;
		}
		_DrawScreenHeader("\t Add New Client Screen");
 

		string AccountNumber = " ";
		cout << "\nplease enter client Account Number: ";
		AccountNumber = clsinputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client with this Account Number is already exist, please try again: ";
			AccountNumber = clsinputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResult Result = NewClient.Save();

		switch (Result)
		{
		case clsBankClient::enSaveResult::svFailedEmptyMode:
			cout << "Failed to update client info, client is in empty mode." << endl;
			break;
		case clsBankClient::enSaveResult::svSucceeded:
			cout << "\nAccount added successfully.:-)" << endl;
			_printClient(NewClient);
			break;
		case clsBankClient::enSaveResult::svFaildAccountNumberExists:
			cout << "Account already is used." << endl;
			break;
		}
	}

};

