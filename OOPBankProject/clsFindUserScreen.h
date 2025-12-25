#include<iostream>
#include <iomanip>
#include "clsinputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"

#pragma once
class clsFindUserScreen : protected clsScreen
{
private : 
	static void _printUser(clsUser User)
	{
		cout << "\nUser Details:" << endl;
		cout << "----------------" << endl;
		cout << "Firstname: " << User.Firstname << endl;
		cout << "Lastname: " << User.Lastname << endl;
		cout << "Fullname: " << User.FullName() << endl;
		cout << "Email: " << User.Email << endl;
		cout << "Phone: " << User.Phone << endl;
		cout << "User Name: " << User.UserName << endl;
		cout << "Password: " << User.Password << endl;
		cout << "Permission: " << User.Permissions << endl;
		cout << "----------------" << endl;
	}

public:
	static void FindUserScreen()
	{
		_DrawScreenHeader("\t Find User Screen");
 

		string UserName;
		cout << "\nplease enter User Name: ";
		UserName = clsinputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "User with this User Name does not exist, please try again: ";
			UserName = clsinputValidate::ReadString();
		}
		clsUser User1 = clsUser::Find(UserName);
		if (!User1.IsEmpty())
		{
			cout << "\nUser found:)\n";
		}
		else {
			cout << "\nUser not found:(\n";
		}
		_printUser(User1);
	}
};

