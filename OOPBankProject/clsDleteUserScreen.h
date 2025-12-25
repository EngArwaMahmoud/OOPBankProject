#include<iostream>
#include <iomanip>
#include "clsinputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"

#pragma once
class clsDleteUserScreen : protected clsScreen
{
private:
	static void _printUser(clsUser User)
	{
		cout << "\nClient Details:" << endl;
		cout << "----------------" << endl;
		cout << "Firstname: " << User.Firstname << endl;
		cout << "Lastname: " << User.Lastname << endl;
		cout << "Fullname: " << User.FullName() << endl;
		cout << "Email: " << User.Email << endl;
		cout << "Phone: " << User.Phone << endl;
		cout << "UserName: " << User.UserName << endl;
		cout << "Password: " << User.Password << endl;
		cout << "Permission: " << User.Permissions << endl;
		cout << "----------------" << endl;
	}
public:
	static void DeleteUser()
	{
		_DrawScreenHeader("\t Delete User Screen");
 
		string UserName = " ";
		cout << "\nplease enter User Name: ";
		UserName = clsinputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "User with this User Name not fount, please try again: ";
			UserName = clsinputValidate::ReadString();
		}

		clsUser DeleteUser = clsUser::Find(UserName);
		_printUser(DeleteUser);

		char answer = 'n';
		cout << "Are you sure you want to delete this User? y/n?";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			if (DeleteUser.Delete())
			{
				cout << "\nUser Deleted Successfully:)\n";
				_printUser(DeleteUser);
			}
			else {
				cout << "\nError wasn't deleted\n";
			}
		}

	}
};

