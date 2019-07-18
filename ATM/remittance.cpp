#include "remittance.h"

using namespace std;

Remittance::Remittance() {
	cout << "Enter your bank name : ";
	cin >> uBank;
	cout << "Enter your account name : ";
	cin >> uAcntNum;
	sender = new Withdraw(uBank, uAcntNum);
}

Remittance::~Remittance() {
	remittance();
}

void Remittance::remittance() {
	string money = sender->send();
	changeData();
	if (money == "")
		return;
	else {
		cout << "Enter recipient bank name : ";
		cin >> rBank;
		cout << "Enter recipient account number :";
		cin >> rAcntNum;
		recipient = new Deposit(rBank,rAcntNum,money);
		recipient->recieve();
		changeData();
	}
}
/*
void Remittance::initRecipientName(char* buf) {
	string name;
	for (int i = 0; i < 3; i++)
		name += buf[i];
	recipient.setName(name);
}

void Remittance::initRecipientAcntNum(char* buf,int size) {
	int *num;
	int arrSize;
	switch (size) {
	case 7:
		arrSize = 14;
		num = new int[arrSize];
		for (int i = 0; i < arrSize; i++)
			num[i] = buf[14 + i] - '0';
		break;
	case 5:
		arrSize = 13;
		num = new int[arrSize];
		for (int i = 0; i < arrSize; i++)
			num[i] = buf[12 + i] - '0';
		break;
	case 6:
		arrSize = 12;
		num = new int[arrSize];
		for (int i = 0; i < arrSize; i++)
			num[i] = buf[13 + i] - '0';
		break;
	case 8:
		arrSize = 13;
		num = new int[arrSize];
		for (int i = 0; i < arrSize; i++)
			num[i] = buf[15 + i] - '0';
		break;
	default:
		arrSize = 14;
		num = new int[arrSize];
		for (int i = 0; i < arrSize; i++)
			num[i] = buf[10 + i] - '0';
		break;
	}
	recipient.setAcntNum(num, size);
}

void Remittance::initRecipientBalance(char* buf,int size) {
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
	recipient.setBalance(balance);
}

void Remittance::initRecipientBank(char* buf, int size) {
	string bankName;
	for (int i = 0; i < size; i++) {
		bankName += buf[6 + i];
	}
	recipient.setBank(bankName);
}

void Remittance::initRecipientPwd(char* buf,int size) {
	char pwd[4] = { 0 };
	switch (size) {
	case 7:
	case 8:
		for (int i = 0; i < 4; i++)
			pwd[i] = buf[29 + i];
		break;
	case 5:
	case 6:
		for (int i = 0; i < 4; i++)
			pwd[i] = buf[26 + i];
		break;
	default:
		for (int i = 0; i < 4; i++)
			pwd[i] = buf[25 + i];
		break;
	}
	int myPwd = atoi(pwd);
	recipient.setPwd(myPwd);
}

void Remittance::checkRecipientBank() {

}

void Remittance::checkRecipientAcnt() {

}*/