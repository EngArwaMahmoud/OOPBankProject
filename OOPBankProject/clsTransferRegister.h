#include<iostream>
#include <iomanip>
#include "clsinputValidate.h"
#include "clsScreen.h"
#include"clsBankClient.h"

using namespace std;
#pragma once
class clsTransferRegister : protected clsScreen
{
private:

    static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLog)
    {

        cout << setw(8) << left << "" << "| " << setw(25) << left << TransferLog.DateTime;
        cout << "| " << setw(10) << left << TransferLog.FromAccount;
        cout << "| " << setw(10) << left << TransferLog.ToAccount;
        cout << "| " << setw(10) << left << TransferLog.Amount;
        cout << "| " << setw(10) << left << TransferLog.FromAccountBalance;
        cout << "| " << setw(10) << left << TransferLog.ToAccountBalance;
        cout << "| " << setw(10) << left << TransferLog.UserName;
    }

public:

    static void ShowTransferLogScreen()
    {

        vector <clsBankClient::stTransferLogRecord> vTransferLog = clsBankClient::GetTransferLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vTransferLog.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "s.Account";
        cout << "| " << left << setw(10) << "d.Account";
        cout << "| " << left << setw(10) << "Ammount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(10) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLog.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vTransferLog)
            {

                _PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

