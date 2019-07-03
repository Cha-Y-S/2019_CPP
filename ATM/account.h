#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include <iostream>
#include <string>

using namespace std;

class Account {
private:
	int *accountNum;
	int pwd;
	int balance;
	string name;
	string bank;
public:
	Account();
	Account(int value,string bank,string name);
	~Account();
	int* getAcntNum();
	int getPwd();
	long getBalance();
	string getName();
	string getBank();
	void setAcntNum();
	void setAcntNum(int* num,int size);
	void setPwd(int value);
	void setBank(string bank);
	void setName(string name);
	void setBalance(int value);
};

#endif