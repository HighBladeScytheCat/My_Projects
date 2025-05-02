#include <iostream>

using namespace std;

int main() {

	int row = 20;

	for (int i = 0; i < row; i++) {

		for (int n = 0; n < row - i; n++) {
			if (i % 2 == 0) {
				cout << "/";
			} else {
				cout << "\\";
			}
		}

		for (int j = 0; j < i * 2 + 1; j++) {
			if (i % 2 == 0) {
				cout << "+";
			} else {
				cout << "*";
			}
		}

		for (int n = 0; n < row - i; n++) {
			if (i % 2 == 0) {
				cout << "/";
			} else {
				cout << "\\";
			}
		}

		cout << endl;
	}

	return 0;
}
