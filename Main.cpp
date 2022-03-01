#include <iostream>
#include "Librarian.h"

void pollForAction(string username);

int main() {

	vector<string> bookDirs;
	bookDirs.push_back("JK-Rowling");
	bookDirs.push_back("Brian-Jacques");
	bookDirs.push_back("Katherine-Neville");

	Librarian lib(bookDirs, "./users.txt");

	cout << "Library" << endl;

	for (auto pair : lib.library) {
		cout << pair.first << ": " << endl;
		for (auto book : pair.second) {
			book.printBook();
		}
		cout << endl;
	}

	// Librarian will keep track of book operations and checking users
	// library cards to allow them to browse the library

	cout << "Welcome to the Library!" << endl;
	cout << "Do you have a library card? Enter 'Yes' or 'No'" << endl;
	string userChoice;

	int primaryKey = 1;

	// Library Loop
	do {
		cin >> userChoice;
		lower(userChoice);

		string username;

		if (userChoice == "yes") {
			cout << "Enter username associated with your library card: " << endl;
			cin >> username;

			if (!lib.doesUserExist(username)) {
				cout << "Woops! That username doesn't exist. Come back later!" << endl;
				break;
			}

			pollForAction(username);

		} else if (userChoice == "no") {
			cout << "Process initiated: Creating New User with Library Card" << endl;
			cout << "Enter your username: " << endl;
			cin >> username;

			// before writing that username to "user-log.txt"
			// check if the username already exists
			string uniqueName = lib.pollForUniqueName(username);

			lib.addUserToLog(uniqueName);
			pollForAction(uniqueName);

			break;
		}

		primaryKey++;

	} while (userChoice != "quit");

	return 0;
}

void pollForAction(string username) {
	string action = "";
	string actions[4] = {
			"Search by title",
			"Search by author",
			"View your checked out books",
			"Return a book",
	};
	int actionListSize = sizeof(actions) / sizeof(actions[0]);
	cout << "Greetings " + username + "! ";
	cout << "What brings you to the library today?" << endl;
	for (int i=0; i < actionListSize; i++) {
		cout << to_string(i+1) + ". " + actions[i] << endl;
	}
	cout << "Type 'quit' to leave" << endl;
	cin >> action;
	if (action == "quit") {
		cout << "Thanks for stopping by!" << endl;
		return;
	}
}