#ifndef __REMITTANCE_H__
#define __REMITTANCE_H__
#include "atm.h"
#include "deposit.h"
#include "withdraw.h"

class Remittance : public Atm {
private:
	Deposit *recipient;
	Withdraw *sender;
	//Account recipient;
	string uAcntNum;
	string uBank;
	int money;
	string rAcntNum;
	string rBank;
	int pwd;
public:
	Remittance();
	~Remittance();
	void remittance();
	/*void initRecipientName(char* buf);
	void initRecipientAcntNum(char* buf,int size);
	void initRecipientBank(char* buf,int size);
	void initRecipientPwd(char* buf,int size);
	void initRecipientBalance(char* buf,int size);
	void checkRecipientBank();
	void checkRecipientAcnt();*/
};

#endif