#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#ifndef USER_H
#define USER_H

#include "LibraryCard.h"
#include "Book.h"

class User {
private:
	// String   | int| int             | vector<Book>
	// Username | id | # of checkedOut | List of checked out (3 at most!)
	// --------- ---- ----------------- --------------------------------
	// gnaare   | 1  | 3               | [Book1, Book2, Book3]
	// root     | 2  | 1               | [Book1]
	void logAction(ofstream& ofs, LibraryCard card) {
		ofs.open("./library-log.txt", ios::app);
		string s = username + " | " + to_string(card.id) + " | " + to_string(card.booksCheckedOut) + " | ";
		if (!checkedOutBooks.empty()) {
			for (int i=0; i < checkedOutBooks.size(); i++) {
				s += "[" + checkedOutBooks[i].title + ", ";
			}
			s += "]";
		}
		ofs << s << endl;
		ofs.close();
	}
public:
	string username;
	LibraryCard libraryCard;
	vector<Book> checkedOutBooks;

	int lastCreatedCardId;

	User() {
		ofstream ofs;
		LibraryCard card;
		vector<Book> books;
		username = "default-user";
		libraryCard = card;
		checkedOutBooks = books;
		lastCreatedCardId = card.id;
//		logAction(ofs, libraryCard);
	}

	User(string name) {
		ofstream ofs;
		LibraryCard card;
		vector<Book> books;
		username = name;
		libraryCard = card;
		checkedOutBooks = books;
//		logAction(ofs, libraryCard);
	}

	// username <LibraryCard> or username <NULL>
	void printUser() {
		cout << username;
		libraryCard.printCard();
	}

	string toString() {
		return username + " | " + libraryCard.toString();
	}

};
#endif /* USER_H */