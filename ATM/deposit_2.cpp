#include <iostream>
#include <fstream>
#include "deposit.h"

using namespace std;

Deposit::Deposit() {
	cout << "Enter bank name : ";
	cin >> bank;

	cout << "Enter your Account Number : ";
	cin >> acntNum;
}

void Deposit::findUser() {
	ifstream infile;
	ofstream outfile;
	infile.open("user/user.txt", ios::in);
	outfile.open("user/temp.txt", ios::out);


	int nameSize;

	while (!infile.eof()) {
		char buffer[1024];
		bool check = false;
		infile.getline(buffer, 1024);
		nameSize = buffer[4]-'0';
		//cout << "nameSize : " << nameSize << endl;
		if (buffer[0] == '\0')
			break;
		char* bankName = new char[nameSize];
		memset(bankName, 0, sizeof(bankName));
		int length = bank.length();
		//cout << "length : " << length << endl;
		char* myBank = new char[length];
		memset(myBank, 0, sizeof(myBank));
		

		for (int i = 0; i < nameSize; i++) {
			bankName[i] = buffer[6 + i];
		}
		bankName[nameSize] = '\0';

		for (int i = 0; i < length; i++) {
			myBank[i] = bank[i];
		}
		myBank[length] = '\0';
		
		if (strcmp(myBank, bankName) == 0) {
			char* acnt;
			
			if (nameSize == 7) {	// ±¹¹Î
				acnt = new char[14];
				for (int i = 0; i < 14; i++) {
					acnt[i] = buffer[i + 14];
				}
				for (int i = 0; i < 14; i++) {
					if (acnt[i] == acntNum[i]) {
						check = true;
						continue;
					}
					else {
						check = false;
						break;
					}
				}
				if (check == true) {
					char* myMoney = new char[20];
					for (int i = 0; buffer[34 + i] != '\\'; i++) {
						myMoney[i] = buffer[34 + i];
						if (buffer[34 + i + 1] == '\\')
							myMoney[i + 1] = '\\';
					}
					string mMoney = myMoney;
					cout << "Enter Deposit Money : ";

					cin >> money;
					int oMoney = atoi(money.c_str())+atoi(mMoney.c_str());
					cout << "output money : " << oMoney << endl;
					for (int i = 0; i < 34; i++) {
						outfile << buffer[i];
					}
					outfile << oMoney;

					outfile << '\\';

					outfile << '\n';
				}
			}

			else if (nameSize == 5) { //¿ì¸®
				acnt = new char[13];
				for (int i = 0; i < 13; i++) {
					acnt[i] = buffer[i + 12];
				}
				for (int i = 0; i < 13; i++) {
					if (acnt[i] == acntNum[i]) {
						check = true;
						continue;
					}
					else {
						check = false;
						break;
					}
				}
			}

			else if (nameSize == 6) { //½ÅÇÑ
				acnt = new char[12];
				for (int i = 0; i < 12; i++) {
					acnt[i] = buffer[i + 13];
				}
				for (int i = 0; i < 12; i++) {
					if (acnt[i] == acntNum[i]) {
						check = true;
						continue;
					}
					else {
						check = false;
						break;
					}
				}
			}

			else if (nameSize == 8) { //³óÇù
				acnt = new char[13];
				for (int i = 0; i < 13; i++) {
					acnt[i] = buffer[i + 15];
				}
				for (int i = 0; i < 13; i++) {
					if (acnt[i] == acntNum[i]) {
						check = true;
						continue;
					}
					else {
						check = false;
						break;
					}
				}
			}

			else { //±â¾÷
				acnt = new char[14];
				for (int i = 0; i < 14; i++) {
					acnt[i] = buffer[i + 10];
				}
				for (int i = 0; i < 14; i++) {
					if (acnt[i] == acntNum[i]) {
						check = true;
						continue;
					}
					else {
						check = false;
						break;
					}
				}
				
			}
			if (check == false) {
				outfile << buffer + '\n';
				break;
			}
		}
		else {
			outfile << buffer + '\n';
			continue;
		}
			
	}
}

Deposit::~Deposit() {
	findUser();
}