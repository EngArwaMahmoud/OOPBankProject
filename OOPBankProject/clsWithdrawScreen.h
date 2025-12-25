#include<iostream>
#include <iomanip>
#include "clsinputValidate.h"
#include "clsScreen.h"
#include"clsBankClient.h"

#pragma once
class clsWithdrawScreen : protected clsScreen
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

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t   Withdraw Screen");
          
        string AccountNumber = _ReadAccountNumber();


        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _printClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter Withdraw amount? ";
        Amount = clsinputValidate::ReadDblNumber();

            cout << "\nAre you sure you want to perform this transaction? ";
            char Answer = 'n';
            cin >> Answer;

            if (Answer == 'Y' || Answer == 'y')
            {
                if (Client1.WithDraw(Amount))
                {
                    cout << "\nAmount Withdraw Successfully.\n";
                    cout << "\nNew Balance Is: " << Client1.AccountBalance;
                }
                else {
                    cout << "\nCannot withdraw, Insuffecient Balance.";
                    cout << "\nAmount to withdraw is " << Amount;
                    cout << "\nYour Balance is: "<< Client1.AccountBalance;
                }
            }
            else
            {
                cout << "\nOperation was cancelled.\n";
            }
    }
};

