#include "makeaccount.h"
#include "deposit.h"

using namespace std;

int main() {
	char in;
	cout << "*===========MENU===========*" << endl;
	cout << "| - Deposit   - MakeAccount|" << endl;
	cout << "*==========================*" << endl;
	cin >> in;

	switch (in) {
	case 'd':
	{
		Deposit depo;
		break;
	}
	case 'm':
	{
		MakeAccount make;
		break;
	}
	}
	return 0;
}