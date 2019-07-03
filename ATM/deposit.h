#ifndef __DEPOSIT_H__
#define __DEPOSIT_H__
#include "account.h"

class Deposit {
private:
	Account user;
	string money;
	string bank;
	string acntNum;
public:
	Deposit();
	~Deposit();
	void findUser();
	void initUserName(char* buf);
	void initUserBank(char* buf, int size);
	void initUserAcntNum(char* buf, int size);
	void initUserPwd(char* buf,int size);
	void initUserBalance(char* buf, int size);
	bool checkBank(string a, string b);
	bool checkAcntNum(char* a, int* b,int size);
	void changeData();

	// 은행선택
	// 계좌번호(카드 or 통장 넣으면 안물어봄)
	// 비밀번호 x
	// 돈
};


#endif