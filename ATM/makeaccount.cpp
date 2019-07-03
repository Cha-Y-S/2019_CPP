#include "makeaccount.h"

using namespace std;

MakeAccount::MakeAccount() {
	string bank;
	string name;
	int pwd;
	cout << "±¹¹Î : KOOKMIN" << endl;
	cout << "¿ì¸® : WOORI" << endl;
	cout << "½ÅÇÑ : SINHAN" << endl;
	cout << "³óÇù : NONGHYUP" << endl;
	cout << "±â¾÷ : IBK" << endl;
	cout << "Enter Bank : ";
	cin >> bank;
	cout << "Enter Name : ";
	cin >> name;
	cout << "Enter PassWord : ";
	cin >> pwd;
	user.setName(name);
	user.setBank(bank);
	user.setAcntNum();
	user.setPwd(pwd);
}

MakeAccount::~MakeAccount() {
	upUserData();
}

void MakeAccount::upBank() {
	ofstream outfile;

	outfile.open("user/user.txt", ios::app);

	string bank = user.getBank();

	outfile << bank;

	outfile << " ";

	outfile.close();
}

void MakeAccount::upName() {
	ofstream outfile;

	outfile.open("user/user.txt", ios::app);

	string name = user.getName();

	outfile << name;

	outfile << " ";

	outfile.close();
}

void MakeAccount::upAccountNum() {
	ofstream outfile;

	outfile.open("user/user.txt", ios::app);

	string bank = user.getBank();
	int* account = new int[16];
	account = user.getAcntNum();

	if (bank == "KOOKMIN") {
		for (int i = 0; i < 14; i++) {
			outfile << account[i];
		}
	}

	else if (bank == "WOORI") {
		for (int i = 0; i < 13; i++) {
			outfile << account[i];
		}
	}

	else if (bank == "SINHAN") {
		for (int i = 0; i < 12; i++) {
			outfile << account[i];
		}
	}

	else if (bank == "NONGHYUP") {
		for (int i = 0; i < 13; i++) {
			outfile << account[i];
		}
	}

	else {
		for (int i = 0; i < 14; i++) {
			outfile << account[i];
		}
	}
	
	outfile << " ";

	outfile.close();
}

void MakeAccount::upPassword() {
	ofstream outfile;

	outfile.open("user/user.txt", ios::app);

	outfile << user.getPwd();

	outfile << " ";

	outfile.close();
}

void MakeAccount::upAccountBalance() {
	ofstream outfile;

	outfile.open("user/user.txt", ios::app);

	outfile << user.getBalance();

	outfile << "\\\n";

	outfile.close();
}

void MakeAccount::upBankUniqueNumber() {
	ofstream outfile;

	outfile.open("user/user.txt", ios::app);

	string bank = user.getBank();
	
	int uNum;

	if (bank == "KOOKMIN") {
		uNum = 7;
	}
	else if (bank == "WOORI") {
		uNum = 5;
	}
	else if (bank == "SINHAN") {
		uNum = 6;
	}
	else if (bank == "NONGHYUP") {
		uNum = 8;
	}
	else {
		uNum = 3;
	}

	outfile << uNum;

	outfile << " ";

	outfile.close();
}

void MakeAccount::upUserData() {
	upName();
	upBankUniqueNumber();
	upBank();
	upAccountNum();
	upPassword();
	upAccountBalance();
}