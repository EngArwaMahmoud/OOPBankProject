#include <iostream>
#include <iomanip>
#include "clsinputValidate.h"
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "Global.h"

#pragma once
class clsLoginScreen : clsScreen
{
private:
	static bool _Login()
	{
		string Username, Password;
		bool LoginFailed = false;
		short NumberOfTriel = 3;
		do {

			if (LoginFailed)
			{
				NumberOfTriel-= 1;

				cout << "\nInvalid Username or Password, Try again\n";
				cout << "You have " << (NumberOfTriel) << " Trials to login!\n\n";
			}
			if (NumberOfTriel == 0)
			{
				cout << "You are locked after " << NumberOfTriel << "failed trails\n\n";
				return false;
			}

			cout << "Enter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);
			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
	}
public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t    Login Screen");
 
		return _Login();
	}
};

