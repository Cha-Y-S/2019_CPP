#ifndef __MAKEACCOUNT_H__
#define __MAKEACCOUNT_H__
#include "account.h"
#include <fstream>

class MakeAccount {
private:
	Account user;
public:
	MakeAccount();
	~MakeAccount();
	void upBank();
	void upAccountNum();
	void upPassword();
	void upAccountBalance();
	void upName();
	void upBankUniqueNumber();
	void upUserData();
};

#endif