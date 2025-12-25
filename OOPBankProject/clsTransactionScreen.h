#include <iostream>
#include <iomanip>
#include "clsinputValidate.h"
#include "clsScreen.h"
#include "clsShowBalanceListScreen.h"
#include "clsDeppositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferRegister.h"
#pragma once

class clsTransactionScreen :protected clsScreen
{
private:
    enum enTransactionMenueOptions {
        eWithDraw = 1, eDeposit = 2, eTotalBalance = 3,
        eTransfer = 4,eTransferLog = 5,eGoMainMenue = 6};

    static short _ReadTransactionMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsinputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static  void _GoBackToTransactionMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menue...\n";

        system("pause>0");
        showTransactionMenue();
    }

    static void _ShowWithDrawScreen()
    {
        //cout << "\nWithDraw Screen Will be here...\n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowDepositScreen()
    {
        //cout << "\nDeposit Client Screen Will be here...\n";//
        clsDeppositScreen::ShowDepositScreen();
    }

    static void _ShowTotalBalanceScreen()
    {
        //cout << "\nTotal Balance Screen Will be here...\n";
        clsShowBalanceListScreen::ShowBalanceList();
    }

	static void _ShowTransferScreen()
	{
		//cout << "\nTransfer Screen Will be here...\n";
		clsTransferScreen::ShowTransferScreen();
	}

    static void _ShowTransferLogScreen()
    {
		//cout << "\nTransfer Log Screen Will be here...\n";
		clsTransferRegister::ShowTransferLogScreen();
    }

    static void _PerfromTransactionMenueOption(enTransactionMenueOptions TransactionOption)
    {
        switch (TransactionOption)
        {
        case clsTransactionScreen::eWithDraw:
        {
            system("cls");
            _ShowWithDrawScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case clsTransactionScreen::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case clsTransactionScreen::eTotalBalance:
        {
            system("cls");
            _ShowTotalBalanceScreen();
            _GoBackToTransactionMenue();
            break;
        }

		case clsTransactionScreen::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionMenue();
			break;
		}

		case clsTransactionScreen::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionMenue();
			break;
		}

        case clsTransactionScreen::eGoMainMenue:
        {

        }
           
        }
    }

public:
    static void showTransactionMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\tTransaction Screen");
          

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransaction Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[2] Deposit.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromTransactionMenueOption((enTransactionMenueOptions)_ReadTransactionMenueOption());
    }

};

