#ifndef __WITHDRAW_H__
#define __WITHDRAW_H__
#include "atm.h"

class Withdraw : public Atm {
private:
	string acntNum;
	string bank;
	string money;
	int pwd;
public:
	Withdraw();
	Withdraw(string uBank, string uAcntNum);
	~Withdraw();
	void withdraw();
	string send();
	void callWithdraw();
};

#endif