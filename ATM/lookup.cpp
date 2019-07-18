#include "lookup.h"
#include <fstream>
#pragma warning(disable:4996)

using namespace std;

Lookup::Lookup() {
	cout << "Enter your bank name : ";
	cin >> bank;
	cout << "Enter your account number : ";
	cin >> acntNum;
}

void Lookup::lookup() {
	ifstream infile("user/user.txt", ios::in);

	int nameSize;

	while (!infile.eof()) {
		char buffer[1024];
		bool check = false;

		infile.getline(buffer, 1024);
		nameSize = buffer[4] - '0';

		if (buffer[0] == '\0')
			break;

		initUserName(buffer);
		initUserBank(buffer, nameSize);
		initUserAcntNum(buffer, nameSize);
		initUserPwd(buffer, nameSize);
		initUserBalance(buffer, nameSize);

		int arrSize;
		switch (nameSize) {
		case 7:
		case 3:
			arrSize = 14;
			break;
		case 5:
		case 8:
			arrSize = 13;
			break;
		default:
			arrSize = 12;
			break;
		}

		char *checkAcnt = new char[arrSize];
		int* userAcnt = new int[arrSize];
		int userPwd = user.getPwd();
		userAcnt = user.getAcntNum();

		strcpy(checkAcnt, acntNum.c_str());

		string myBank = user.getBank();

		if (checkBank(myBank, bank) && checkAcntNum(checkAcnt, userAcnt, arrSize)) {
			cout << "Enter your pass word : ";
			cin >> pwd;
			if (checkPwd(userPwd, pwd)) {
				printInfo(nameSize);
				break;
			}
		}
		/*else {
			cout << "Not Correct Information" << endl;
		}*/
	}
}

void Lookup::printInfo(int size) {
	cout << "Name : \t\t\t" << user.getName() << endl;
	cout << "Bank : \t\t\t" << user.getBank() << endl;
	cout << "Account Number : \t";
	int* account = new int[16];
	account = user.getAcntNum();

	switch (size) {
	case 7:
	case 3:
		for (int i = 0; i < 14; i++) {
			cout << account[i];
		}
		break;
	case 5:
	case 8:
		for (int i = 0; i < 13; i++) {
			cout << account[i];
		}
		break;
	default:
		for (int i = 0; i < 12; i++) {
			cout << account[i];
		}
		break;
	}
	cout << endl;
	cout << "Balance : \t\t" << user.getBalance() << " WON" << endl;
}

/*void Lookup::initUserName(char* buf) {
	string userName;

	for (int i = 0; i < 3; i++) {
		userName += buf[i];
	}

	user.setName(userName);
}

void Lookup::initUserBank(char* buf, int size) {
	string bankName;
	for (int i = 0; i < size; i++) {
		bankName += buf[6 + i];
	}

	user.setBank(bankName);
}

void Lookup::initUserAcntNum(char *buf, int size) {
	int* num;
	int arrSize;
	switch (size) {
	case 7:
		arrSize = 14;
		num = new int[arrSize];
		for (int i = 0; i < arrSize; i++) {
			num[i] = buf[14 + i] - '0';
		}
		break;
	case 5:
		arrSize = 13;
		num = new int[arrSize];
		for (int i = 0; i < arrSize; i++) {
			num[i] = buf[12 + i] - '0';
		}
		break;
	case 6:
		arrSize = 12;
		num = new int[arrSize];
		for (int i = 0; i < arrSize; i++) {
			num[i] = buf[13 + i] - '0';
		}
		break;
	case 8:
		arrSize = 13;
		num = new int[arrSize];
		for (int i = 0; i < arrSize; i++) {
			num[i] = buf[15 + i] - '0';
		}
		break;
	default:
		arrSize = 14;
		num = new int[arrSize];
		for (int i = 0; i < arrSize; i++) {
			num[i] = buf[10 + i] - '0';
		}
		break;
	}
	user.setAcntNum(num, size);
}

void Lookup::initUserPwd(char* buf, int size) {
	char pwd[4] = { 0 };
	switch (size) {
	case 7:
	case 8:
		for (int i = 0; i < 4; i++) {
			pwd[i] = buf[29 + i];
		}
		break;
	case 5:
	case 6:
		for (int i = 0; i < 4; i++) {
			pwd[i] = buf[26 + i];
		}
		break;
	default:
		for (int i = 0; i < 4; i++) {
			pwd[i] = buf[25 + i];
		}
		break;
	}
	int mPwd = atoi(pwd);

	user.setPwd(mPwd);
}

void Lookup::initUserBalance(char* buf, int size) {
	char num[20] = { 0 };

	switch (size) {
	case 7:
	case 8:
		for (int i = 0;; i++) {
			num[i] = buf[34 + i];
			if (buf[34 + i] == '\\')
				break;
		}
		break;
	case 5:
	case 6:
	default:
		for (int i = 0;; i++) {
			num[i] = buf[31 + i];
			if (buf[31 + i] == '\\')
				break;
		}
		break;
	}

	int balance = atoi(num);

	user.setBalance(balance);
}

bool Lookup::checkBank(string a, string b) {
	if (a == b)
		return true;
	else
		return false;
}

bool Lookup::checkAcntNum(char* a, int* b, int size) {
	bool result = false;
	for (int i = 0; i < size; i++) {
		if (a[i] - '0' == b[i]) {
			result = true;
		}
		else {
			result = false;
			break;
		}
	}
	return result;
}

bool Lookup::checkPwd(int a, int b) {
	if (a == b)
		return true;
	else
		return false;
}*/

Lookup::~Lookup() {
	lookup();
}