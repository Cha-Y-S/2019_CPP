#ifndef __LOOKUP_H__
#define __LOOKUP_H__
#include "atm.h"

class Lookup : public Atm {
	string acntNum;
	string bank;
	int pwd;
public:
	Lookup();
	~Lookup();
	void lookup();
	void printInfo(int size);
	/*void initUserName(char* buf);
	void initUserBank(char* buf, int size);
	void initUserAcntNum(char* buf, int size);
	void initUserPwd(char* buf, int size);
	void initUserBalance(char* buf, int size);
	bool checkBank(string a, string b);
	bool checkAcntNum(char* a, int* b, int size);
	bool checkPwd(int a, int b);*/
	
};

#endif