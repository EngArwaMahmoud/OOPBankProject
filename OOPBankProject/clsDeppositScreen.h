#include<iostream>
#include <iomanip>
#include "clsinputValidate.h"
#include "clsScreen.h"
#include"clsBankClient.h"

#pragma once
class clsDeppositScreen : protected clsScreen
{
private: 

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
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

    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t   Deposit Screen");
          
        string AccountNumber = _ReadAccountNumber();


        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _printClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter deposit amount? ";
        Amount = clsinputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.Deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.AccountBalance;

        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }
};

