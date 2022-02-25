#include <iostream>
#include <vector>
#include <fstream>

#ifndef USER_H
#define USER_H

#include "LibraryCard.h"

class User {
public:
	string username;
	LibraryCard libraryCard;
	vector<Book> checkedOutBooks;

	int lastCreatedCardId;

	User() {
		LibraryCard card;
		vector<Book> books;
		username = "default-user";
		libraryCard = card;
		checkedOutBooks = books;
		lastCreatedCardId = card.id;
		// write created user to user log
		// username <LibraryCard>
		ofstream ofs;
		ofs.open("./action-log.txt", ios::app);
		ofs << "User created: " << toString() << endl;
	}

	User(string name) {
		LibraryCard card;
		vector<Book> books;
		username = name;
		libraryCard = card;
		checkedOutBooks = books;
		ofstream ofs;
		ofs.open("./action-log.txt", ios::app);
		ofs << "User created: " << toString() << endl;
	}

	void logAction(ofstream& ofs) {
		ofs.open("./action-log.txt", ios::app);
		ofs << "User created: " << toString() << endl;
	}

	// username <LibraryCard> or username <NULL>
	void printUser() {
		cout << username;
		libraryCard.printCard();
	}

	string toString() {
		return username + ", " + libraryCard.toString();
	}

};
#endif /* USER_H */
