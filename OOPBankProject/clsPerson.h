#pragma once
#include<iostream>
#include <string>
using namespace std;

class clsPerson
{
private:
	string _Firstname;
	string _Lastname;
	string _Email;
	string _Phone;

public:
	clsPerson(string Firstname, string Lastname, string Email, string Phone) {
		_Firstname = Firstname;
		_Lastname = Lastname;
		_Email = Email;
		_Phone = Phone;
	}

	void setFirstname(string Firstname) {
		_Firstname = Firstname;
	}
	string getFirstname() {
		return _Firstname;
	}
	__declspec(property(get = getFirstname, put = setFirstname)) string Firstname;

	void setLastname(string Lastname) {
		_Lastname = Lastname;
	}

	string getLastname() {
		return _Lastname;
	}
	__declspec(property(get = getLastname, put = setLastname)) string Lastname;

	void setEmail(string Email) {
		_Email = Email;
	}
	string getEmail() {
		return _Email;
	}
	__declspec(property(get = getEmail, put = setEmail)) string Email;

	void setPhone(string Phone) {
		_Phone = Phone;
	}
	string getPhone() {
		return _Phone;
	}
	__declspec(property(get = getPhone, put = setPhone)) string Phone;
};

