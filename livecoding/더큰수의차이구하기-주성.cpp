#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream input;
	input.open("test.txt");
	int t, t1, t2;
	input >> t;
	for (int i = 0; i < t; i++) {
		input >> t1;
		int a = 0;
		int b = 0;
		int c = 0;
		for (int j = 0; j < t1; j++) {
			input >> c;
			if (b == 0) {
				b = c;
			}
			else if (a == 0) {
				a = c;
			}
			else if (c > b) {
				a = b;
				b = c;
			}
			else if (c<b&&c>a) {
				a = c;
			}
		}
		cout << a << " " << b << endl;
		cout << b - a << endl;
	}
}