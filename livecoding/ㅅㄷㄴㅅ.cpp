#include <iostream>
using namespace std;

int lengthOfIntervalIntersection(int a, int b, int c, int d);

int main(void)
{
	int t;
	int a, b, c, d;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> a >> b >> c >> d;
		cout << lengthOfIntervalIntersection(a, b, c, d) << endl;
	}
	return 0;
}

int lengthOfIntervalIntersection(int a, int b, int c, int d) {
	int front;
	int end;
	if (a <= c) {
		if (b < c) {
			return -1;
		}
		end = b;
		for (int i = a; i <= b; i++) {
			if (i == c) {
				front = i;
			}
			else if (i == d) {
				end = i;
			}
		}
	}
	else if (a > c) {
		if (d < a) {
			return -1;
		}

		end = d;
		for (int j = c; j <= d; j++) {
			if (j == a) {
				front = a;
			}
			else if (j == b) {
				end = j;
			}
		}
	}
	return end - front;
}
