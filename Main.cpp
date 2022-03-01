#include <iostream>
#include "Librarian.h"

void pollForAction(Librarian& lib);

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
			getline(std::cin >> std::ws, username);

			if (!lib.doesUserExist(username)) {
				cout << "Woops! That username doesn't exist. Come back later!" << endl;
				break;
			}
			cout << "Greetings " + username + "! ";
			pollForAction(lib);

		} else if (userChoice == "no") {
			cout << "Process initiated: Creating New User with Library Card" << endl;
			cout << "Enter your username: " << endl;
			getline(std::cin >> std::ws, username);

			// before writing that username to "user-log.txt"
			// check if the username already exists
			string uniqueName = lib.pollForUniqueName(username);

			lib.addUserToLog(uniqueName);
			cout << "Greetings " + username + "! ";
			pollForAction(lib);

			break;
		}

		primaryKey++;

	} while (userChoice != "quit");

	return 0;
}

void pollForAction(Librarian& lib) {
	string action = "";
	string actions[5] = {
			"Search by title",
			"Search by author",
			"Checkout a book",
			"View your checked out books",
			"Return a book",
	};

	int actionListSize = sizeof(actions) / sizeof(actions[0]);

	cout << "What brings you to the library today?" << endl;

	for (int i=0; i < actionListSize; i++) {
		cout << to_string(i+1) + ". " + actions[i] << endl;
	}

	cout << "Type 'quit' to leave" << endl;

	cin >> action;

	if (action == "1") {
		// todo: fuzzy search by title

	} else if (action == "2") {
		// search by author
		string author = "";
		cout << "Enter author: " << endl;
		getline(std::cin >> std::ws, author);
		vector<Book> booksByAuthor = lib.searchByAuthor(author);
		for (auto b : booksByAuthor) {
			cout << b.title << endl;
		}
		cout << "\nDisplayed " << booksByAuthor.size() << " results by " << author << endl;
		cout << endl;
		// poll for action again (todo: pass action by reference so it gets updated when recursive calls resolve)
		pollForAction(lib);

		if (action == "quit") return;

	} else if (action == "3") {
		// Checkout a book given a book title and author (or in todo unique book ID)

	} else if (action == "4") {
		// Display a users checked out books

	} else if (action == "5") {
		// Return a book given a title and author

	} else if (action == "quit") {
		cout << "Thanks for stopping by!" << endl;
		return;
	} else {
		cout << "Invalid choice! Select 1-4 or type 'quit'" << endl;
	}
}