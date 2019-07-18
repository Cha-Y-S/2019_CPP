#ifndef __ATM_H__
#define __ATM_H__
#include <fstream>
#include "account.h"

class Atm {
protected:
	Account user;
public:
	Atm();
	~Atm();
	void initUserName(char* buf);
	void initUserBank(char* buf, int size);
	void initUserAcntNum(char* buf, int size);
	void initUserPwd(char* buf, int size);
	void initUserBalance(char* buf, int size);
	bool checkBank(string a, string b);
	bool checkAcntNum(char* a, int* b, int size);
	bool checkPwd(int a, int b);
	void changeData();
};

#endif