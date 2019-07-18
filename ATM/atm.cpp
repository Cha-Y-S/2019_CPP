#include "atm.h"

using namespace std;

Atm::Atm() {

}

Atm::~Atm() {

}

void Atm::initUserName(char* buf) {
	string userName;
	for (int i = 0; i < 3; i++) {
		userName += buf[i];
	}
	user.setName(userName);
}

void Atm::initUserBank(char* buf, int size) {
	string bankName;
	for (int i = 0; i < size; i++) {
		bankName += buf[6 + i];
	}
	user.setBank(bankName);
}

void Atm::initUserAcntNum(char* buf, int size){
	int *num;
	int arrSize;
	switch(size) {
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
	user.setAcntNum(num, size);
}

void Atm::initUserPwd(char* buf, int size) {
	char pwd[4] = { 0 };
	switch(size) {
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
	user.setPwd(myPwd);
}

void::Atm::initUserBalance(char* buf, int size) {
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

bool Atm::checkBank(string a, string b) {
	if (a == b)
		return true;
	else
		return false;
}

bool Atm::checkAcntNum(char* a, int* b, int size) {
	bool result = false;
	for (int i = 0; i < size; i++) {
		if (a[i] - '0' == b[i])
			result = true;
		else {
			result = false;
			break;
		}
	}
	return result;
}

bool Atm::checkPwd(int a, int b) {
	if (a == b)
		return true;
	else
		return false;
}

void Atm::changeData() {
	ifstream infile;
	infile.open("user/temp.txt", ios::in);
	ofstream outfile;
	outfile.open("user/user.txt", ios::out);

	char buffer[1024];

	while (!infile.eof()) {
		infile.getline(buffer, 1024);
		if (buffer[0] == '\0')
			break;
		outfile << buffer << '\n';
	}
	outfile.close();
	infile.close();

	outfile.open("user/temp.txt", ios::out);
	outfile.close();	// temp.txt ³»¿ëÀ» ¾ø¾Ú
}