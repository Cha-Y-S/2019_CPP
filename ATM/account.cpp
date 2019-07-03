#include "account.h"
#include <ctime>

Account::Account() {
	accountNum = new int[16];
	pwd = 0;
	balance = 0;
	bank = "";
	name = "";
}

Account::Account(int value, string bank,string name) {
	accountNum = new int[16];
	pwd = value;
	balance = 0;
	this->name = name;
	this->bank = bank;
}

Account::~Account() {}

int* Account::getAcntNum() {
	return accountNum;
}

int Account::getPwd() {
	return pwd;
}

long Account::getBalance() {
	return balance;
}

string Account::getName() {
	return name;
}

string Account::getBank() {
	return bank;
}

void Account::setAcntNum() {
	srand((unsigned int)time(0));
	if (bank == "KOOKMIN") {
		accountNum[0] = 9;
		accountNum[1] = 3;
		accountNum[2] = 8;
		for (int i = 3; i < 14; i++) {
			accountNum[i] = rand() % 10;
		}
	}
	else if (bank == "WOORI") {
		accountNum[0] = 1;
		accountNum[1] = 4;
		accountNum[2] = 0;
		for (int i = 3; i < 13; i++) {
			accountNum[i] = rand() % 10;
		}
	}
	else if (bank == "SINHAN") {
		accountNum[0] = 1;
		accountNum[1] = 1;
		accountNum[2] = 0;
		for (int i = 3; i < 12; i++) {
			accountNum[i] = rand() % 10;
		}
	}
	else if (bank == "NONGHYUP") {
		accountNum[0] = 3;
		accountNum[1] = 5;
		accountNum[2] = 2;
		for (int i = 3; i < 13; i++) {
			accountNum[i] = rand() % 10;
		}
	}
	else {
		accountNum[0] = 0;
		accountNum[1] = 3;
		accountNum[2] = 3;
		for (int i = 3; i < 14; i++) {
			accountNum[i] = rand() % 10;
		}
	}
}

void Account::setAcntNum(int* num,int size) {
	int arrSize;
	switch (size) {
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

	for (int i = 0; i < arrSize; i++) {
		accountNum[i] = num[i];
	}
}

void Account::setPwd(int value) {
	this->pwd = value;
}

void Account::setBank(string bank) {
	this->bank = bank;
}

void Account::setName(string name) {
	this->name = name;
}

void Account::setBalance(int value) {
	this->balance = value;
}