#include<iostream>
#include <iomanip>
#include "clsinputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"

#pragma once
class clsAddNewUser : protected clsScreen
{
private:
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nplease enter First Name: ";
		User.Firstname = clsinputValidate::ReadString();

		cout << "\nplease enter Last Name: ";
		User.Lastname = clsinputValidate::ReadString();

		cout << "\nplease enter Email: ";
		User.Email = clsinputValidate::ReadString();

		cout << "\nplease enter Phone: ";
		User.Phone = clsinputValidate::ReadString();

		cout << "\nplease enter Password: ";
		User.Password = clsinputValidate::ReadString();

		cout << "\nplease enter Permission: ";
		User.Permissions = _ReadUserPermissionToSet();

	}

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
		cout << "Password: " <<clsUtil::EncryptText (User.Password) << endl;
		cout << "Permission: " << User.Permissions << endl;
		cout << "----------------" << endl;
	}

	static int _ReadUserPermissionToSet()
	{
		int Permissions = 0;
		char Answer = 'n';


		cout << "\nDo you want to give full access? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow Client List? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{


			Permissions += clsUser::enPermissions::pListUser;
		}

		cout << "\nAdd New Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewUser;
		}

		cout << "\nDelete Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteUser;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateUsers;
		}

		cout << "\nFind Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindUser;
		}

		cout << "\nTransactions? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTranactions;
		}

		cout << "\nManage Users? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nLogin Register? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pLoginRegister;
		}
		return Permissions;
	}

public:
	static void AddNewUser()
	{

		_DrawScreenHeader("\t Add New User Screen");
 
		string UserName = " ";
		cout << "\nplease enter User Name: ";
		UserName = clsinputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "User with this User Name is already exist, please try again: ";
			UserName = clsinputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
		_ReadUserInfo(NewUser);

		clsUser::enSaveResults Result = NewUser.Save();

		switch (Result)
		{
		case clsUser::enSaveResults::svFaildUserExists:
			cout << "Failed to update User info, User is in empty mode." << endl;
			break;
		case clsUser::enSaveResults::svSucceeded:
			cout << "\nUser added successfully :-)" << endl;
			_printUser(NewUser);
			break;
		case clsUser::enSaveResults::svFaildEmptyObject:
			cout << "User already is exist." << endl;
			break;
		}
	}
};

