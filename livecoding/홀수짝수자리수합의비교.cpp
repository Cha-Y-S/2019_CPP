#include <iostream>

using namespace std;

int main() {
	int t;
	unsigned int inNum;

	cin >> t;

	for (int i = 0; i < t; i++) {
		int arr[10];
		int j = 0;
		int jjak = 0;
		int hol = 0;
		int cnt = 0;

		cin >> inNum;

		while (inNum!=0) {
			arr[j] = inNum % 10;
			inNum = inNum / 10;
			j++;
			cnt++;
		}

		if (cnt % 2 == 0) {
			for (int k = 0; k < cnt; k++) {
				if (k % 2 == 0) jjak += arr[k];
				else hol += arr[k];
			}
		}

		else {
			for (int k = 0; k < cnt; k++) {
				if (k % 2 == 0) hol += arr[k];
				else jjak += arr[k];
			}
		}

		if (hol > jjak) cout << 1 << endl;
		else if (hol < jjak) cout << -1 << endl;
		else cout << 0 << endl;

	}
}