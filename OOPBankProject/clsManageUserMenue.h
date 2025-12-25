#include <iostream>
#include <iomanip>
#include "clsinputValidate.h"
#include "clsScreen.h"
#include "clsListUserScreen.h"
#include "clsAddNewUser.h"
#include "clsDleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

#pragma once
class clsManageUserMenue : protected clsScreen
{
private:
    enum enManageUserMenueOptions {
        eListUser = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue};

    static short _ReadManageUserMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsinputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 4? ");
        return Choice;
    }

    static  void _GoBackToManageUserMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage User Menue...\n";

        system("pause>0");
        ShowManageUserMenue();
    }

    static void _ShowListUserScreen()
    {
        //cout << "\nList User Screen Will be here...\n";
        clsListUserScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        //cout << "\Add New User Screen Will be here...\n";//
        clsAddNewUser::AddNewUser();
    }

    static void _ShowDeleteScreen()
    {
        //cout << "\nDelete User Screen Will be here...\n";
        clsDleteUserScreen::DeleteUser();
    }

    static void _ShowUpdateUserScreen()
    {
        //cout << "\nUpdate User Screen Will be here...\n";
        clsUpdateUserScreen::UpdateUser();
    }

    static void _ShowFindUserScreen()
    {
        //cout << "\nFind User Screen Will be here...\n";
        clsFindUserScreen::FindUserScreen();
    }

    static void _PerfromManageUserMenueOption(enManageUserMenueOptions ManageUserOption)
    {
        switch (ManageUserOption)
        {
        case enManageUserMenueOptions::eListUser:
        {
            system("cls");
            _ShowListUserScreen();
            _GoBackToManageUserMenue();
            break;
        }
        case enManageUserMenueOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUserMenue();
            break;
        }
        case enManageUserMenueOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteScreen();
            _GoBackToManageUserMenue();
            break;
        }
        case enManageUserMenueOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUserMenue();
        }
        case enManageUserMenueOptions::eFindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUserMenue();
        }
        case enManageUserMenueOptions::eMainMenue:
        {

        }

        }
    }
public:

	static void ShowManageUserMenue()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");
          

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tManage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromManageUserMenueOption((enManageUserMenueOptions)_ReadManageUserMenueOption());
	}

};

