#include "withdraw.h"
#pragma warning(disable:4996)

using namespace std;

Withdraw::Withdraw() {
	cout << "Enter your Bank Name : ";
	cin >> bank;
	cout << "Enter your Account Number : ";
	cin >> acntNum;
}

Withdraw::Withdraw(string uBank, string uAcntNum) {
	bank = uBank;
	acntNum = uAcntNum;
}

Withdraw::~Withdraw() {
}

void Withdraw::withdraw() {
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
		int userPwd = user.getPwd();
		userAcnt = user.getAcntNum();

		strcpy(checkAcnt, acntNum.c_str());

		string myBank = user.getBank();

		if (checkBank(myBank, bank) && checkAcntNum(checkAcnt, userAcnt, arrSize)) {
			cout << "Enter your password : ";
			cin >> pwd;
			if (checkPwd(userPwd, pwd)) {
				cout << "Enter withdraw money : ";
				cin >> money;
				int wMoney = atoi(money.c_str());
				if (user.getBalance() < wMoney) {
					cout << "Not enough money on your account" << endl;
				}
				else {
					int oMoney = user.getBalance() - wMoney;
					user.setBalance(oMoney);
				}
			}
			else {
				cout << "Not correct password" << endl;
			}
			/*int oMoney = atoi(money.c_str()) + user.getBalance();

			user.setBalance(oMoney);*/
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

string Withdraw::send() {
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
		int userPwd = user.getPwd();
		userAcnt = user.getAcntNum();

		strcpy(checkAcnt, acntNum.c_str());

		string myBank = user.getBank();

		if (checkBank(myBank, bank) && checkAcntNum(checkAcnt, userAcnt, arrSize)) {
			cout << "Enter your password : ";
			cin >> pwd;
			if (checkPwd(userPwd, pwd)) {
				cout << "Enter remittance money : ";
				cin >> money;
				int wMoney = atoi(money.c_str());
				if (user.getBalance() < wMoney) {
					cout << "Not enough money on your account" << endl;
					money = "";
				}
				else {
					int oMoney = user.getBalance() - wMoney;
					user.setBalance(oMoney);
				}
			}
			/*else {
				cout << "Not correct password" << endl;
			}
			int oMoney = atoi(money.c_str()) + user.getBalance();

			user.setBalance(oMoney);*/
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

	return money;
}

void Withdraw::callWithdraw() {
	withdraw();
	changeData();
}