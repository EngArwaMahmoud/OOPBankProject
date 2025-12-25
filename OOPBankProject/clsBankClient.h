#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:
	enum enMode {emptyMode = 0, updateMode = 1, AddNewMode = 2};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector <string> vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(
			enMode::updateMode,
			vClientData[0], //AccountNumber
			vClientData[1], 
			vClientData[2],
			vClientData[3],
			vClientData[4],
			vClientData[5],
			stod(vClientData[6])
		);
	}

	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.Firstname + Seperator;
		stClientRecord += Client.Lastname + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.getAccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;
	}

	static  vector <clsBankClient> _LoadClientsDataFromFile()
	{

		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConvertLineToClientObject(Line);

				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return vClients;
	}

	static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient C : vClients)
			{
				DataLine = _ConverClientObjectToLine(C);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}

	static void _SaveClientDataToFileDelete(vector <clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient C : vClients)
			{
				if (C._MarkForDelete == false)
				{
				DataLine = _ConverClientObjectToLine(C);
				MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.getAccountNumber() == getAccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveCleintsDataToFile(_vClients);
	}

	void _AddNew()
	{

		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,
		string UserName, string Seperator = "#//#")
	{
		string TransferLogRecord = "";
		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += getAccountNumber() + Seperator;
		TransferLogRecord += DestinationClient.getAccountNumber() + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogRecord += UserName;
		return TransferLogRecord;
	}

	struct stTransferLogRecord;
	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTransferLogRecord TransferLog;

		vector <string> TransferLogDataLine = clsString::Split(Line, Seperator);
		TransferLog.DateTime = TransferLogDataLine[0];
		TransferLog.FromAccount = TransferLogDataLine[1];
		TransferLog.ToAccount = TransferLogDataLine[2];
		TransferLog.Amount = stoi(TransferLogDataLine[3]);
		TransferLog.FromAccountBalance = stoi(TransferLogDataLine[4]);
		TransferLog.ToAccountBalance = stoi(TransferLogDataLine[5]);
		TransferLog.UserName = (TransferLogDataLine[6]);

		return TransferLog;

	}

	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{

		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0);
	}

public:

	struct stTransferLogRecord
	{
		string DateTime;
		string FromAccount;
		string ToAccount;
		float Amount;
		float FromAccountBalance;
		float ToAccountBalance;
		string UserName;
	};

	clsBankClient(enMode Mode, string Firstname, string Lastname, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
		: clsPerson(Firstname, Lastname, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}
	string getAccountNumber() {
		return _AccountNumber;
	}

	void setPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string getPinCode() {
		return _PinCode;
	}
	__declspec(property(get = getPinCode, put = setPinCode)) string PinCode;

	void setAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}
	float getAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = getAccountBalance, put = setAccountBalance)) float AccountBalance;

	string FullName() {
		return Firstname + " " + Lastname;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::emptyMode);
	}


	static clsBankClient Find(string AcountNumber)
	{
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); //read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.getAccountNumber() == AcountNumber)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AcountNumber , string PinCode)
	{
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); //read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.getAccountNumber() == AcountNumber && Client.getPinCode() == PinCode)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	enum enSaveResult {svFailedEmptyMode = 0, svSucceeded = 1,svFaildAccountNumberExists = 2};

	enSaveResult Save()
	{
		switch (_Mode)
		{

		case enMode::emptyMode:
		{
			return enSaveResult::svFailedEmptyMode;
			break;
		}
			

		case enMode::updateMode:
		{
			_Update();
			return enSaveResult::svSucceeded;
			break;
		}
		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
			return enSaveResult::svFaildAccountNumberExists;
			}
			else {
				_AddNew();
				_Mode = enMode::updateMode;
				return enSaveResult::svSucceeded;
			}
		}
		}
	}


	static bool IsClientExist(string AcountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AcountNumber);
		return (!Client1.IsEmpty());
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector <clsBankClient> _Vclients;
		_Vclients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _Vclients)
		{
			if (C.getAccountNumber() == _AccountNumber)
			{
				C._MarkForDelete = true;
				break;
			}
		}
		_SaveClientDataToFileDelete(_Vclients);
		*this = _GetEmptyClientObject();
		return true;
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalance()
	{
		double TotalBalance = 0;
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		for (clsBankClient C : vClients)
		{
			TotalBalance += C.AccountBalance;
		}
		return TotalBalance;
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool WithDraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}

		_AccountBalance -= Amount;
		Save();
	}

	bool Transfer(float Amount, clsBankClient& ToClient, string UserName)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}

		WithDraw(Amount);
		ToClient.Deposit(Amount);
		_RegisterTransferLog(Amount, ToClient, UserName);
		return true;
	}

	static  vector <stTransferLogRecord> GetTransferLogList()
	{
		vector <stTransferLogRecord> vTransferLogRecord;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			stTransferLogRecord TransferLogRecord;

			while (getline(MyFile, Line))
			{

				TransferLogRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferLogRecord);

			}
			MyFile.close();

		}
		return vTransferLogRecord;
	}

};

