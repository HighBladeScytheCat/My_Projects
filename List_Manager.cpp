#include <iostream>
#include <cstring>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

void Spacing();
void Menu();
void Add();
void Line();
void Update();
void Sort();
void Remove();

vector<string> list;

void Spacing() {
	for (int i = 0; i <= 2; i++) {
		cout << "\n";
	}
}

void Line() {
	cout << "|";
	for (int i = 0; i < 20; i++) {
				cout << "-";
	}
	cout << "|" << endl;
}

void Add() {
	string text;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "What do you want to add?\nText: ";
	getline(cin, text);


	list.push_back(text);
	cout << "\nAdded \"" << text << "\" to the list.\n";
	Spacing();

	char choice;

	while (true) {
		cout << "Do you want to add text again? (y or n): ";
		cin >> choice;

		switch (choice) {
		case 'y' :
			Spacing();
			Add();
			break;
		case 'n' :
			Spacing();
			Menu();
			break;
		default:
			cout << "\nInvalid Choice!";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			Spacing();
			Menu();
			break;
		}
	}
}

void Remove() {


	if (list.empty()) {
		cout << "List is Empty.";
		Spacing();
		Menu();
		return;
	}

	while (true) {

		Line();

		cout << "|Current List:\n";

		int index = 1;

		for_each(list.begin(), list.end(), [&](const string& item) {
			cout << "|(" << index++ << ") - " << item << endl;
		});

		Line();

		int input_remove;
		cout << "Enter a number of the item you want to remove: ";


		cin >> input_remove;

		if (cin.fail() || input_remove < 1 || input_remove > list.size()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			Spacing();
			cout << "Invalid input!";
			Spacing();
			continue;
		}

		list.erase(list.begin() + (input_remove - 1));


		char choice;

		if (list.empty()) {
			Spacing();
			cout << "List is empty.";
			Spacing();
			Menu();
		}

		cout << "Do you want to remove another item?: ";

		cin >> choice;

		switch (choice) {
		case 'y':
			Spacing();
			Remove();
			break;
		case 'n':
			Spacing();
			Menu();
			return;
		default:
			cout << "\nEnter a valid answer! \n";

		}
	}


}

void Update() {

	Spacing();

	if (list.empty()) {
			cout << "List is empty";
			Spacing();
			Menu();
		}

	while (true) {

		int input_update;
		string old;
		string updated_text;
		char again;

		Line();

		for (int i = 0; i < list.size(); i++) {
				cout << "|(" << i + 1 << ") - " << list[i] << endl;
			}

			Line();

			cout << "Enter a number of item you want to update: ";

			cin >> input_update;

			old = list[input_update - 1];

			if (cin.fail() || input_update < 1 || input_update > list.size()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				Spacing();
				cout << "Invalid input!";
				Spacing();
				continue;
			}

			cin.ignore();

			cout << "Updated text: ";

			getline(cin, updated_text);

			list[input_update - 1] = updated_text;

			cout << "Changed \"" << old << "\" to \"" << list[input_update - 1] << "\"\n";

			cout << "Do you want to update again? (y or n): ";

			cin >> again;

			switch (again) {
			case 'y':
				Spacing();
				Update();
				break;
			case 'n':
				Spacing();
				Menu();
				return;
			default:
				cout << "\nEnter a valid answer!\n";
			}
	}

}

void Sort() {
	char input_sort;

	if (list.empty()) {
		Spacing();
		cout << "List is empty.";
		Spacing();
		Menu();
		return;
	}

	while (true) {

		cout << "|Do you want to sort in Ascending or Descending order?\n";
		cout << "|{Ascending for A, Descending for D)\n";
		cout << "|Arrangement: ";

		cin >> input_sort;

		switch (input_sort) {
		case 'A':
		case 'a':
			sort(list.begin(), list.end());
			Spacing();
			cout << "Successfully sorted to Ascending order.";
			Spacing();
			Menu();
			return;
		case 'D':
		case 'd':
			sort(list.rbegin(), list.rend());
			Spacing();
			cout << "Successfully sorted to Descending order.";
			Spacing();
			Menu();
			return;
		default:
			Spacing();
			cout << "Invalid input!";
			Spacing();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
	}

}

void Menu() {
	int input;
	int index = 1;

	Line();

	for_each(list.begin(), list.end(), [&](const string& item) {
		cout << "|" << "(" << index++ << ") - " << item << endl;
	});

	Line();

	while (true) {


		cout << "[1] - Add List\n";
		cout << "[2] - Remove List\n";
		cout << "[3] - Update List\n";
		cout << "[4] - Sort List\n";
		cout << "Command: ";

		cin >> input;

		if (cin.fail() || input < 0 || input > 4) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Number. Please enter a valid number.";
			Spacing();
			continue;
		}

		switch (input) {
			case 1:
				Spacing();
				Add();
				break;
			case 2:
				Spacing();
				Remove();
				break;
			case 3:
				Spacing();
				Update();
				break;
			case 4:
				Spacing();
				Sort();
				break;
			default:
				cout << "Invalid Number";
				Spacing();
				Menu();
		}
	}

}


int main() {
	for (int i = 0; i <= 2; i++) {
		if (i == 1) {
			cout << "|------[[List]]------|\n|----By: TheCobra----|\n";
		} else {
			cout << "|====================|\n";
		}
	}
	Menu();
    return 0;
}
