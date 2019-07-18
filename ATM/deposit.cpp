#include <iostream>
#include <fstream>
#include "deposit.h"
#pragma warning(disable:4996)

using namespace std;

Deposit::Deposit() {
	cout << "Enter your bank Name : ";
	cin >> bank;

	cout << "Enter your Account Number : ";
	cin >> acntNum;
}

Deposit::Deposit(string uBank,string uAcntNum,string sMoney) {
	bank = uBank;
	acntNum = uAcntNum;
	money = sMoney;
}

void Deposit::deposit() {
	ifstream infile;
	ofstream outfile;
	infile.open("user/user.txt", ios::in);
	outfile.open("user/temp.txt", ios::out);

	int nameSize;

	while (!infile.eof()) {
		char buffer[1024];
		bool check = false;

		infile.getline(buffer, 1024);
		nameSize = buffer[4] - '0';

		if (buffer[0] == '\0')	// 모든 정보 탐색이 끝나면 탐색 종료
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

		char* checkAcnt = new char[arrSize];
		int* userAcnt = new int[arrSize];
		userAcnt = user.getAcntNum();
		
		strcpy(checkAcnt, acntNum.c_str());

		string myBank = user.getBank();

		if (checkBank(myBank,bank)&&checkAcntNum(checkAcnt,userAcnt,arrSize)) {
			cout << "Enter your deposit money : ";
			cin >> money;

			int oMoney = atoi(money.c_str()) + user.getBalance();

			user.setBalance(oMoney);
		}

		outfile << user.getName() << " ";
		outfile << nameSize << " ";
		outfile << user.getBank() << " ";

		int* account = new int[16];
		account = user.getAcntNum();

		switch (nameSize) {
		case 7:
		case 3:
			for (int i = 0; i < 14; i++) {
				outfile << account[i];
			}
			break;
		case 5:
		case 8:
			for (int i = 0; i < 13; i++) {
				outfile << account[i];
			}
			break;
		default:
			for (int i = 0; i < 12; i++) {
				outfile << account[i];
			}
			break;
		}
		outfile << " ";

		outfile << user.getPwd() << " ";
		outfile << user.getBalance() << '\\' << '\n';
	}

	infile.close();
	outfile.close();
}

void Deposit::recieve() {
	ifstream infile;
	ofstream outfile;
	infile.open("user/user.txt", ios::in);
	outfile.open("user/temp.txt", ios::out);

	int nameSize;

	while (!infile.eof()) {
		char buffer[1024];
		bool check = false;

		infile.getline(buffer, 1024);
		nameSize = buffer[4] - '0';

		if (buffer[0] == '\0')	// 모든 정보 탐색이 끝나면 탐색 종료
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

		char* checkAcnt = new char[arrSize];
		int* userAcnt = new int[arrSize];
		userAcnt = user.getAcntNum();

		strcpy(checkAcnt, acntNum.c_str());

		string myBank = user.getBank();

		if (checkBank(myBank, bank) && checkAcntNum(checkAcnt, userAcnt, arrSize)) {
			int oMoney = atoi(money.c_str()) + user.getBalance();

			user.setBalance(oMoney);
		}

		outfile << user.getName() << " ";
		outfile << nameSize << " ";
		outfile << user.getBank() << " ";

		int* account = new int[16];
		account = user.getAcntNum();

		switch (nameSize) {
		case 7:
		case 3:
			for (int i = 0; i < 14; i++) {
				outfile << account[i];
			}
			break;
		case 5:
		case 8:
			for (int i = 0; i < 13; i++) {
				outfile << account[i];
			}
			break;
		default:
			for (int i = 0; i < 12; i++) {
				outfile << account[i];
			}
			break;
		}
		outfile << " ";

		outfile << user.getPwd() << " ";
		outfile << user.getBalance() << '\\' << '\n';
	}

	infile.close();
	outfile.close();
}

void Deposit::callDeposit() {
	deposit();
	changeData();
}

/*void Deposit::initUserName(char* buf) {
	char name[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		name[i] = buf[i];
	}
	string userName;

	for (int i = 0; i < 3; i++) {
		userName += name[i];
	}

	user.setName(userName);
}

void Deposit::initUserBank(char* buf, int size) {
	char* name = new char[size];
	for (int i = 0; i < size; i++) {
		name[i] = buf[6 + i];
	}
	string bankName;
	for (int i = 0; i < size; i++) {
		bankName += name[i];
	}

	user.setBank(bankName);
}

void Deposit::initUserAcntNum(char* buf, int size) {
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

void Deposit::initUserPwd(char* buf, int size) {
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

void Deposit::initUserBalance(char* buf, int size) {
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

bool Deposit::checkBank(string a, string b) {
	if (a == b)
		return true;
	else
		return false;
}

bool Deposit::checkAcntNum(char* a, int* b, int size) {
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

void Deposit::changeData() {
	ifstream infile;
	infile.open("user/temp.txt", ios::in);
	ofstream outfile;
	outfile.open("user/user.txt", ios::out);

	char buffer[1024];

	while (!infile.eof()) {
		infile.getline(buffer, 1024);
		if (buffer[0] == '\0') {
			break;
		}
		outfile << buffer << '\n';
	}
	outfile.close();
	infile.close();

	outfile.open("user/temp.txt", ios::out);
	outfile.close();
}*/

Deposit::~Deposit() {
}