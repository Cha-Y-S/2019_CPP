#include "makeaccount.h"
#include "deposit.h"
#include "lookup.h"
#include "withdraw.h"
#include "remittance.h"

using namespace std;

int main() {
	char in;
	cout << "*==============MENU=============*" << endl;
	cout << "| - Deposit\t- MakeAccount\t|" << endl;
	cout << "| - Lookup\t- Withdraw\t|" << endl;
	cout << "| - Remittance\t\t\t|" << endl;
	cout << "*===============================*" << endl;


	do {
		cout << "Enter menu for using : ";
		cin >> in;
		switch (in) {
		case 'D':
		case 'd':
		{
			Deposit depo;
			depo.callDeposit();
			break;
		}
		case 'M':
		case 'm':
		{
			MakeAccount make;
			break;
		}
		case 'L':
		case 'l':
		{
			Lookup look;
			break;
		}
		case 'W':
		case 'w':
		{
			Withdraw with;
			with.callWithdraw();
			break;
		}
		case 'R':
		case 'r':
		{
			Remittance remit;
			break;
		}
		}
	} while ((in != 'q')&&(in != 'Q'));
	return 0;
}